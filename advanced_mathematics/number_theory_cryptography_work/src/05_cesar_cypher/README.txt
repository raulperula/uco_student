El programa "cesar_cod.exe" codifica un mensaje dado (en mayúsculas y sin espacios) con el cifrado del César y una clave K dada, creando dos archivos de texto: "info.txt", que muestra el texto plano, codificado y la clave; y "cod_cesar.txt", que sólo contiene el texto codificado.

Los otros dos programas "cesar_dec_normal.exe" y "cesar_dec_fb.exe", decodifican un mensaje codificado. En el caso del primero, usando la clave K dada por el usuario, y en el caso del segundo, descifrando el mensaje por fuerza bruta, esto es, decodificandolo de todas las maneras posibles.

Si el mensaje que se quiere descifrar ha sido cifrado anteriormente con el programa "cesar_cod.exe", los dos programas de descifrado tienen la opcion de cargar directamente el archivo del texto codificado, no teniendo en este caso que escribirlo a mano el usuario.

NOTA: Los programas estan hechos de manera que si se quiere cambiar los caracteres de la clave (por ejemplo si se quieren incluir minusculas, espacios, simbolos, etc) solo hay que escribirlos en la cadena abc[] = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ". Hay que tener cuidado de cambiarlo en los tres programas.