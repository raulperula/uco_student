#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import threading
from time import sleep

cerrojo = threading.Lock()

class Hilo(threading.Thread):
	def __init__(self, id):
	  threading.Thread.__init__(self)
	  self.id = id

	def run(self):
	  cerrojo.acquire()
	  print "Yo soy hilo_%s y ahora los demás hilos (%d) que esperen..." %(self.id,threading.activeCount()-2)
	  sleep(5)
	  cerrojo.release()

hilos = [Hilo(1),Hilo(2),Hilo(3)]

for h in hilos:
	h.start()

