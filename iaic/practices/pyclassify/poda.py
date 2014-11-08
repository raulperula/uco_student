#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: poda.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo contiene el clasificador por el metodo de la poda.
"""


__author__ = "Manuel Pedrero Luque <i62pelum@uco.es>"
__author__ = "Raul Perula Martinez <i62pemar@uco.es>"
__author__ = "Miguel Angel Sanchez Muñoz <i52samum@uco.es>"
__date__ = "01 de julio 2010"
__version__ = "$ Revision: 1 $"
__credits__ = """Universidad de Cordoba"""


import string
import nltk
from nltk.corpus.reader import CategorizedPlaintextCorpusReader

# creacion de un corpus de documentos categorizados tematicamente
parrafos_txt = CategorizedPlaintextCorpusReader('corpus/categorias','.*\.txt',cat_pattern=r'(Cultura|Deportes|Economia|Sucesos|Tecnologia)/.*')

########## procesamiento del texto ##########
def procesar_texto(palabras):
	'''Filtra las palabras con menos de tres letras, elimina los digitos y
	las pasa a minuscula
		@param palabras: Lista de palabras 
		
		@return: Lista de las palabras filtradas
	'''
	lista = []
	palabras_aux = []
	
	# se filtran palabras cortas y digitos
	for i in palabras:
		if len(i) > 3 and not i.isdigit():
			lista.append(i)
	
	# se pone todo en minusculas
	for i in lista:
		palabras_aux.append(i.lower())
	
	return palabras_aux

########## seleccion de las caracteristicas optimas ##########
def seleccion_caracteristicas():
	'''Construye el vector de caracteristicas que se usara mas tarde en el
	metodo de la poda 
		
		@return: Devuelve un diccionario con las palabras optimas, junto con
		la frecuencia de aparicion de las mismas en cada una de las categorias
		del conjunto de entrenamiento
	'''
	frecuencias = dict()
	lista_gen = []
	lista_cul_aux = []
	lista_dep_aux = []
	lista_eco_aux = []
	lista_suc_aux = []
	lista_tec_aux = []

	# se crean las listas con las palabras de los textos de cada categoria
	for category in parrafos_txt.categories():
		for fileid in parrafos_txt.fileids(category):
			if category == "Cultura":
				lista_cul_aux += list(parrafos_txt.words(fileid))
			elif category == "Deportes":
				lista_dep_aux += list(parrafos_txt.words(fileid))
			elif category == "Economia":
				lista_eco_aux += list(parrafos_txt.words(fileid))
			elif category == "Sucesos":
				lista_suc_aux += list(parrafos_txt.words(fileid))
			elif category == "Tecnologia":
				lista_tec_aux += list(parrafos_txt.words(fileid))
	
	# se obtiene la lista con todas las palabras del corpus
	lista_gen_aux = procesar_texto(list(parrafos_txt.words()))
	for i in lista_gen_aux:
		if (i in lista_gen_aux) and (i not in lista_gen):
			lista_gen.append(i)
	
	# se procesan las listas con las palabras
	lista_cul = procesar_texto(lista_cul_aux)
	lista_dep = procesar_texto(lista_dep_aux)
	lista_eco = procesar_texto(lista_eco_aux)
	lista_suc = procesar_texto(lista_suc_aux)
	lista_tec = procesar_texto(lista_tec_aux)

	# se obtiene la frecuencia de aparicion de las palabras por categorias
	freq_cul = nltk.FreqDist(lista_cul)
	freq_dep = nltk.FreqDist(lista_dep)
	freq_eco = nltk.FreqDist(lista_eco)
	freq_suc = nltk.FreqDist(lista_suc)
	freq_tec = nltk.FreqDist(lista_tec)
	
	# se obtiene el diccionario con las palabras y la frecuencia de cada categoria
	for i in lista_gen:
		lista_aux = dict()
		lista_aux['cultura'] = freq_cul[i] if i in freq_cul else 0
		lista_aux['deportes'] = freq_dep[i] if i in freq_dep else 0
		lista_aux['economia'] = freq_eco[i] if i in freq_eco else 0
		lista_aux['sucesos'] = freq_suc[i] if i in freq_suc else 0
		lista_aux['tecnologia'] = freq_tec[i] if i in freq_tec else 0
		frecuencias[i] = lista_aux
	
	return frecuencias

########## metodo de clasificacion por el metodo de la poda ##########
def clasificacion_poda(texto):
	'''Clasifica el texto por el metodo de la poda y devuelve la seccion
	a la que pertenece
		@param texto: Texto a clasificar 
		
		@return: Seccion a la que pertenece el texto
	'''
	palabras = []
	lista = []
	
	# clases candidatas iniciales
	clases_candidatas = []
	for i in parrafos_txt.categories():
		clases_candidatas.append(i.lower())
	candidatas = clases_candidatas[:]
	
	# se obtienen las palabras y sus frecuencias en cada categoria
	palabras_freq = seleccion_caracteristicas()
	
	# se seleccionan todas las palabras de los textos y se ponen en una lista
	palabras = texto.split()
	
	# filtro para palabras repetidas y con menos de tres letras
	for i in palabras:
		if (i not in lista) and (len(i) > 3):
			cad_aux = i.lower()
			for i in string.punctuation:
				if i in cad_aux:
					cad_aux = cad_aux.replace(i,'')
			lista.append(cad_aux)
	
	for i in lista:
		if i in palabras_freq:
			for j in palabras_freq[i]:
				if palabras_freq[i][j] == 0:
					if j in candidatas:
						candidatas.remove(j)
	
	if candidatas == []: 
		candidatas = ['Seccion no identificada']
	return candidatas

def evaluar():
	'''Calcula y muestra la precision del clasificador para el metodo de
	la poda 
		
		@return: Precision del clasificador en tanto por ciento
	'''
	correct = 0
	test = 0
	corpus = parrafos_txt

	for categoria in corpus.categories():
		for fileid in corpus.fileids(categoria):
			if categoria in corpus.categories():
				correct += 1
			test += 1
	return (correct/test)*100

