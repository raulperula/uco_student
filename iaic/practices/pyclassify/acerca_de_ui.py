#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# File: acerca_de_ui.py

"""
Arquitectura de referencia en commonKads.
Modelo de la Aplicacion.
Este modulo contiene la interfaz de la ventana "Acerca de" de la
aplicacion y la gestion de eventos de la misma.
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

from acerca_de import Ui_acerca_de_form

# Clase de la ventana Acerca de, gestiona los eventos de la interfaz
class AcercaDeWidget(QtGui.QWidget):
	
	def cerrar_ventana(self):
		'''Cierra la ventana cuando se pulse el boton correspondiente

			@return: Nada
		'''
		self.close()
	
	def __init__(self, parent=None):
		'''Muestra la ventana de Acerca de

			@return: Nada
		'''
		QtGui.QWidget.__init__(self, parent)
		self.ui = Ui_acerca_de_form()
		self.ui.setupUi(self)
		
		# Gestion de eventos
		# Si se pulsa el boton aceptar, se cierra la ventana
		self.connect(self.ui.cerrar_pushButton, QtCore.SIGNAL("clicked()"),self.cerrar_ventana)

