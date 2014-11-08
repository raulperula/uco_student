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

class Hilo(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id
    self.n = 0

  def run(self):
    while True:
      try:
        obj = cola.get(False)
        print "hilo_%s saca de la cola %d"%(self.id, obj)
        self.n += 1
      except Queue.Empty:
        print "Fin hilo_%s, elementos extraídos %d"%(self.id,self.n)
        break
           
cola = Queue.Queue()
hilos = [Hilo(1),Hilo(2),Hilo(3)]

for i in range(100):
  cola.put(i)
   
for h in hilos:
  h.start()

