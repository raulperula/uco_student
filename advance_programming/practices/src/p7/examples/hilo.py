#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import threading

class Hilo(threading.Thread):
	def __init__(self, id):
		threading.Thread.__init__(self)
		self.id = "hilo_" + str(id)

	def run(self):
		print "Yo soy %s y la variable d tiene el valor %s" %(self.id,d)

d = 1;
hilos = [Hilo(1),Hilo(2),Hilo(3)]

for h in hilos:
	h.start()

