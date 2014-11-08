#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

#!/usr/bin/env python
# -*- coding: latin1 -*-

#Sustituye pre por PRE sólo si es un prefijo

import re

cadena = raw_input("Introduce una cadena: ")

cadena = re.sub(r"\bpre\B","PRE",cadena)

# r de manera recursiva
# \b indica un comienzo de palabra
# \B indica que puede haber algo mas despues

print "Cadena sustituída: ",cadena

