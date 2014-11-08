#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Form implementation generated from reading ui file 'des_acerca_de.ui'
#
# Created: Tue Jul  6 17:16:09 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_acerca_de_form(object):
    def setupUi(self, acerca_de_form):
        acerca_de_form.setObjectName("acerca_de_form")
        acerca_de_form.setWindowModality(QtCore.Qt.ApplicationModal)
        acerca_de_form.resize(653, 277)
        acerca_de_form.setMinimumSize(QtCore.QSize(653, 277))
        acerca_de_form.setMaximumSize(QtCore.QSize(653, 277))
        self.textEdit = QtGui.QTextEdit(acerca_de_form)
        self.textEdit.setGeometry(QtCore.QRect(200, 10, 445, 221))
        self.textEdit.setObjectName("textEdit")
        self.cerrar_pushButton = QtGui.QPushButton(acerca_de_form)
        self.cerrar_pushButton.setGeometry(QtCore.QRect(560, 240, 85, 27))
        self.cerrar_pushButton.setObjectName("cerrar_pushButton")
        self.uco_label = QtGui.QLabel(acerca_de_form)
        self.uco_label.setGeometry(QtCore.QRect(11, 11, 179, 107))
        self.uco_label.setText("")
        self.uco_label.setPixmap(QtGui.QPixmap("imgs/uco_logo.png"))
        self.uco_label.setScaledContents(True)
        self.uco_label.setObjectName("uco_label")
        self.eps_label = QtGui.QLabel(acerca_de_form)
        self.eps_label.setGeometry(QtCore.QRect(11, 124, 179, 106))
        self.eps_label.setText("")
        self.eps_label.setPixmap(QtGui.QPixmap("imgs/eps_logo.png"))
        self.eps_label.setScaledContents(False)
        self.eps_label.setAlignment(QtCore.Qt.AlignCenter)
        self.eps_label.setObjectName("eps_label")

        self.retranslateUi(acerca_de_form)
        QtCore.QMetaObject.connectSlotsByName(acerca_de_form)

    def retranslateUi(self, acerca_de_form):
        acerca_de_form.setWindowTitle(QtGui.QApplication.translate("acerca_de_form", "Acerca de PyClassifier", None, QtGui.QApplication.UnicodeUTF8))
        self.textEdit.setHtml(QtGui.QApplication.translate("acerca_de_form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Clasificador de artículos periodísticos escrito en Python utilizando las librerias nltk, lxml y pyqt.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">                </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Trabajo realizado por:</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Manuel Pedrero Luque</span><span style=\" font-size:10pt;\">     </span><a href=\"mailto:i62pelum@uco.es\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">i62pelum@uco.es</span></a></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Raúl Pérula Martínez        </span><a href=\"mailto:i62pemar@uco.es\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">i62pemar@uco.es</span></a></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">M. Ángel Sánchez Muñoz    </span><a href=\"mailto:i52samum.uco.es\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">i52samum@uco.es</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">                </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Inteligencia Artificial e Ingeniería del Conocimiento, Julio 2010</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Universidad de Córdoba - Escuela Politécnica Superior</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cerrar_pushButton.setText(QtGui.QApplication.translate("acerca_de_form", "Cerrar", None, QtGui.QApplication.UnicodeUTF8))

