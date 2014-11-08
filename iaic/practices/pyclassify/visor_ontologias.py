#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Form implementation generated from reading ui file 'des_visor_ontologias.ui'
#
# Created: Tue Jul  6 17:57:56 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_visor_ontologias_form(object):
    def setupUi(self, visor_ontologias_form):
        visor_ontologias_form.setObjectName("visor_ontologias_form")
        visor_ontologias_form.setWindowModality(QtCore.Qt.ApplicationModal)
        visor_ontologias_form.resize(652, 400)
        visor_ontologias_form.setMinimumSize(QtCore.QSize(652, 400))
        visor_ontologias_form.setMaximumSize(QtCore.QSize(652, 400))
        self.textos_textBrowser = QtGui.QTextBrowser(visor_ontologias_form)
        self.textos_textBrowser.setGeometry(QtCore.QRect(170, 110, 471, 281))
        self.textos_textBrowser.setReadOnly(False)
        self.textos_textBrowser.setObjectName("textos_textBrowser")
        self.articulo_label = QtGui.QLabel(visor_ontologias_form)
        self.articulo_label.setGeometry(QtCore.QRect(10, 90, 131, 16))
        self.articulo_label.setObjectName("articulo_label")
        self.articulo_list = QtGui.QListWidget(visor_ontologias_form)
        self.articulo_list.setGeometry(QtCore.QRect(10, 110, 151, 281))
        self.articulo_list.setObjectName("articulo_list")
        self.textos_label = QtGui.QLabel(visor_ontologias_form)
        self.textos_label.setGeometry(QtCore.QRect(170, 90, 91, 16))
        self.textos_label.setObjectName("textos_label")
        self.url_lineEdit = QtGui.QLineEdit(visor_ontologias_form)
        self.url_lineEdit.setGeometry(QtCore.QRect(105, 22, 441, 24))
        self.url_lineEdit.setMinimumSize(QtCore.QSize(0, 24))
        self.url_lineEdit.setObjectName("url_lineEdit")
        self.url_label = QtGui.QLabel(visor_ontologias_form)
        self.url_label.setGeometry(QtCore.QRect(10, 20, 88, 24))
        self.url_label.setMinimumSize(QtCore.QSize(0, 24))
        self.url_label.setMaximumSize(QtCore.QSize(16777215, 24))
        self.url_label.setObjectName("url_label")
        self.abrir_pushButton = QtGui.QPushButton(visor_ontologias_form)
        self.abrir_pushButton.setGeometry(QtCore.QRect(555, 21, 85, 24))
        self.abrir_pushButton.setMinimumSize(QtCore.QSize(0, 24))
        self.abrir_pushButton.setMaximumSize(QtCore.QSize(16777215, 24))
        self.abrir_pushButton.setObjectName("abrir_pushButton")
        self.line = QtGui.QFrame(visor_ontologias_form)
        self.line.setGeometry(QtCore.QRect(10, 70, 631, 20))
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName("line")

        self.retranslateUi(visor_ontologias_form)
        QtCore.QMetaObject.connectSlotsByName(visor_ontologias_form)

    def retranslateUi(self, visor_ontologias_form):
        visor_ontologias_form.setWindowTitle(QtGui.QApplication.translate("visor_ontologias_form", "Visor de ontologías web", None, QtGui.QApplication.UnicodeUTF8))
        self.articulo_label.setText(QtGui.QApplication.translate("visor_ontologias_form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Artículo</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.textos_label.setText(QtGui.QApplication.translate("visor_ontologias_form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Visor de textos</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.url_label.setText(QtGui.QApplication.translate("visor_ontologias_form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">URL Ontología</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.abrir_pushButton.setText(QtGui.QApplication.translate("visor_ontologias_form", "Abrir", None, QtGui.QApplication.UnicodeUTF8))

