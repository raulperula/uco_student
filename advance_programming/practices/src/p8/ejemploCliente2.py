#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Lee la página enviada por el servidor web de www.elmundo.es

import socket

miSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
miSocket.connect(("www.elmundo.es", 80))
miSocket.send("GET / HTTP/1.0\n\n")

mensaje = ""
iteraciones = 0
data = miSocket.recv(256)

while data != "":
	mensaje += data
	iteraciones += 1
	data = miSocket.recv(256)
print mensaje
print "Iteraciones: ",iteraciones
miSocket.close()

