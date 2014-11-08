#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import threading

class MiHilo( threading.Thread ):
	def __init__( self, num, nom ):
		threading.Thread.__init__(self)
		self.bignum = num
		self.nombre = nom

	def run( self ):
		for l in range( 10 ):
			for k in range( self.bignum ):
				res = 0
				for i in range( self.bignum ):
					res += 1
			print( self.nombre + ": iteracion " + str( l ) )

def test():
	num1 = 1000
	num2 = 500

	thr1 = MiHilo( num1, "Hilo 1" )
	thr2 = MiHilo( num2, "Hilo 2" )

	thr2.start()
	print "Lanzado hilo 2"

	thr1.start()
	print "Lanzado hilo 1"

	thr1.join()
	print "Terminó hilo 1"

	thr2.join()
	print "Terminó hilo 2"

if __name__ == "__main__":
	test()

