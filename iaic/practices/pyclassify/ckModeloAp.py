#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: ckModeloAp.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo contiene todos los objetos del modelo de aplicacion
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
from lxml import etree
from rdflib import Graph
from rdflib.Graph import ConjunctiveGraph
import nltk
from nltk.corpus.reader import CategorizedPlaintextCorpusReader
from nltk.tokenize import RegexpTokenizer


#===============================================================================
# GESTIÓN DE ONTOLOGÍAS
#===============================================================================
prefijo = '''
					PREFIX owl: <http://www.w3.org/2002/07/owl##>
					PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
					PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#/>
					PREFIX instextos: <http://www.IAIC.com/ontologies/clasificador_textos.owl#>
					'''


##############################
# consulta para obtener todos los sujetos de los textos
##############################
def getSubjects(source='http://www.uco.es/~i62pemar/clasificador_textos.owl'):
	'''Devuelve los ids de los textos de la ontologia web que se le pasa como parametro. 
	Utiliza SparQL para realizar las consultas a la ontologia.

		 @param source: Direccion web de la ontologia.

		 @return: Devuelve una lista con los identificadores de los articulos de la ontologia.
	'''

	store = Graph()
	store.parse('http://www.uco.es/~i62pemar/clasificador_textos.owl')
	
	test_query =	"""
								SELECT   ?s
								WHERE { ?s instextos:Texto ?o }
								"""

	test_query = prefijo + test_query
	results = store.query(test_query)
	root = etree.fromstring(results.serialize(format='xml'))

	# se obtienen todos los resultados de la consulta
	results = root.xpath("//sparql:result",
											namespaces={'sparql': 'http://www.w3.org/2005/sparql-results#',
											'instextos': 'http://www.IAIC.com/ontologies/clasificador_textos.owl#'})

	# lista de tuplas con los cuerpos de los correos.
	subjects = []

	# para cada resultado
	for result in  results:
		# se obtiene el sujeto
		s = result.xpath("sparql:binding[@name='s']/sparql:uri",
										namespaces={'sparql': 'http://www.w3.org/2005/sparql-results#',
										'instextos': 'http://www.IAIC.com/ontologies/clasificador_textos.owl#'})

		subjects.append(s[0].text.split('#')[1])

	return subjects


##############################
#	Obtener cuerpos de los documentos
##############################
def getBody(source='http://www.uco.es/~i62pemar/clasificador_textos.owl',subject='1'):
	'''Devuelve el cuerpo de un documento de la ontologia dada la direccion web de la misma y 
	la id del texto correspondiente.

		 @param source: Direccion web de la ontologia.
		 @param subject: Id del texto que se quiere cargar

		 @return: Devuelve el cuerpo del documento correspondiente.
	'''
	store = Graph()
	store.parse(source)

	test_query = ' SELECT   ?o   WHERE { instextos:'+subject+' instextos:Texto ?o }'

	test_query = prefijo + test_query

	results = store.query(test_query)

	root = etree.fromstring(results.serialize(format='xml'))

	# se obtienen todos los resultados de la consulta
	results = root.xpath("//sparql:result",
											namespaces={'sparql': 'http://www.w3.org/2005/sparql-results#',
											'instextos': 'http://www.IAIC.com/ontologies/clasificador_textos.owl#'})

	bodies = []
	for result in  results:
		# se obtiene el objeto
		s = result.xpath("sparql:binding[@name='o']/sparql:literal",
										namespaces={'sparql': 'http://www.w3.org/2005/sparql-results#',
										'instextos': 'http://www.IAIC.com/ontologies/clasificador_textos.owl#'})

		bodies.append(s[0].text)

	return bodies[0]

#===============================================================================
# GESTIÓN DEL CORPUS
#===============================================================================

# creacion de un corpus de documentos categorizados tematicamente
parrafos_txt = CategorizedPlaintextCorpusReader('corpus/categorias','.*\.txt',
			cat_pattern=r'(Cultura|Deportes|Economia|Sociedad|Sucesos|Tecnologia)/.*')

#===============================================================================
# INFERENCIAS
#===============================================================================

##############################
# caracteristicas de los documentos, utilizada
##############################
def document_features(document_words,word_features):
	'''Dado el conjunto de palabras de un documento, obtiene las propiedades asociadas
		 a ese documento. La propiedad a usar es si la palabra del conjunto de palabras
		 se encuentra en el documento.

		 @param document_words: Texto del documento en palabras o tokens.
		 @param word_features: Lista de palabras que se usaran para obtener las propiedades

		 @return: Devuelve un dicccionario, donde cada palabra del diccionario
							representa la propiedad y su valor.
	'''
	# diccionario de propiedades.
	features = {}

	# para cada caracteristica (palabra) en la lista de caracteristicas (palabras)
	for word in word_features:
		# se obtine el valor de la caracteristica
		features['contains(%s)' % word] = (word.lower() in document_words)
		
	# devuelve las caracteristicas del documento
	return features


##############################
# obtener categorias, utilizada
##############################
def getCategories(corpusName=parrafos_txt):
	'''Obtiene las categorias de un corpus.

		 @param corpusName: Instancia del corpus

		 @return: Lista de las categorias del corpus
	'''
	
	return corpusName.categories()


##############################
# obtener documentos de una categoria, utilizada
##############################
def getDocsFromCategories(corpusName=parrafos_txt, categories=[]):
	'''Obtiene los documentos de una lista de categorias de un corpus.

		 @param corpusName: Instancia del corpus.
		 @param categories: Lista de categorias del corpus.

		 @return: Lista de documentos de esas categorias
	'''
	return  corpusName.fileids(categories=categories)


