#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

import threading
import Queue
import random
import time

## Clase Counter
class Counter:
	def __init__(self):
		self.cont = 0 # si se pusiese self en vez de Counter no lo haria
	
	def increase(self):
		self.cont += 1
	
	def get(self):
		return self.cont

class HiloInt(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id

  def run(self):
    while True:
      cola.put(random.randint(0,100))
      time.sleep(1)

class HiloFl(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id

  def run(self):
    while True:
      cola.put(random.random())
      time.sleep(2)

class HiloStr(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id

  def run(self):
    while True:
      cola.put(cadenas[random.randint(0,len(cadenas)-1)])
      time.sleep(3)

class Consumidor(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id

  def run(self):
    while True:
      try:
      	obj = cola.get()
      	if type(obj) == type(1):
      		cntInt.increase()
      		print "Hilo %d - cont entero:" %(self.id),; print cntInt.get()
      	elif type(obj) == type(1.1):
      		cntFlt.increase()
      		print "Hilo %d - cont float:" %(self.id),; print cntFlt.get()
      	elif type(obj) == type("1"):
      		cntStr.increase()
      		print "Hilo %d - cont cadena:" %(self.id),; print cntStr.get()
      	
      	print "Obj:",; print obj
      	print
      	
      except Queue.Empty:
        print "Fin hilo_%s, elementos extraídos %d" %(self.id, self.n)
        break

## MAIN ##

cadenas = ["hola","que","tal","estas"]
cola = Queue.Queue()
hilos = [HiloInt("int"),HiloFl("float"),HiloStr("str")]
cntInt,cntFlt,cntStr = Counter(),Counter(),Counter()
it = 0
consumer = []

while it not in [1,2,3,4,5]:
	it = int(raw_input("Cuantos hilos quiere (1-5): "))
	if it not in [1,2,3,4,5]:
		print "Error, repita la operacion"
		it = raw_input("Cuantos hilos quiere (1-5): ")

for i in range(0,it):
	consumer.append(Consumidor(i+1))

for h in hilos:
	h.start()
for c in consumer:
	c.start()

