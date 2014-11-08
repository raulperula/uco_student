#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import funciones

x1 = funciones.suma(4, 3)
x2 = funciones.resta(4, 3)
x3 = funciones.mult(4, 3)
x4 = funciones.div(4, 3)

print x1
print funciones.suma.__doc__
print x2
print funciones.resta.__doc__
print x3
print funciones.mult.__doc__
print x4
print funciones.div.__doc__

