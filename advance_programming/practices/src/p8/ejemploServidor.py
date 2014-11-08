#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Crea un socket pasivo que envía la cadena "Hola Mundo" por el puerto 9000

import socket

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind((socket.gethostname(), 9000))
serverSocket.listen(1)

while True:
	channel, port = serverSocket.accept()
	channel.send('Hola Mundo!')
	channel.close()
