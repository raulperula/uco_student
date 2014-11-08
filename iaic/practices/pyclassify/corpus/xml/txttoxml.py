#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

import sys
import string

if __name__ == "__main__":
	cad_tex_ap = "<texto>"
	cad_tex_ci = "</texto>"
	cad_par_ap = "<p>"
	cad_par_ci = "</p>"
	
	indice = open(sys.argv[1],"rt")
	for archivo in indice.readlines():
		archivo = archivo.replace('\n', '')
		print archivo
		# Abrimos el archivo de texto
		fichero_texto = open(archivo,"rt")
		texto = fichero_texto.readlines()
		nuevo_texto = list()
		
		nuevo_texto.append(cad_tex_ap+"\n")
		nuevo_texto.append(cad_par_ap+"\n")
		
		for cadena in texto:
			if cadena == "\n":
				nuevo_texto.append(cad_par_ci+"\n"+cad_par_ap+"\n")
			else:
				nuevo_texto.append(cadena)
				
		nuevo_texto.append(cad_par_ci+"\n")
		nuevo_texto.append(cad_tex_ci+"\n")
		print nuevo_texto
		fichero_texto.close()
		fichero_texto = open(archivo,"wt")
		
		for cadena in nuevo_texto:
			fichero_texto.write(cadena)
		fichero_texto.close()
