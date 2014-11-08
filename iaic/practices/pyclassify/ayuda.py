#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Form implementation generated from reading ui file 'forms_ui/ayuda.ui'
#
# Created: Mon Jul  5 23:30:27 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_ayuda_form(object):
    def setupUi(self, ayuda_form):
        ayuda_form.setObjectName("ayuda_form")
        ayuda_form.setWindowModality(QtCore.Qt.ApplicationModal)
        ayuda_form.resize(800, 600)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(ayuda_form.sizePolicy().hasHeightForWidth())
        ayuda_form.setSizePolicy(sizePolicy)
        ayuda_form.setMinimumSize(QtCore.QSize(640, 480))
        self.verticalLayout = QtGui.QVBoxLayout(ayuda_form)
        self.verticalLayout.setObjectName("verticalLayout")
        self.ayuda_textBrowser = QtGui.QTextBrowser(ayuda_form)
        self.ayuda_textBrowser.setContextMenuPolicy(QtCore.Qt.DefaultContextMenu)
        self.ayuda_textBrowser.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOn)
        self.ayuda_textBrowser.setAutoFormatting(QtGui.QTextEdit.AutoNone)
        self.ayuda_textBrowser.setSource(QtCore.QUrl("file:ayuda/index.html"))
        self.ayuda_textBrowser.setSearchPaths([])
        self.ayuda_textBrowser.setOpenExternalLinks(True)
        self.ayuda_textBrowser.setObjectName("ayuda_textBrowser")
        self.verticalLayout.addWidget(self.ayuda_textBrowser)

        self.retranslateUi(ayuda_form)
        QtCore.QMetaObject.connectSlotsByName(ayuda_form)

    def retranslateUi(self, ayuda_form):
        ayuda_form.setWindowTitle(QtGui.QApplication.translate("ayuda_form", "Ayuda PyClassify", None, QtGui.QApplication.UnicodeUTF8))
        self.ayuda_textBrowser.setHtml(QtGui.QApplication.translate("ayuda_form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))

