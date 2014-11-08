#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

#Reconoce una cadena que sea un número decimal

import re

cadena = raw_input("Introduce una cadena: ")
patron = re.compile(r"^([\-\+]?\d+)[,\.](\d+)\Z")

# () indica la cadena que esta dentro
# \d un digito numerico

if patron.search(cadena):
	print "Es un número decimal";
	numero = patron.search(cadena).groups()
	print "parte entera",numero[0]
	print "parte decimal",numero[1]
else:
	print "No es un número decimal"

