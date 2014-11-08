/**
 * @file    Servidor.java
 * @brief   Clase del servidor que implementa la ventana grafica junto con las
 *          acciones del envio del video a traves de streaming a un cliente.
 *
 * @author Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

import java.io.*;
import java.net.*;
import java.awt.*;
import java.util.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;

public class Servidor extends JFrame implements ActionListener {

    /**
     * Versión UID.
     */
    private static final long serialVersionUID = 1L;

    /**
     * Variables RTP.
     */
    DatagramSocket socketRTP; // Socket para enviar y recibir datagramas RTP
    DatagramPacket pqtEnviar; // Paquete UDP con los frames de video

    InetAddress direccionIPCliente; // Direccion IP del Cliente
    int puertoDestinoRTP = 0; // Puerto destino para los paquetes
    // RTP (proporcionado por el cliente RTSP)

    /**
     * GUI.
     */
    JPanel mainPanel;
    JPanel configPanel;
    JPanel statusPanel;

    JLabel label;
    JLabel lhost;
    /**
     * Etiqueta para el puerto.
     */
    JLabel portLabel;
    /**
     * Añadir campo de texto para el puerto del servidor.
     */
    JTextField portnb;
    /**
     * Etiqueta para la informacion de estado.
     */
    JLabel statusinfo;
    /**
     * Etiqueta para las peticiones.
     */
    JLabel rq;
    JLabel clientlabel;
    JLabel clientip;
    JLabel length;

    /**
     * Barra de progreso.
     */
    JProgressBar progress;

    /**
     * Variable de video.
     */
    int numImagen = 0; // Numero de imagen transmitida en este momento
    StreamVideo video; // VideoStream utilizado para acceder a los frames de
    // video
    static int TIPO_MJPEG = 26; // Tipo de carga RTP para video MJPEG
    static int PERIODO_FRAME = 100; // Periodo de frames a transmitir en ms
    static int LONG_VIDEO = 500; // Longitud del video en frames

    Timer temporizador; // Temporizador utilizado para enviar las imagenes del
    // video al ratio adecuado
    byte[] buffer; // Buffer utilizado para almacenar las imagenes a enviar al
    // cliente

    /**
     * Variables RTSP. Estados RTSP.
     */
    final static int INIT = 0;
    final static int READY = 1;
    final static int PLAYING = 2;
    /**
     * Tipos de mensajes RTSP.
     */
    final static int SETUP = 3;
    final static int PLAY = 4;
    final static int PAUSE = 5;
    final static int TEARDOWN = 6;

    static int estado; // Estado del servidor RTSP == INIT o READY o PLAY
    Socket RTSPsocket; // Socket utilizado para recibir y enviar mensajes RTSP
    /**
     * Canales de entrada y salida.
     */
    static BufferedReader RTSPBufferedReader;
    static BufferedWriter RTSPBufferedWriter;
    static String ficheroVideo; // Fichero de video solicitado por el cliente
    static int RTSP_ID = 123456; // ID de la sesion RTSP
    int RTSPNumSeq = 0; // Numero de secuencia de los mensajes RTSP sin sesion

    final static String CRLF = "\n";

    /**
     * Constructor.
     */
    public Servidor() {

        /**
         * Inicialiar Frame.
         */
        super("Servidor");

        /**
         * Inicializar temporizador.
         */
        temporizador = new Timer(PERIODO_FRAME, this);
        temporizador.setInitialDelay(0);
        temporizador.setCoalesce(true);

        /**
         * Reservar memoria para el buffer de envio.
         */
        buffer = new byte[15000];

        /**
         * Manejador para cerrar la ventana principal.
         */
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                /**
                 * Parar el temporizador y salir.
                 */
                temporizador.stop();
                System.exit(0);
            }
        });

        /**
         * GUI.
         */
        mainPanel = new JPanel();
        statusPanel = new JPanel();
        configPanel = new JPanel();

        label = new JLabel(
                "Enviando frame ###. Tamaño paquete: ######. Timestamp: ######.",
                JLabel.CENTER);
        lhost = new JLabel("Localhost:                   ");
        portLabel = new JLabel(" Puerto: ");
        portnb = new JTextField("2000");
        clientlabel = new JLabel(" Cliente IP: ");
        clientip = new JLabel(" ###.###.###.###:#### ");
        statusinfo = new JLabel(" Esperando primer estado RTSP. ");
        rq = new JLabel(" Esperando al Cliente ", JLabel.RIGHT);
        length = new JLabel(" ");

        progress = new JProgressBar(0, 50000);
        progress.setStringPainted(true);

        configPanel.add(lhost);
        configPanel.add(portLabel);
        configPanel.add(portnb);
        statusPanel.add(label);
        statusPanel.add(length);
        statusPanel.add(progress);
        statusPanel.add(clientlabel);
        statusPanel.add(clientip);
        statusPanel.add(statusinfo);
        statusPanel.add(rq);

        /**
         * Capa de salida.
         */
        mainPanel.setPreferredSize(new Dimension(550, 200));
        mainPanel.setLayout(null);
        mainPanel.add(configPanel);
        mainPanel.add(statusPanel);

        configPanel.setBounds(0, 0, 400, 50);
        statusPanel.setBounds(20, 50, 500, 400);

        getContentPane().add(mainPanel, BorderLayout.CENTER);
    }

    /**
     * Funcion principal.
     *
     * @param argv
     *            Entrada por linea de comandos.
     * @throws Exception
     */
    public static void main(String argv[]) throws Exception {
        /**
         * Crear objeto Servidor.
         */
        Servidor servidor = new Servidor();

        /**
         * Mostrar GUI.
         */
        servidor.pack();
        servidor.setVisible(true);

        /**
         * Obtener el puerto RTSP.
         */
        int RTSPport = Integer.parseInt(servidor.portnb.getText());

        /**
         * Iniciar la conexion TCP con el cliente para la sesion RTSP.
         */
        ServerSocket socketServidor = new ServerSocket(RTSPport);
        servidor.RTSPsocket = socketServidor.accept();
        socketServidor.close();

        /**
         * Obtener direccion IP del cliente.
         */
        servidor.lhost.setText("Localhost: "
                + servidor.RTSPsocket.getLocalSocketAddress() + "");
        servidor.direccionIPCliente = servidor.RTSPsocket.getInetAddress();

        /**
         * Imprimir la direccion IP del Cliente.
         */
        servidor.clientip.setText(servidor.direccionIPCliente.toString() + ":"
                + RTSPport + " (" + servidor.direccionIPCliente.getHostName()
                + ") ");

        /**
         * Inicializar el estado RTSP.
         */
        estado = INIT;

        /**
         * Establecer los canales de entrada y salida.
         */
        RTSPBufferedReader = new BufferedReader(new InputStreamReader(
                servidor.RTSPsocket.getInputStream()));
        RTSPBufferedWriter = new BufferedWriter(new OutputStreamWriter(
                servidor.RTSPsocket.getOutputStream()));

        /**
         * Esperar por el mensaje SETUP del cliente.
         */
        int tipoSolicitud;
        boolean acabo = false;
        while (!acabo) {
            tipoSolicitud = servidor.parseSolicitudRTSP(); // Bloqueante

            if (tipoSolicitud == SETUP) {
                acabo = true;

                /**
                 * Actualizar estado RTSP.
                 */
                estado = READY;
                servidor.statusinfo.setText("Nuevo estado RTSP: READY");

                /**
                 * Enviar respuesta.
                 */
                servidor.enviarRespuestaRTSP();

                /**
                 * Inicializar el objeto VideoStream.
                 */
                servidor.video = new StreamVideo(ficheroVideo);

                /**
                 * Inicializar el socket RTP.
                 */
                servidor.socketRTP = new DatagramSocket();
            }
        }

        /**
         * Bucle para gestionar las solicitudes RTSP.
         */
        while (true) {
            /**
             * Analizar la solicitud.
             */
            tipoSolicitud = servidor.parseSolicitudRTSP(); // Bloqueante

            if ((tipoSolicitud == PLAY) && (estado == READY)) {
                /**
                 * Enviar la respuesta.
                 */
                servidor.enviarRespuestaRTSP();
                /**
                 * Iniciar temporizador.
                 */
                servidor.temporizador.start();
                /**
                 * Actualizar estado.
                 */
                estado = PLAYING;
                servidor.statusinfo.setText("Nuevo estado RTSP: PLAYING");
            } else if ((tipoSolicitud == PAUSE) && (estado == PLAYING)) {
                /**
                 * Enviar la respuesta.
                 */
                servidor.enviarRespuestaRTSP();
                /**
                 * Parar temporizador.
                 */
                servidor.temporizador.stop();
                /**
                 * Actualizar estado.
                 */
                estado = READY;
                servidor.statusinfo.setText("Nuevo estado RTSP: READY");
            } else if (tipoSolicitud == TEARDOWN) {
                /**
                 * Enviar la respuesta.
                 */
                servidor.enviarRespuestaRTSP();
                /**
                 * Parar temporizador.
                 */
                servidor.temporizador.stop();
                /**
                 * Cerrar sockets.
                 */
                servidor.RTSPsocket.close();
                servidor.socketRTP.close();

                System.exit(0);
            }
        }
    }

    /*
     * (non-Javadoc) Manejador del temporizador
     *
     * @see
     * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
     */
    public void actionPerformed(ActionEvent e) {

        /**
         * Si el numero de imagen es menor que la longitud del video.
         */
        if (numImagen < LONG_VIDEO) {
            /**
             * Incrementar numImagen.
             */
            numImagen++;

            try {
                /**
                 * Obtener el siguiente frame y su tamaño.
                 */
                int longImagen = video.getnextframe(buffer);

                /**
                 * Construir un paquete RTP con el frame.
                 */
                PaqueteRTP paqueteRTP = new PaqueteRTP(TIPO_MJPEG, numImagen,
                        numImagen * PERIODO_FRAME, buffer, longImagen);

                /**
                 * Obtener la longitud total del paquete RTP a enviar.
                 */
                int longPaquete = paqueteRTP.getLong();
                length.setText(" Tamaño paquete: " + longPaquete
                        + ". Timestamp: " + paqueteRTP.getTimestamp() + ".");

                // Print progress
                progress.setValue(paqueteRTP.getTimestamp());

                /**
                 * Recuperar el array de bits del paquete y almacenarlo en un
                 * array.
                 */
                byte[] bitsPaquete = new byte[longPaquete];
                paqueteRTP.getPaquete(bitsPaquete);

                /**
                 * Enviar el paquete como un DatagramPacket sobre un socket UDP.
                 */
                pqtEnviar = new DatagramPacket(bitsPaquete, longPaquete,
                        direccionIPCliente, puertoDestinoRTP);
                socketRTP.send(pqtEnviar);

                // System.out.println("Enviando frame #" + numImagen);

                /**
                 * Mostrar la cabecera.
                 */
                paqueteRTP.printheader();

                /**
                 * Actualizar GUI.
                 */
                label.setText("Enviando frame: " + numImagen + ".");

            } catch (Exception ex) {
                System.out.println("Excepcion 1: " + ex);
                System.exit(0);
            }
        } else {
            /**
             * Si se ha alcanzado el final del video, parar temporizador
             */
            temporizador.stop();
        }
    }

    /**
     * Analizar solicitud RTSP.
     *
     * @return Devuelve
     */
    private int parseSolicitudRTSP() {
        int tipoSolicitud = -1;
        try {
            /**
             * Parsear la linea de solicitud y extraer el tipo de solicitud.
             */
            String lineaSolicitud = RTSPBufferedReader.readLine();
            rq.setText("Recibido del Cliente: " + lineaSolicitud);

            StringTokenizer tokens = new StringTokenizer(lineaSolicitud);
            String stringTipoSolicitud = tokens.nextToken();

            /**
             * Convertir a una estructura tipoSolicitud.
             */
            if ((new String(stringTipoSolicitud)).compareTo("SETUP") == 0)
                tipoSolicitud = SETUP;
            else if ((new String(stringTipoSolicitud)).compareTo("PLAY") == 0)
                tipoSolicitud = PLAY;
            else if ((new String(stringTipoSolicitud)).compareTo("PAUSE") == 0)
                tipoSolicitud = PAUSE;
            else if ((new String(stringTipoSolicitud)).compareTo("TEARDOWN") == 0)
                tipoSolicitud = TEARDOWN;

            if (tipoSolicitud == SETUP) {
                /**
                 * Extraer el fichero de video de la linea de solicitud.
                 */
                ficheroVideo = tokens.nextToken();
            }

            /**
             * Parsear la linea de numero de secuencia.
             */
            String lineaNumSeq = RTSPBufferedReader.readLine();
            System.out.println(lineaNumSeq);
            tokens = new StringTokenizer(lineaNumSeq);
            tokens.nextToken();
            RTSPNumSeq = Integer.parseInt(tokens.nextToken());

            /**
             * Obtener la ultima linea.
             */
            String ultimaLinea = RTSPBufferedReader.readLine();
            System.out.println(ultimaLinea);

            if (tipoSolicitud == SETUP) {
                /**
                 * Extraer el puerto destino RTP de la ultima linea.
                 */
                tokens = new StringTokenizer(ultimaLinea);
                for (int i = 0; i < 3; i++)
                    tokens.nextToken(); // no utilizado
                puertoDestinoRTP = Integer.parseInt(tokens.nextToken());
            }
            /**
             * Sino la ultima linea es la linea de identificador de sesion, no
             * se analiza por ahora.
             */
        } catch (Exception ex) {
            System.out.println("Excepcion 2: " + ex);
            System.exit(0);
        }
        return (tipoSolicitud);
    }

    /**
     * Enviar respuesta RTSP.
     */
    private void enviarRespuestaRTSP() {
        try {
            RTSPBufferedWriter.write("RTSP/1.0 200 OK" + CRLF);
            RTSPBufferedWriter.write("CSeq: " + RTSPNumSeq + CRLF);
            RTSPBufferedWriter.write("Session: " + RTSP_ID + CRLF);
            RTSPBufferedWriter.flush();
            System.out
                    .println("Servidor RTSP - Enviando respuesta al cliente.");
        } catch (Exception ex) {
            System.out.println("Excepcion 3: " + ex);
            System.exit(0);
        }
    }
}
