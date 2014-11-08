#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#Crear una clase llamada Punto que represente un punto en un espacio bidimensional, y realizar las siguientes operaciones:
#    * Crear un atributo de clase cuyo valor sea igual al numero de objetos de la clase Punto que se han creado.
#    * Crear un metodo (mostrar) que muestre por pantalla los valores almacenados del objeto.
#    * Sobrecargar los operadores + y - para que permitan la suma/resta de puntos y la suma/resta escalar.
#    * Sobrecargar el operador * para que permita la multiplicacion de puntos y la multiplicacion escalar.
#    * Realizar lo necesario para que al ejecutar la orden print sobre un objeto de la clase Punto se escriba por la pantalla:
				#Coordenada X: <valor x>
				#Coordenada Y: <valor y>

class Punto:
	numObjetos = 0
	
	# Constructor
	def __init__(self, x, y):
		self.x = x
		self.y = y
		Punto.numObjetos += 1
	
	# Operador suma
	def __add__(self, obj):
		if type(obj) == type(1):
			obj = Punto(obj,obj)
		return Punto(self.x+obj.x, self.y+obj.y)

	__radd__ = __add__
	
	# Operador resta
	def __sub__(self, obj):
		if type(obj) == type(1):
			obj = Punto(obj,obj)
		return Punto(self.x-obj.x, self.y-obj.y)

	__rsub__ = __sub__
	
	# Operador multiplicacion
	def __mul__(self, obj):
		if type(obj) == type(1):
			obj = Punto(obj,obj)
		return Punto(self.x*obj.x, self.y*obj.y)

	__rmul__ = __mul__
	
	# Impresion de datos
	def __str__(self):
		aux1 = "\nCoordenada X: %d" %(self.x) + "\nCoordenada Y: %d" %(self.y)
		return aux1

## MAIN ##
print "\nCreacion de puntos:"
p1 = Punto(2,3)
p2 = Punto(3,4)
print "punto 1: ", p1, "\npunto 2: ", p2

print "\nPruebas del operador de suma/resta:"
p3 = p1+p2
p4 = p3-p3
print "punto 3: ", p3
print "punto 4: ", p4

print "\nNumero de objetos hasta ahora:",Punto.numObjetos

print "\nPruebas del operador de suma/resta escalar:"
p1 = 3+p1
print p1
p1 = 3-p1
print p1
p1 = p1+3
print p1
p1 = p1-3
print p1

print "\nPruebas del operador de multiplicacion:"
print p2*p3
print p1*1
print 2*p2
print 

