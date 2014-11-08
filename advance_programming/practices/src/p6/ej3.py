#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

#Reconoce una cadena que sea un numero entero

import re

cadena = raw_input("Introduce una cadena: ")
patron = re.compile("^[\-\+]?[0-9]+\Z")

# ^ lo que viene a continuacion tiene que ir al principio
# \caracter para representar caracteres que pueden formar una expresion regular
# ? lo de la izquierda puede aparecer cero o una vez
# + lo de la izquierda puede aparecer una o mas veces
# \Z indica el final, a partir de aqui no reconoce nada

if patron.search(cadena):
	print "Es un entero";
else:
	print "No es un entero"

