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

resp = raw_input("Introduce 'Sí': ")
patron = re.compile("[Ss][IÍií]")

if patron.search(resp):
	print "Respuesta afirmativa";
else:
	print "Respuesta NO afirmativa";