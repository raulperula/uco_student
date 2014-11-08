#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: ckControlador.py

"""
Arquitectura de referencia en commonKads.
Controlador.
Este modulo contiene todos los objetos del controlador
en la arquitectura MVC (Modelo Vista Controlador) de la arquitectura
de referencia de CommonKads.
"""


__author__ = "Manuel Pedrero Luque <i62pelum@uco.es>"
__author__ = "Raul Perula Martinez <i62pemar@uco.es>"
__author__ = "Miguel Angel Sanchez Muñoz <i52samum@uco.es>"
__date__ = "01 de julio 2010"
__version__ = "$ Revision: 1 $"
__credits__ = """Universidad de Cordoba"""


import codecs
import types, sets
import ckModeloAp

##############################
# evneto para abrir una ontologia
##############################
def event_OpenOntologie(ontoName):
	'''
	Gestor de eventos basico para el reconocimiento de articulos. Abre la ontologia de articulos.
	'''
	lt = ckModeloAp.getSubjects(source=ontoName)
	return lt


##############################
# evento para obtener texto de una ontologia
##############################
def event_GetBodyTextOntologie(ontoName,subject):
	'''
	Gestor de eventos basico para el reconocimiento de articulos. Obtiene el texto de una ontologia.
	'''
	lt = ckModeloAp.getBody(source=ontoName,subject=subject)
	return lt


##############################
# evento para extraer las propiedades de un texto, utilizado
##############################
def event_ExtractPropertiesFromText(text,word_features):
	'''
	Gestor de eventos basico para el reconocimiento de articulos. Extrae las propiedades de un texto.
	'''
	features = ckModeloAp.paragraph_features_w(paragraph=text,word_features=word_features)
	lf = []

	for p in features.keys():
		el = p+' = '+ str(features[p])
		lf.append(el)

	return lf


##############################
# evento para entrenar el clasificador
##############################
def event_TrainClassifier(corpusName,nWords,modelClassify,percentTrain):
	'''
	Gestor de eventos basico para el reconocimiento de articulos. Entrena el clasificador.
	'''
	cl = ckModeloAp.trainClassifier_Task(corpusName=corpusName,
			nWords=nWords,
			modelClassify=modelClassify,
			percentTrain=percentTrain)
	return cl
	
