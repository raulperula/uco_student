#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

import re

cadena = raw_input("Introduce una cadena: ")
busca = raw_input("Subcadena a buscar: ")

if re.search(busca,cadena):
	print busca,"está en",cadena
else:
	print busca,"no está en",cadena

