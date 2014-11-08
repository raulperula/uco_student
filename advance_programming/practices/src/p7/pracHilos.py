#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import threading
import sys

cerrojo = threading.Lock()

## Clase Counter
class Counter:
	def __init__(self):
		Counter.cont = 0 # si se pusiese self en vez de Counter no lo haria
	
	def increase(self):
		Counter.cont += 1
	
	def get(self):
		return Counter.cont

## Clase Hilo
class Hilo(threading.Thread):
	def __init__(self, id, cont, it):
		threading.Thread.__init__(self)
		self.id = str(id)
		self.cont = cont
		self.it = it

	def run(self):
		cerrojo.acquire()
		for i in range(0,self.it):
			self.cont.increase()
		cerrojo.release()

def main():
	contador = Counter()
	hilos = []
	
	if len(sys.argv) == 3:
		num_hilos = int(sys.argv[1])
		num_iter = int(sys.argv[2])
	else:
		print "Numero incorrecto de parametros"
		return
	
	for i in range(1,num_hilos+1):
		hilos.append(Hilo(i,contador,num_iter))
	
	for h in hilos:
		h.start()
	
	while threading.activeCount() > 1:
		pass

	print "%d hilos * %d iteraciones: %d" %(num_hilos, num_iter, contador.get())

## MAIN ##

if __name__ == "__main__":
	main()

