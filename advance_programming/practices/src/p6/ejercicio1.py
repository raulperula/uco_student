#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import re

f = open(raw_input("Escriba nombre fichero: "), "r")

lista = f.read()
print re.findall(r"[^0-9]*([0-9]+)[^0-9]*([0-9]*)",lista)

f.close()

