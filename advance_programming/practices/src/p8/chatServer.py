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

cliente = {'nick':[], 'socket':[]}

## Servidor ##
class servidor(threading.Thread):
	## Constructor de la clase ##
	def __init__(self, socket):
		threading.Thread.__init__(self)
		self.conn = socket
		self.mensaje = ''
		self.conectado = False
	
	## Ejecutor del hilo ##
	def run(self):
		while True:
			## Se recibe el mensaje
			self.mensaje = self.conn.recv(1024)
			
			## Entrar un usuario en el chat ##
			if (('ADD ' in self.mensaje) or ('add ' in self.mensaje)):
				if(self.conectado == False):
					self.conectado = True					
					cliente['nick'].append(self.mensaje[4:])
					cliente['socket'].append(self.conn)
					for i in cliente['socket']:
						if (i == self.conn):
							i.send("'"+self.mensaje[4:]+"'"+" ha entrado en el chat")
							print "'"+self.mensaje[4:]+"'"+" ha entrado en el chat"
				else:
					self.conn.send("Ya estas dentro del chat")
			## Listar todos los usuarios ##
			elif ((('LIST' in self.mensaje) or ('list' in self.mensaje)) and (self.conectado == True)):
				print "Lista de usuarios en el chat:"
				for i in cliente['nick']:
					print str(i)
					self.conn.send(i)
			## Enviar mensaje general ##
			elif (((('TEXT ' in self.mensaje) or ('text ' in self.mensaje)) and (('TEXT TO ' not in self.mensaje) and ('text to ' not in self.mensaje))) and
						 (self.conectado == True)):
				for i in cliente['socket']:
					if (i != self.conn):
						i.send("'"+cliente['nick'][cliente['socket'].index(self.conn)]+"'"+" dice: "+self.mensaje[5:])
			## Enviar mensaje a un usuario ##
			elif ((('TEXT TO ' in self.mensaje) or ('text to ' in self.mensaje)) and (self.conectado == True)):
				palabras = self.mensaje[8:].split()
				for i in cliente['nick']:
					if (i == palabras[0]):
						del palabras[0]
						aux = string.join(palabras,' ')
						cliente['socket'][cliente['nick'].index(i)].send(cliente['nick'][cliente['socket'].index(self.conn)]+" dice: "+aux)
			## Salir un usuario del chat ##
			elif ((('END' in self.mensaje) or ('end' in self.mensaje))):
				if (self.conectado == True):
					for i in cliente['socket']:
						if (i == self.conn):
							nick = cliente['nick'][cliente['socket'].index(i)]
							print "'"+nick+"'"+" ha salido del chat"
							i.send("'"+nick+"'"+" ha salido del chat")
							cliente['nick'].remove(nick)
							cliente['socket'].remove(i)
							self.conectado = False
			else:
				print "Comando incorrecto"
		
		## Se cierra la conexion
		self.conn.close() 

## MAIN ##

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((socket.gethostname(),8000))
s.listen(5)

while(True):
	conn, addr = s.accept()
	servidor(conn).start()

