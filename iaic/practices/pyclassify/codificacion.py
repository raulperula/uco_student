#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: codificacion.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo sustituye los caracteres no ASCII de los textos para que
puedan ser procesados por el programa.
"""


__author__ = "Manuel Pedrero Luque <i62pelum@uco.es>"
__author__ = "Raul Perula Martinez <i62pemar@uco.es>"
__author__ = "Miguel Angel Sanchez Muñoz <i52samum@uco.es>"
__date__ = "01 de julio 2010"
__version__ = "$ Revision: 1 $"
__credits__ = """Universidad de Cordoba"""

import string
import codecs
from nltk.corpus.reader import CorpusReader

archivos = CorpusReader('corpus/texto','.*\.txt')

dir = []

lista = archivos.fileids()
for i in lista:
	cad = 'corpus/texto/'+i
	dir.append(cad)


for i in dir:
	f = open(i,'r')
	text = f.read()

	text = text.replace('\xe1','a')
	text = text.replace('\xe9','e')
	text = text.replace('\xed','i')
	text = text.replace('\xf3','o')
	text = text.replace('\xfa','u')
	text = text.replace('\xf1','n')
	text = text.replace('\xc1','A')
	text = text.replace('\xc9','E')
	text = text.replace('\xcd','I')
	text = text.replace('\xd3','O')
	text = text.replace('\xda','U')
	text = text.replace('\xd1','N')
	
	f.close()
	
	f = open(i,'w')
	f.write(text)
	f.close()
