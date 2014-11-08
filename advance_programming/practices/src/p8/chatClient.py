#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import string
import threading
import socket
import sys

## Recibir mensaje ##
class recibir(threading.Thread):
	def __init__(self, socket):
		threading.Thread.__init__(self)
		self.conn = socket
		self.mensaje = ''
	def run(self):
		while True:
			self.mensaje = self.conn.recv(1024)
			print(self.mensaje)
		self.conn.close()

## Enviar mensaje ##
class enviar(threading.Thread):
	def __init__(self, socket):
		threading.Thread.__init__(self)
		self.conn = socket
		self.mensaje = ''
	def run(self):
		while True:
			self.mensaje = raw_input("Mensaje: ")
			self.conn.send(self.mensaje)
		self.conn.close()


## MAIN ##

miSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
miSocket.connect((socket.gethostname(),8000))

hilos = [enviar(miSocket), recibir(miSocket)]

for h in hilos:
	h.start()

