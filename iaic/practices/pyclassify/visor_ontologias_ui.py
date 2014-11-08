#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: visor_ontologias_ui.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo contiene la interfaz de la ventana del visor de ontologias
y la gestion de eventos de la misma.
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

from visor_ontologias import Ui_visor_ontologias_form
import ckControlador

# Clase de la ventana Acerca de, gestiona los eventos de la interfaz
class VisorOntologiasWidget(QtGui.QWidget):
	
	def abrir_ontologia(self):
		'''Carga en la interfaz la ontologia almacenada en la URL que haya \
		actualmente en la interfaz
		
			@return: Nada
		'''
		# Obtenemos la lista de documentos
		ontologia = ckControlador.event_OpenOntologie(ontoName=self.ui.url_lineEdit.text())
		for documento in ontologia:
			self.ui.articulo_list.addItem(documento)
			
	def mostrar_documento(self):
		'''Carga en la interfaz el documento seleccionado de la lista de documentos \
		de la ontologia
		
			@return: Nada
		'''
		# Obtenemos el cuerpo del documento desde la ontologia
		documento = ckControlador.event_GetBodyTextOntologie(
				ontoName=str(self.ui.url_lineEdit.text()),
				subject=str((self.ui.articulo_list.currentItem()).text()))
				
		# Mostramos texto del articulo en el textBrowser
		self.ui.textos_textBrowser.setText(documento)
	
	def __init__(self, parent=None):
		'''Muestra la ventana de acerca de

				@return: Nada
		'''
		QtGui.QWidget.__init__(self, parent)
		self.ui = Ui_visor_ontologias_form()
		self.ui.setupUi(self)
		# Ponemos por defecto la direccion web de la ontologia
		self.ui.url_lineEdit.setText("http://www.uco.es/~i62pemar/clasificador_textos.owl")
		
		# Gestion de eventos

		# Si se el boton abrir, cargamos la ontologia con la URL que haya en la interfaz
		self.connect(self.ui.abrir_pushButton, QtCore.SIGNAL("clicked()"),self.abrir_ontologia)
		# Si se selecciona un articulo, ejecutamos la funcion mostrar_articulo
		self.connect(self.ui.articulo_list, QtCore.SIGNAL("itemSelectionChanged()"), self.mostrar_documento)

