/**
 * @file    StreamVideo.java
 * @brief   Clase que se utiliza para el tratado y transmision del video.
 *
 * @author Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

import java.io.*;

public class StreamVideo {

    FileInputStream fis; // Fichero de video
    int frame_nb; // Frame nb actual

    /**
     * Constructor.
     *
     * @param filename
     *            Nombre del fichero.
     * @throws Exception
     */
    public StreamVideo(String filename) throws Exception {
        /**
         * Inicializar variables.
         */
        fis = new FileInputStream(filename);
        frame_nb = 0;
    }

    /**
     * Obtener siguiente frame.
     *
     * @param frame
     * @return Devuelve el siguiente frame como un array de bytes y el tamaño
     *         del frame.
     * @throws Exception
     */
    public int getnextframe(byte[] frame) throws Exception {
        int length = 0;
        String length_string;
        byte[] frame_length = new byte[5];

        /**
         * Leer el tamaño del frame actual.
         */
        fis.read(frame_length, 0, 5);

        /**
         * Transformar frame_length a entero.
         */
        length_string = new String(frame_length);
        length = Integer.parseInt(length_string);

        return (fis.read(frame, 0, length));
    }
}
