#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: main.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo implementa la ventana principal de la interfaz de usuario y 
gestion de eventos de la misma.
"""


__author__ = "Manuel Pedrero Luque <i62pelum@uco.es>"
__author__ = "Raul Perula Martinez <i62pemar@uco.es>"
__author__ = "Miguel Angel Sanchez Muñoz <i52samum@uco.es>"
__date__ = "01 de julio 2010"
__version__ = "$ Revision: 1 $"
__credits__ = """Universidad de Cordoba"""


import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtGui import *

from mainwindow import Ui_MainWindow
from acerca_de_ui import AcercaDeWidget
from visor_ontologias_ui import VisorOntologiasWidget
from ayuda_ui import AyudaWidget
import ckModeloAp
import ckControlador
import poda

# Clase principal del formulario, gestiona los eventos de la interfaz
class MyForm(QtGui.QMainWindow):
	
	def cargar_secciones(self):
		'''Carga las secciones de los articulos que se van a clasificar

			@return: Nada
		'''
		# obtiene las lista de categorias
		categories = ckModeloAp.getCategories()
		
		# inserta las categorias en la lista de documentos
		for categoria in categories:
			self.ui.seccion_list.addItem(categoria)
			
	def cargar_articulos(self):
		'''Carga los articulos del corpus de la categoria seleccionada \
		y los muestra en el widget de la interfaz

			@return: Nada
		'''
		# Obtenemos la categoria actualmente seleccionada
		categoria = self.ui.seccion_list.currentItem()
		# Obtenemos la lista de los articulos que forman parte de la categoria
		lista_articulos = ckModeloAp.getDocsFromCategories(categories=str(categoria.text()))
		# Borramos el contenido de la lista actual
		self.ui.articulo_list.clear()
		# Mostramos los articulos en articulo_list
		for articulo in lista_articulos:
			self.ui.articulo_list.addItem(articulo)
	
	def mostrar_articulo(self):
		'''Muestra en articulo seleccionado en el visor de documentos de la interfaz

			@return: Nada
		'''
		# Obtenemos la ruta del articulo actualmente seleccionado
		articulo = self.ui.articulo_list.currentItem()
		# Obtenemos el texto del articulo seleccionado
		texto_articulo = ckModeloAp.getTextFromDoc(fileids=str(articulo.text()))
		# Mostramos texto del articulo en el textBrowser
		self.ui.textos_textBrowser.setText(texto_articulo)
		
	def entrenar(self):
		'''Entrena el conjunto de entrenamiento en el caso de que se haya seleccionado \
		el clasificador bayesiano. Habilita los botones de clasificar y evaluar.

			@return: Nada
		'''
		# Obtenemos el numero de propiedades que vamos a utilizar para entrenar
		num_propiedades = self.ui.nprop_opc_spinBox.value()
		
		# Obtenemos el clasificador que vamos a utilizar
		# poda: Clasificador mediante reglasEconomia/35.txt
		# bayes: Clasificador bayesiano
		# ninguno: No se ha seleccionado ningun clasificador
		if(self.ui.poda_radioButton.isChecked() == True):
			clasificador = 'poda'
		elif(self.ui.bayes_radioButton.isChecked() == True):
			clasificador = 'bayes'
		else:
			clasificador = 'ninguno'
		
		# Obtener el porcentaje de muestras de entrenamiento	
		porc_entrenamiento = self.ui.porc_entr_spinBox.value()
		
		# Llamamos a la funcion de entrenamiento del modelo de aplicacion
		global res_clasificador
		res_clasificador = ckModeloAp.trainClassifier_Task(corpusName=ckModeloAp.parrafos_txt,
				nWords=num_propiedades,
				modelClassify=clasificador,
				percentTrain=porc_entrenamiento)
																						
		# Mostramos la precision en la interfaz grafica
		self.ui.precision_opc_lineEdit.setText(str(round(res_clasificador[1],3)))
		
		# Habilitamos el boton de clasificar
		self.ui.clasificar_pushButton.setEnabled(True)
		# Habilitamos el boton de evaluar
		self.ui.evaluar_pushButton.setEnabled(True)
		
		
	def clasificar(self):
		'''Clasifica el documento que haya cargado en ese momento en el visor de \
		documentos en una de las categorias, utilizando el metodo especificado \
		en las opciones.
		
			@return: Nada
		'''
		# Obtenemos el texto del widget correspondiente
		doc_articulo = self.ui.textos_textBrowser.document()
		texto_articulo = str(doc_articulo.toPlainText())
		# Clasificacion por el metodo de la poda
		if self.ui.poda_radioButton.isChecked() == True:
			resultado = (poda.clasificacion_poda(texto_articulo))[0]
			
		else:
			# Clasificamos por el metodo de bayes
			
			# Obtenemos lista de palabras mas frecuentes
			palabras_frecuentes = ckModeloAp.getWordFeatures(corpusName=ckModeloAp.parrafos_txt,nWords=100)
			
			# Extraemos las propiedades del texto
			lista_propiedades = ckControlador.event_ExtractPropertiesFromText(
					text=texto_articulo,
					word_features=palabras_frecuentes)
			
			# Mostramos las propiedades extraidas
			self.ui.propiedades_list.clear()
			for propiedad in lista_propiedades:
				self.ui.propiedades_list.addItem(propiedad)
			
			# Aqui comenzaria el proceso de clasificacion propiamente dicho
			
			# Se obtienen las caracteristicas del articulo
			caracteristicas_texto = ckModeloAp.document_features(texto_articulo.split(),palabras_frecuentes)

			# Se clasifica el articulo, devolviendo una de las secciones del periodico
			#~ self.frmTextProperties.entryResultClass.setvalue(classifier.classify(p))
			resultado = res_clasificador[0].classify(caracteristicas_texto)
		
		# Se lanza un QMessageBox con la seccion que se ha obtenido resultado de la clasificacion
		resultado = resultado.capitalize()
		print resultado
		
		QMessageBox.information(self,
				"Resultado",
				resultado)
				
	def evaluar(self):
		'''Evalua la precision del clasificador
		
			@return: Nada
		'''
		if(self.ui.poda_radioButton.isChecked() == True):
			QMessageBox.information(self,
				QtCore.QString("Prec. del clasificador"),
				QtCore.QString(str(poda.evaluar())+' %'))
		else:
			QMessageBox.information(self,
				QtCore.QString("Prec. del clasificador"),
				QtCore.QString(str(100*float(self.ui.precision_opc_lineEdit.text()))+' %'))

	def menu_acerca_de(self):
		'''Muestra la ventana Acerca de

			@return: Nada
		'''
		acercade = AcercaDeWidget()
		acercade.show()
		sys.exit(acercade.exec_())
		
	def menu_ver_ontologia(self):
		'''Muestra la ventana con la interfaz que permite leer una ontologia desde Internet

			@return: Nada
		'''
		ver_ontologia = VisorOntologiasWidget()
		ver_ontologia.show()
		sys.exit(ver_ontologia.exec_())
		
	def menu_ayuda(self):
		'''Muestra la ventana con la interfaz que muestra la ayuda del programa

			@return: Nada
		'''
		ver_ayuda = AyudaWidget()
		ver_ayuda.show()
		sys.exit(ver_ayuda.exec_())
		
	def poda_activo(self):
		'''Habilita y deshabilita los widgets necesarios para el metodo de la \
		poda cuando se activa la opcion correspondiente

			@return: Nada
		'''
		self.ui.entrenar_pushButton.setEnabled(False)
		self.ui.clasificar_pushButton.setEnabled(True)
		self.ui.evaluar_pushButton.setEnabled(True)
		self.ui.nprop_opc_spinBox.setEnabled(False)
		self.ui.porc_entr_spinBox.setEnabled(False)
		self.ui.precision_opc_lineEdit.setText("1")
		self.ui.propiedades_list.clear()

	def bayes_activo(self):
		'''Habilita y deshabilita los widgets necesarios para el metodo de \
		bayes cuando se activa la opcion correspondiente

			@return: Nada
		'''
		self.ui.entrenar_pushButton.setEnabled(True)
		self.ui.clasificar_pushButton.setEnabled(False)
		self.ui.evaluar_pushButton.setEnabled(False)
		self.ui.nprop_opc_spinBox.setEnabled(True)
		self.ui.porc_entr_spinBox.setEnabled(True)
		self.ui.precision_opc_lineEdit.setText("")

		
	def __init__(self, parent=None):
		'''Muestra la ventana principal y recoge los eventos de la misma

			@return: Nada
		'''
		QtGui.QWidget.__init__(self, parent)
		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)
		# Cargamos las secciones de nuestro corpus
		self.cargar_secciones()
		# Obtenemos lista de palabras mas frecuentes
		palabras_frecuentes = ckModeloAp.getWordFeatures(corpusName=ckModeloAp.parrafos_txt,nWords=100)
		# Mostramos la lista en la interfaz grafica
		self.ui.palabras_list.clear()
		for palabra in palabras_frecuentes:
			self.ui.palabras_list.addItem(palabra)
		
		# Gestion de eventos
		
		# Si se selecciona un articulo, ejecutamos la funcion mostrar_articulo
		self.connect(self.ui.articulo_list, QtCore.SIGNAL("itemSelectionChanged()"), self.mostrar_articulo)
		# Si se selecciona una categoria, ejecutamos la funcion cargar_articulos
		self.connect(self.ui.seccion_list, QtCore.SIGNAL("itemSelectionChanged()"), self.cargar_articulos)
		# Si se pulsa el boton entrenar, se realiza el entrenamiento y se desactiva el boton
		self.connect(self.ui.entrenar_pushButton, QtCore.SIGNAL("clicked()"), self.entrenar)
		# Si se pulsa el boton clasificar, intentamos clasificar el texto actual en una de las secciones del periodico
		self.connect(self.ui.clasificar_pushButton, QtCore.SIGNAL("clicked()"), self.clasificar)
		# Si se pulsa la opcion Acerca de, se mostrara la ventana correspondiente
		self.connect(self.ui.actionAcerca_de, QtCore.SIGNAL("activated()"),self.menu_acerca_de)
		# Si se pulsa la opcion ver documentos de una ontologia, se muestra la ventana correspondiente
		self.connect(self.ui.actionVer_documentos_de_una_ontolog_a, QtCore.SIGNAL("activated()"),self.menu_ver_ontologia)
		# Si se pulsa la opcion Indice, se muestra la ventana de ayuda
		self.connect(self.ui.action_ndice, QtCore.SIGNAL("activated()"),self.menu_ayuda)
		# Si se pulsa el boton evaluar, se muestra el valor de la precision del clasificador seleccionado
		self.connect(self.ui.evaluar_pushButton, QtCore.SIGNAL("clicked()"),self.evaluar)
		# Si se pulsa la opcion de poda, quitamos entrenar y activamos clasificar y evaluar
		self.connect(self.ui.poda_radioButton, QtCore.SIGNAL("clicked()"),self.poda_activo)
		# Si se pulsa la opcion de bayes, habilitamos entrenar y desactivamos clasificar y evaluar
		self.connect(self.ui.bayes_radioButton, QtCore.SIGNAL("clicked()"),self.bayes_activo)

			
if __name__ == "__main__":
	app = QtGui.QApplication(sys.argv)
	myapp = MyForm()
	myapp.show()
	sys.exit(app.exec_())
