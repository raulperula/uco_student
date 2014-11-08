/**
 * @file    AlgoritmoD.java
 * @brief   Clase del cliente que implementa los metodos necesarios para
 *          conectarse con el servidor, reproducir, pausar el video enviado en
 *          streaming y finalizar desconectandose de la conexion.
 *
 * @author Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InterruptedIOException;
import java.io.OutputStreamWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.util.StringTokenizer;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

public class Cliente {

    /**
     * GUI.
     */

    JFrame f = new JFrame("Cliente");

    JButton setupButton = new JButton("Conectar");
    JButton playButton = new JButton("Play");
    JButton pauseButton = new JButton("Pause");
    JButton tearButton = new JButton("Teardown");

    JPanel mainPanel = new JPanel();
    JPanel infoPanel = new JPanel();
    JPanel buttonPanel = new JPanel();

    JLabel iconLabel = new JLabel();
    /**
     * Etiqueta para el host.
     */
    JLabel hostLabel = new JLabel("Servidor: ");
    /**
     * Añadir campo de texto para el hostname del servidor.
     */
    JTextField hostname = new JTextField("localhost");
    /**
     * Etiqueta para el puerto.
     */
    JLabel portLabel = new JLabel(" Puerto: ");
    /**
     * Añadir campo de texto para el puerto del servidor.
     */
    JTextField portnb = new JTextField("2000");
    /**
     * Etiqueta para el nombre del archivo.
     */
    JLabel vLabel = new JLabel(" Fichero: ");
    /**
     * Añadir campo de texto para el nombre del archivo.
     */
    JTextField vfile = new JTextField("video.Mjpeg");

    ImageIcon icon;
    JLabel countpkt = new JLabel("                ");

    /**
     * RTP variables.
     */
    DatagramPacket rcvdp; // Paquete UDP recibido desde el servidor
    DatagramSocket RTPsocket; // Socket usado para enviar y recibir paquetes UDP

    static int RTP_RCV_PORT = 25000; // Puerto por donde el cliente recibira los
    // paquetes RTP

    Timer timer; // Temporizador usado para recibir datos desde el socket UDP
    byte[] buf; // Bufer usado para almacenar datos recibidos desde el servidor

    static int countpk = 0; // Contador de paquetes

    /**
     * Variables RTSP. Estados RTSP.
     */
    final static int INIT = 0;
    final static int READY = 1;
    final static int PLAYING = 2;
    static int state; // Estado RTSP == INIT o READY o PLAYING
    Socket RTSPsocket; // Socket usado para enviar/recibir mensajes RTSP

    /**
     * Flujos de entrada y salida.
     */
    static BufferedReader RTSPBufferedReader;
    static BufferedWriter RTSPBufferedWriter;
    static String VideoFileName; // Fichreo de video para pedir al servidor
    int RTSPSeqNb = 0; // Numero de secuencia de los mensajes RTSP sin la sesion
    int RTSPid = 0; // ID de la sesion RTSP (dada por el servidor RTSP)

    final static String CRLF = "\n";

    /**
     * Variables para la interfaz.
     */
    static int setupstage = 0;
    static int sizem;
    static int tc = 1;
    static int dt = 1;

    /**
     * Constantes de video.
     */
    static int MJPEG_TYPE = 26; // Tipo de RTP para video MJPEG

    /**
     * Constructor.
     */
    public Cliente() {

        /**
         * Construccion de la GUI.
         */

        /**
         * Frame.
         */
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        /**
         * Informacion y configuracion.
         */

        /**
         * Añadir las etiquetas y los campos de texto.
         */
        infoPanel.add(hostLabel);
        infoPanel.add(hostname);
        infoPanel.add(portLabel);
        infoPanel.add(portnb);
        infoPanel.add(vLabel);
        infoPanel.add(vfile);
        infoPanel.add(countpkt);

        /**
         * Botones.
         */
        buttonPanel.setLayout(new GridLayout(1, 0));

        buttonPanel.add(setupButton);
        buttonPanel.add(playButton);
        buttonPanel.add(pauseButton);
        buttonPanel.add(tearButton);

        setupButton.addActionListener(new setupButtonListener());
        playButton.addActionListener(new playButtonListener());
        pauseButton.addActionListener(new pauseButtonListener());
        tearButton.addActionListener(new tearButtonListener());

        /**
         * Etiqueta de imagen mostrada.
         */
        iconLabel.setIcon(null);

        /**
         * Capa de salida del frame.
         */
        mainPanel.setLayout(null);
        mainPanel.add(infoPanel);
        mainPanel.add(iconLabel);
        mainPanel.add(buttonPanel);
        infoPanel.setBounds(-20, 10, 540, 20);
        iconLabel.setBounds(50, 10, 500, 400);
        buttonPanel.setBounds(20, 380, 450, 50);

        f.getContentPane().add(mainPanel, BorderLayout.CENTER);
        f.setSize(new Dimension(500, 500));
        f.setVisible(true);

        /**
         * Inicializacion del temporizados.
         */
        timer = new Timer(20, new timerListener());
        timer.setInitialDelay(0);
        timer.setCoalesce(true);

        /**
         * Almacenamiento de suficiente memoria para el bufer usado para recibir
         * datos desde el servidor.
         */
        buf = new byte[15000];
    }

    /**
     * Funcion principal.
     *
     * @param argv
     *            Lista de argumentos en linea de comandos.
     * @throws Exception
     */
    public static void main(String argv[]) throws Exception {
        /**
         * Creacion de un objeto Cliente.
         */
        Cliente cliente = new Cliente();

        /**
         * Obtener puerto RTSP del servidor y la direccion IP desde linea de
         * comandos.
         */
        int RTSP_server_port = Integer.parseInt(cliente.portnb.getText());
        String ServerHost = cliente.hostname.getText();
        InetAddress ServerIPAddr = InetAddress.getByName(ServerHost);

        /**
         * Obtener nombre de fichero de video.
         */
        VideoFileName = cliente.vfile.getText();

        /**
         * Establecer una conexion TCP con el servidor para intercambiar
         * mensajes RTSP.
         */
        cliente.RTSPsocket = new Socket(ServerIPAddr, RTSP_server_port);

        /**
         * Poner los flujos de entrada y salida.
         */
        RTSPBufferedReader = new BufferedReader(new InputStreamReader(
                cliente.RTSPsocket.getInputStream()));
        RTSPBufferedWriter = new BufferedWriter(new OutputStreamWriter(
                cliente.RTSPsocket.getOutputStream()));

        /**
         * Inicializar estado RTSP.
         */
        state = INIT;
    }

    /**
     * Funciones de los botones.
     */

    /**
     * Funcion para el boton Setup.
     */
    class setupButtonListener implements ActionListener {
        /*
         * (non-Javadoc)
         *
         * @see
         * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent
         * )
         */
        public void actionPerformed(ActionEvent e) {
            setupstage++;
            countpk = 0;

            if (state == INIT) {
                /**
                 * Inicializar un RTPsocket no bloqueante que sera usado para
                 * recibir los datos.
                 */
                try {
                    /**
                     * Construir un nuevo DatagramSocket para recibir los
                     * paquetes RTP desde el servidor, en el puerto
                     * RTP_RCV_PORT.
                     */
                    RTPsocket = new DatagramSocket(RTP_RCV_PORT);

                    /**
                     * Poner el valor de TimeOut a 5ms.
                     */
                    RTPsocket.setSoTimeout(5);
                } catch (SocketException se) {
                    System.out.println("Excepcion de socket: " + se);
                    System.exit(0);
                }

                /**
                 * Inicializar el numero de secuencia RTSP.
                 */
                RTSPSeqNb = 1;

                /**
                 * Enviar mensaje SETUP al servidor.
                 */
                send_RTSP_request("SETUP");

                /**
                 * Esperar la respuesta.
                 */
                if (parse_server_response() != 200)
                    System.out.println("Respuesta del Servidor Invalida");
                else {
                    /**
                     * Cambiar el estado RTSP e imprimir el nuevo estado.
                     */
                    state = READY;
                    System.out.println("Nuevo estado RTSP: READY");
                }
            }
        }
    }

    /**
     * Funcion para el boton Play.
     */
    class playButtonListener implements ActionListener {
        /*
         * (non-Javadoc)
         *
         * @see
         * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent
         * )
         */
        public void actionPerformed(ActionEvent e) {
            if (state == READY) {
                /**
                 * Incremento del numero de secuencia RTSP.
                 */
                RTSPSeqNb++;

                /**
                 * Enviar mensaje PLAY al servidor.
                 */
                send_RTSP_request("PLAY");

                /**
                 * Esperar la respuesta.
                 */
                if (parse_server_response() != 200)
                    System.out.println("Respuesta del Servidor Invalida");
                else {
                    /**
                     * Cambiar el estado RTSP e imprimir el nuevo estado.
                     */
                    state = PLAYING;
                    System.out.println("Nuevo estado RTSP: PLAYING");

                    /**
                     * Activar el temporizador.
                     */
                    timer.start();
                }
            }
        }
    }

    /**
     * Funcion del boton Pause.
     */
    class pauseButtonListener implements ActionListener {
        /*
         * (non-Javadoc)
         *
         * @see
         * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent
         * )
         */
        public void actionPerformed(ActionEvent e) {
            if (state == PLAYING) {
                /**
                 * Incrementar el numero de secuencia RTSP.
                 */
                RTSPSeqNb++;

                /**
                 * Enviar mensaje PAUSE al servidor.
                 */
                send_RTSP_request("PAUSE");

                /**
                 * Esperar la respuesta.
                 */
                if (parse_server_response() != 200)
                    System.out.println("Respuesta del Servidor Invalida");
                else {
                    /**
                     * Cambiar estado RTSP e imprimir el nuevo estado.
                     */
                    state = READY;
                    System.out.println("Nuevo estado RTSP: READY");

                    /**
                     * Parar el temporizador.
                     */
                    timer.stop();
                }
            }
        }
    }

    /**
     * Funcion del boton Teardown.
     */
    class tearButtonListener implements ActionListener {
        /*
         * (non-Javadoc)
         *
         * @see
         * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent
         * )
         */
        public void actionPerformed(ActionEvent e) {
            /**
             * Incrementar el numero de secuencia RTSP.
             */
            RTSPSeqNb++;

            /**
             * Enviar mensaje TEARDOWN al servidor.
             */
            send_RTSP_request("TEARDOWN");

            /**
             * Esperar la respuesta.
             */
            if (parse_server_response() != 200)
                System.out.println("Respuesta del Servidor Invalida");
            else {
                /**
                 * Cambiar estado RTSP e imprimir el nuevo estado.
                 */
                state = INIT;
                System.out.println("Nuevo estado RTSP: INIT");

                /**
                 * Parar el temporizador.
                 */
                timer.stop();

                /**
                 * Salir.
                 */
                System.exit(0);
            }
        }
    }

    /**
     * Funcion del temporizador.
     */
    class timerListener implements ActionListener {
        /*
         * (non-Javadoc)
         *
         * @see
         * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent
         * )
         */
        public void actionPerformed(ActionEvent e) {
            /**
             * Construir un DatagramPacket para recibir datos desde el socket
             * UDP.
             */
            rcvdp = new DatagramPacket(buf, buf.length);

            try {
                /**
                 * Recibir el DP desde el socket.
                 */
                RTPsocket.receive(rcvdp);

                /**
                 * Crear un objeto PaqueteRTP desde el DP.
                 */
                PaqueteRTP rtp_packet = new PaqueteRTP(rcvdp.getData(), rcvdp
                        .getLength());

                /**
                 * Imprimir el total de paquetes por segundo.
                 */
                sizem = sizem + rtp_packet.getLongCarga();
                dt = tc - rtp_packet.getTimestamp();
                tc = rtp_packet.getTimestamp();
                countpkt.setText(" " + Math.abs(sizem / tc) + "KB/s");

                /**
                 * Imprimir los campos de las cabeceras importantes del paquete
                 * RTP recibido.
                 */
                System.out
                        .println("Recibido paquete RTP con Numero Secuencia # "
                                + rtp_packet.getNumeroSecuencia()
                                + " TimeStamp " + rtp_packet.getTimestamp()
                                + " ms, de tipo " + rtp_packet.getTipoCarga());

                /**
                 * Imprimir la cabecera bitstream.
                 */
                rtp_packet.printheader();

                /**
                 * Obtener el bitstream desde el objeto PaqueteRTP.
                 */
                int payload_length = rtp_packet.getLongCarga();
                byte[] payload = new byte[payload_length];
                rtp_packet.getCarga(payload);

                /**
                 * Obtener una objeto imagen desde el bitstream.
                 */
                Toolkit toolkit = Toolkit.getDefaultToolkit();
                Image image = toolkit.createImage(payload, 0, payload_length);

                /**
                 * Mostrar la imagen como un objeto ImageIcon.
                 */
                icon = new ImageIcon(image);
                iconLabel.setIcon(icon);
            } catch (InterruptedIOException iioe) {
                // System.out.println("Nada que leer");
            } catch (IOException ioe) {
                System.out.println("Excepcion capturada: " + ioe);
            }
        }
    }

    /**
     * Parsear respuesta del servidor.
     *
     * @return Devuelve el codigo de respuesta.
     */
    private int parse_server_response() {
        int reply_code = 0;

        try {
            /**
             * Parsear estado de la linea y extraer el reply_code.
             */
            String StatusLine = RTSPBufferedReader.readLine();
            System.out.println("Cliente RTSP - Recibido desde el servidor:");
            System.out.println(StatusLine);

            StringTokenizer tokens = new StringTokenizer(StatusLine);
            tokens.nextToken(); // Saltar al siguiente RTSP
            reply_code = Integer.parseInt(tokens.nextToken());

            /**
             * Si el reply_code esta OK se obtiene e imprime las 2 siguiente
             * lineas.
             */
            if (reply_code == 200) {
                String SeqNumLine = RTSPBufferedReader.readLine();
                System.out.println(SeqNumLine);

                String SessionLine = RTSPBufferedReader.readLine();
                System.out.println(SessionLine);

                /**
                 * Si el estado == INIT obtiene el Id de Sesion desde la
                 * SessionLine.
                 */
                tokens = new StringTokenizer(SessionLine);
                tokens.nextToken(); // Saltar a la siguiente sesion
                RTSPid = Integer.parseInt(tokens.nextToken());
            }
        } catch (Exception ex) {
            System.out.println("Excepcion capturada: " + ex);
            System.exit(0);
        }

        return (reply_code);
    }

    /**
     * Enviar peticion RTSP.
     *
     * @param request_type
     *            Tipo de peticion.
     */
    private void send_RTSP_request(String request_type) {
        try {
            /**
             * Usar el RTSPBufferedWriter para escribir el socket RTSP. Escribir
             * la linea de peticion.
             */
            RTSPBufferedWriter.write(request_type + " " + VideoFileName
                    + " RTSP/1.0" + CRLF);
            /**
             * Escribir la linea CSeq.
             */
            RTSPBufferedWriter.write("CSeq: " + RTSPSeqNb + CRLF);

            /**
             * Comprobar si el request_type es igual a "SETUP" y en ese caso
             * escribir el Transport: linea de aviso al servidor del puerto
             * usado para recibir los paquetes RTP, RTP_RCV_PORT.
             */
            if ((new String(request_type)).compareTo("SETUP") == 0)
                RTSPBufferedWriter.write("Transport: RTP/UDP; client_port= "
                        + RTP_RCV_PORT + CRLF);
            else
                RTSPBufferedWriter.write("Session: " + RTSPid + "\n");

            RTSPBufferedWriter.flush();
        } catch (Exception ex) {
            System.out.println("Excepcion capturada: " + ex);
            System.exit(0);
        }
    }
}
