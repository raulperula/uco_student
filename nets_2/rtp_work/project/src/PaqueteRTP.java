/**
 * @file    PaqueteRTP.java
 * @brief   Clase que contiene los metodos para el tratamiento de los paquetes
 *          de tipo RTP.
 *
 * @author Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

public class PaqueteRTP {
    /**
     * Tamaño de la cabecera RTP.
     */
    static int LONG_CABECERA = 12;

    /**
     * Campos de la cabecera RTP.
     */
    public int Version;
    public int Padding;
    public int Extension;
    public int CC;
    public int Marker;
    public int PayloadType;
    public int SequenceNumber;
    public int TimeStamp;
    public int Ssrc;

    /**
     * Array de bits de la cabecera RTP.
     */
    public byte[] cabecera;

    /**
     * Tamaño de la carga RTP.
     */
    public int longCarga;
    /**
     * Array de bits de la carga RTP.
     */
    public byte[] carga;

    /**
     * Constructor de un paquete RTP, utilizando los campos de la cabecera y la
     * carga.
     *
     * @param PType
     *            Tipo de Payload.
     * @param Framenb
     *            Numero de frame.
     * @param Time
     *            Tiempo.
     * @param datos
     *            Datos del video.
     * @param longDatos
     *            Longitud de los datos.
     */
    public PaqueteRTP(int PType, int Framenb, int Time, byte[] datos,
            int longDatos) {
        /**
         * Rellenar los campos de la cabecera por defecto.
         */
        Version = 2;
        Padding = 0;
        Extension = 0;
        CC = 0;
        Marker = 0;
        Ssrc = 0;

        /**
         * Rellenar los campos que cambian de la cabecera.
         */
        SequenceNumber = Framenb;
        TimeStamp = Time;
        PayloadType = PType;

        /**
         * Construir el array de bytes.
         */
        cabecera = new byte[LONG_CABECERA];

        /**
         * Rellenar con los campos de la cabecera RTP.
         */
        cabecera[0] = (byte) (cabecera[0] | Version << 7);
        cabecera[0] = (byte) (cabecera[0] | Padding << 5);
        cabecera[0] = (byte) (cabecera[0] | Extension << 4);
        cabecera[0] = (byte) (cabecera[0] | CC << 3);

        cabecera[1] = (byte) (cabecera[1] | Marker << 7);
        cabecera[1] = (byte) (cabecera[1] | PayloadType << 6);

        cabecera[2] = (byte) (SequenceNumber >> 8);
        cabecera[3] = (byte) (SequenceNumber & 0xFF);
        cabecera[4] = (byte) (TimeStamp >> 24);
        cabecera[5] = (byte) (TimeStamp >> 16);
        cabecera[6] = (byte) (TimeStamp >> 8);
        cabecera[7] = (byte) (TimeStamp & 0xFF);
        cabecera[8] = (byte) (Ssrc >> 24);
        cabecera[9] = (byte) (Ssrc >> 16);
        cabecera[10] = (byte) (Ssrc >> 8);
        cabecera[11] = (byte) (Ssrc & 0xFF);

        /**
         * Rellenar la carga.
         */
        longCarga = longDatos;
        carga = new byte[longDatos];

        /**
         * Rellenar el array de carga.
         */
        carga = datos;
    }

    /**
     * Constructor de un paquete RTP a partir de un array de bytes.
     *
     * @param paquete
     *            Paquete RTP.
     * @param longPaquete
     *            Longitud del paquete RTP.
     */
    public PaqueteRTP(byte[] paquete, int longPaquete) {
        /**
         * Rellenar los campos por defecto.
         */
        Version = 2;
        Padding = 0;
        Extension = 0;
        CC = 0;
        Marker = 0;
        Ssrc = 0;

        /**
         * Comprobar si la longitud total del paquete es menor que la de la
         * cabecera.
         */
        if (longPaquete >= LONG_CABECERA) {
            /**
             * Obtener los bits de la cabecera.
             */
            cabecera = new byte[LONG_CABECERA];

            for (int i = 0; i < LONG_CABECERA; i++) {
                cabecera[i] = paquete[i];
            }

            /**
             * Obtener los bits de la carga.
             */
            longCarga = longPaquete - LONG_CABECERA;
            carga = new byte[longCarga];

            for (int i = LONG_CABECERA; i < longPaquete; i++) {
                carga[i - LONG_CABECERA] = paquete[i];
            }

            /**
             * Interpretar los campos que cambian de la cabecera.
             */
            PayloadType = cabecera[1] & 127;

            SequenceNumber = cabecera[3] + 256 * cabecera[2];

            TimeStamp = cabecera[7] + 256 * cabecera[6] + 65536 * cabecera[5]
                    + 16777216 * cabecera[4];
        }
    }

    /**
     * Obtener la carga de datos.
     *
     * @param datos
     *            Datos del video.
     * @return Devuelve el array de bits de carga y su tamaño.
     */
    public int getCarga(byte[] datos) {
        for (int i = 0; i < longCarga; i++)
            datos[i] = carga[i];

        return (longCarga);
    }

    /**
     * Obtener la longitud de la carga.
     *
     * @return Devuelve la longitud de la carga.
     */
    public int getLongCarga() {
        return (longCarga);
    }

    /**
     * Obtener la longitud total del paquete RTP.
     *
     * @return Devuelve la longitud total del paquete RTP.
     */
    public int getLong() {
        return (longCarga + LONG_CABECERA);
    }

    /**
     * Obtener un paquete RTP bien formado.
     *
     * @param paquete
     *            Paquete RTP.
     * @return Devuelve el paquete y su longitud.
     */
    public int getPaquete(byte[] paquete) {
        /**
         * Construye el paquete = cabecera + carga.
         */
        for (int i = 0; i < LONG_CABECERA; i++)
            paquete[i] = cabecera[i];
        for (int i = 0; i < longCarga; i++)
            paquete[i + LONG_CABECERA] = carga[i];

        /**
         * Devuelve la longitud total del paquete.
         */
        return (longCarga + LONG_CABECERA);
    }

    /**
     * Obtener el tiempo actual.
     *
     * @return Devuelve el tiempo.
     */
    public int getTimestamp() {
        return (TimeStamp);
    }

    /**
     * Obtener el numero de secuencia actual.
     *
     * @return Devuelve el numero de secuencia.
     */
    public int getNumeroSecuencia() {
        return (SequenceNumber);
    }

    /**
     * Obtener el tipo de carga del paquete RTP.
     *
     * @return Devuelve el tipo de carga.
     */
    public int getTipoCarga() {
        return (PayloadType);
    }

    /**
     * Muestra la cabecera.
     */
    public void printheader() {
        // for (int i = 0; i < (LONG_CABECERA - 4); i++) {
        // for (int j = 7; j >= 0; j--)
        // if (((1 << j) & cabecera[i]) != 0)
        // System.out.print("1");
        // else
        // System.out.print("0");
        // System.out.print(" ");
        // }
        // System.out.println();
    }
}
