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

class Saca(threading.Thread):
  def __init__(self, id):
    threading.Thread.__init__(self)
    self.id = id
    self.n = 0

  def run(self):
    global sacados
    while sacados < 100:
      obj = cola.get()
      self.n += 1
      sacados += 1
      print "hilo_%s saca de la cola %d"%(self.id, obj)
    print "hilo_%s ha sacado de la cola %d elementos"%(self.id,self.n)

class Mete(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)

  def run(self):
    for i in range(100):
      cola.put(random.randint(1,100))
    for i in range(2):
      cola.put(-1)
       
cola = Queue.Queue()
sacados = 0
hilosSaca = [Saca(1),Saca(2),Saca(3)]
hiloMete = Mete()

hiloMete.start()

for h in hilosSaca:
    h.start()

