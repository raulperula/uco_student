#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import socket
import threading
import sys

cerrojo = threading.Lock()
contador = 0

## Clase Hilo
class Hilo(threading.Thread):
	def __init__(self,conn,addr):
		threading.Thread.__init__(self)
		self.conn = conn
		self.addr = addr

	def run(self):
		cerrojo.acquire()
		global contador
		
		print "\nBienvenido al servidor de multiplicación"
		print "Conectado desde ", self.addr
		
		while True:
			try:
				self.conn.send('\nDame el primer número: ')
				n1 = float(self.conn.recv(1024))
				print "\nIntroducido:", n1
				self.conn.send('Dame el segundo número: ')
				n2 = float(self.conn.recv(1024))
				print "Introducido:", n2
	
				if n1 == n2 == 0:
					print "\nLas operaciones en el servidor hasta ahora son:", contador ,"operaciones"
					print "\nADIOS\n"
					self.conn.close()
					break
					
				else:
					print "\nEl resultado es:",n1*n2
					contador += 1
			except ValueError:
				print "El valor no es un numero"
				self.conn.close()
		cerrojo.release()

def main():
	hilo = []
	
	#creamos socket pasivo y escuchamos en el puerto 9000
	s = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
	s.bind( ( socket.gethostname(), 9000 ) )
	s.listen( 5 )
	
	#hacemos ciclo infinito
	while True:
		conn, addr = s.accept()
	
		hilo = Hilo(conn,addr)
		
		hilo.start()
		
		while threading.activeCount() > 1:
			pass
	
## MAIN ##

if __name__ == "__main__":
	main()