##############################
# obtener texto de los documentos, utilizada
##############################
def getTextFromDoc(corpusName=parrafos_txt,fileids=''):
	'''Obtiene el texto de un documento de un corpus.

		 @param corpusName: Instancia del corpus.
		 @param fileids: Identificacion del documento.

		 @return: Texto del documento
	'''
	text = corpusName.raw(fileids=fileids)

	return text


##############################
# obtener lista palabras de un corpus categorizado
##############################
def getDocumentsLabeled(corpusName=parrafos_txt):
	'''Obtiene una lista de las palabras de cada documento de los documentos de un corpus categorizado
		 con su categoria asignada.

		 @param corpusName: Nombre del corpus categorizado.

		 @return: Devuelve una lista de tuplas, donde cada tupla
							representa una lista de las palabras de un documento y su categoria.
	'''
	documents = [(list(corpusName.words(fileid)),category)
							for category in corpusName.categories()
							for fileid in corpusName.fileids(category)]

	return documents


##############################
# obtener lista propiedades de documentos
##############################
def getFeaturesSets(word_features,word_documents_categorized):
	'''Obtiene el conjunto de propiedades de un conjunto de documentos junto
		 con su categoria asignada.

		 @param word_features: Palabras que se usaran de propiedades o caracteristicas
		 @param word_documents_categorized: Palabras de cada documento junto con su categoria

		 @return: Devuelve una lista de tuplas. Cada tupla contiene por un lado una lista
							de propiedades y sus valores correspondientes y por otro
							la categoria de esa lista de palabras.
	'''
	featuresets = [(document_features(d,word_features), c) for (d,c) in word_documents_categorized]
	
	return featuresets


##############################
# obtener conjunto caracteristicas de un crpus categorizado
##############################
def getFeaturesSetsFromCategorizedCorpus(corpusName='parrafos_txt',nWords=10):
	'''Obtiene un conjunto de propiedades de los documentos de un corpus de texto
		 categorizado para construir un clasificador.

		 @param corpusName: Instancia del corpus
		 @param nWords: Numero de palabras mas frecuentes a considerar

		 @return featuresets: Matriz de caracteristicas
	'''
	word_documents_categorized = getDocumentsLabeled(corpusName=corpusName)

	# obtiene las palabras mas frecuentes que se usaran para clasificar el texto
	word_features = getWordFeatures(corpusName=parrafos_txt,nWords=nWords)

	# obtiene el conjunto de caracteristicas y su categoria asociadada a un conjunto de documentos
	featuresets = getFeaturesSets(word_features=word_features,word_documents_categorized=word_documents_categorized)

	return featuresets


##############################
# obtener palabras mas frecuentes de un corpus, utilizada
##############################
def getWordFeatures(corpusName,nWords=10):
	'''Dado un corpus obtiene las nWords palabras mas frecuentes de ese Corpus que se usaran como caracteristicas.

		 @param nameCorpus: Nombre del corpus.
		 @param nWords: Numero maximo de palabras que se usaran para obtener propiedades.

		 @return: Devuelve una lista de tuplas, donde cada tupla
							representa la propiedad y su valor.
	'''
	parrafos2 = []
	for i in corpusName.words():
		if len(i) > 3 and not i.isdigit():
			parrafos2.append(i.lower())

	all_words = nltk.FreqDist(parrafos2)

	if nWords > len(all_words):
		nWords = len(all_words)

	word_features = all_words.keys()[:nWords]

	return word_features


##############################
# obtener caracteristicas de un parrafo
##############################
def paragraph_features_w(paragraph,word_features):
	'''Obtiene las propiedades de un parrafo, indicando si una palabra esta
		 en el mismo.
	'''
	tokenizer = RegexpTokenizer('\w+|\$[\d\.]+|\S+')
	words = tokenizer.tokenize(paragraph)
	paragraph_words = set(words)

	features = {}
	for word in word_features:
		features['contains(%s)' % word] = (word in paragraph_words)

	return features


#===============================================================================
# TAREAS
#===============================================================================

##############################
# clasificador con opcion de entrenamiento, utilizado
##############################
def trainClassifier_Task(corpusName=parrafos_txt,nWords=100,modelClassify='bayes',percentTrain=80):
	'''Clasificador Bayesiano que utiliza las palabras mas frecuentes del corpus 
	como conjunto de entrenamiento.

		 @param corpusName: Nombre del corpus utilizado.
		 @param nWords: Numero de propiedades que se van a utilizar.
		 @param modelClassify: Nombre del modelo del clasificador.
		 @param percentTrain: Porcentaje del conjunto de entrenamiento.

		 @return: Devuelve el resultado de la clasificacion y la precision del clasificador
		 para el conjunto de entrenamiento dado.
	'''
	# construccion de un clasificador tomando las nWords mas frecuentes como propiedades incluidas

	# 1.- Obtencion de la matriz de caracteristicas de los documentos
	featuresets = getFeaturesSetsFromCategorizedCorpus(corpusName=corpusName,nWords=nWords)

	# 2.- Defincion del conjunto de entrenamiento y conjunto test
	nTrain = int((float(percentTrain)/100)*len(featuresets))
	nTest = len(featuresets)-nTrain
	train_set, test_set = featuresets[0:nTrain], featuresets[nTrain:]

	# 3.- Obtencion del clasificador
	if modelClassify == 'bayes':
		classifier = nltk.NaiveBayesClassifier.train(train_set)
	elif modelClassify == 'poda':
		classifier = nltk.DecisionTreeClassifier.train(train_set)

	# 4.- Precision del clasificador
	accuracy = nltk.classify.accuracy(classifier, train_set)

	return (classifier,accuracy)
