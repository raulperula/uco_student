#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Form implementation generated from reading ui file 'forms_ui/mainwindow_clasificador.ui'
#
# Created: Mon Jul  5 23:28:27 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.textos_textBrowser = QtGui.QTextBrowser(self.centralwidget)
        self.textos_textBrowser.setGeometry(QtCore.QRect(320, 30, 471, 281))
        self.textos_textBrowser.setReadOnly(False)
        self.textos_textBrowser.setObjectName("textos_textBrowser")
        self.textos_label = QtGui.QLabel(self.centralwidget)
        self.textos_label.setGeometry(QtCore.QRect(320, 10, 91, 16))
        self.textos_label.setObjectName("textos_label")
        self.entrenar_pushButton = QtGui.QPushButton(self.centralwidget)
        self.entrenar_pushButton.setGeometry(QtCore.QRect(710, 460, 85, 27))
        self.entrenar_pushButton.setObjectName("entrenar_pushButton")
        self.clasificar_pushButton = QtGui.QPushButton(self.centralwidget)
        self.clasificar_pushButton.setEnabled(False)
        self.clasificar_pushButton.setGeometry(QtCore.QRect(710, 490, 85, 27))
        self.clasificar_pushButton.setCheckable(False)
        self.clasificar_pushButton.setObjectName("clasificar_pushButton")
        self.seleccion_groupBox = QtGui.QGroupBox(self.centralwidget)
        self.seleccion_groupBox.setGeometry(QtCore.QRect(490, 480, 211, 71))
        self.seleccion_groupBox.setObjectName("seleccion_groupBox")
        self.poda_radioButton = QtGui.QRadioButton(self.seleccion_groupBox)
        self.poda_radioButton.setGeometry(QtCore.QRect(0, 20, 211, 19))
        self.poda_radioButton.setChecked(False)
        self.poda_radioButton.setObjectName("poda_radioButton")
        self.bayes_radioButton = QtGui.QRadioButton(self.seleccion_groupBox)
        self.bayes_radioButton.setGeometry(QtCore.QRect(0, 40, 211, 19))
        self.bayes_radioButton.setChecked(True)
        self.bayes_radioButton.setObjectName("bayes_radioButton")
        self.seccion_label = QtGui.QLabel(self.centralwidget)
        self.seccion_label.setGeometry(QtCore.QRect(10, 10, 131, 16))
        self.seccion_label.setObjectName("seccion_label")
        self.propiedades_label = QtGui.QLabel(self.centralwidget)
        self.propiedades_label.setGeometry(QtCore.QRect(10, 340, 151, 16))
        self.propiedades_label.setObjectName("propiedades_label")
        self.palabras_label = QtGui.QLabel(self.centralwidget)
        self.palabras_label.setGeometry(QtCore.QRect(250, 340, 161, 16))
        self.palabras_label.setObjectName("palabras_label")
        self.opciones_groupBox = QtGui.QGroupBox(self.centralwidget)
        self.opciones_groupBox.setGeometry(QtCore.QRect(490, 340, 241, 121))
        self.opciones_groupBox.setObjectName("opciones_groupBox")
        self.layoutWidget = QtGui.QWidget(self.opciones_groupBox)
        self.layoutWidget.setGeometry(QtCore.QRect(0, 21, 221, 86))
        self.layoutWidget.setObjectName("layoutWidget")
        self.gridLayout = QtGui.QGridLayout(self.layoutWidget)
        self.gridLayout.setObjectName("gridLayout")
        self.nprop_opc_label = QtGui.QLabel(self.layoutWidget)
        self.nprop_opc_label.setObjectName("nprop_opc_label")
        self.gridLayout.addWidget(self.nprop_opc_label, 0, 0, 1, 1)
        self.nprop_opc_spinBox = QtGui.QSpinBox(self.layoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.nprop_opc_spinBox.sizePolicy().hasHeightForWidth())
        self.nprop_opc_spinBox.setSizePolicy(sizePolicy)
        self.nprop_opc_spinBox.setMinimumSize(QtCore.QSize(50, 0))
        self.nprop_opc_spinBox.setMaximumSize(QtCore.QSize(50, 16777215))
        self.nprop_opc_spinBox.setMinimum(20)
        self.nprop_opc_spinBox.setObjectName("nprop_opc_spinBox")
        self.gridLayout.addWidget(self.nprop_opc_spinBox, 0, 1, 1, 1)
        self.porcentaje_opc_label = QtGui.QLabel(self.layoutWidget)
        self.porcentaje_opc_label.setObjectName("porcentaje_opc_label")
        self.gridLayout.addWidget(self.porcentaje_opc_label, 1, 0, 1, 1)
        self.precision_opc_label = QtGui.QLabel(self.layoutWidget)
        self.precision_opc_label.setObjectName("precision_opc_label")
        self.gridLayout.addWidget(self.precision_opc_label, 2, 0, 1, 1)
        self.precision_opc_lineEdit = QtGui.QLineEdit(self.layoutWidget)
        self.precision_opc_lineEdit.setEnabled(True)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.precision_opc_lineEdit.sizePolicy().hasHeightForWidth())
        self.precision_opc_lineEdit.setSizePolicy(sizePolicy)
        self.precision_opc_lineEdit.setMinimumSize(QtCore.QSize(50, 0))
        self.precision_opc_lineEdit.setMaximumSize(QtCore.QSize(50, 16777215))
        self.precision_opc_lineEdit.setAcceptDrops(True)
        self.precision_opc_lineEdit.setReadOnly(True)
        self.precision_opc_lineEdit.setObjectName("precision_opc_lineEdit")
        self.gridLayout.addWidget(self.precision_opc_lineEdit, 2, 1, 1, 1)
        self.porc_entr_spinBox = QtGui.QSpinBox(self.layoutWidget)
        self.porc_entr_spinBox.setMinimumSize(QtCore.QSize(50, 0))
        self.porc_entr_spinBox.setMaximumSize(QtCore.QSize(50, 16777215))
        self.porc_entr_spinBox.setMinimum(10)
        self.porc_entr_spinBox.setMaximum(80)
        self.porc_entr_spinBox.setSingleStep(5)
        self.porc_entr_spinBox.setProperty("value", 80)
        self.porc_entr_spinBox.setObjectName("porc_entr_spinBox")
        self.gridLayout.addWidget(self.porc_entr_spinBox, 1, 1, 1, 1)
        self.seccion_list = QtGui.QListWidget(self.centralwidget)
        self.seccion_list.setGeometry(QtCore.QRect(10, 30, 141, 281))
        self.seccion_list.setObjectName("seccion_list")
        self.articulo_list = QtGui.QListWidget(self.centralwidget)
        self.articulo_list.setGeometry(QtCore.QRect(160, 30, 151, 281))
        self.articulo_list.setObjectName("articulo_list")
        self.articulo_label = QtGui.QLabel(self.centralwidget)
        self.articulo_label.setGeometry(QtCore.QRect(160, 10, 131, 16))
        self.articulo_label.setObjectName("articulo_label")
        self.line = QtGui.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(10, 320, 781, 16))
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName("line")
        self.propiedades_list = QtGui.QListWidget(self.centralwidget)
        self.propiedades_list.setGeometry(QtCore.QRect(10, 360, 231, 191))
        self.propiedades_list.setObjectName("propiedades_list")
        self.palabras_list = QtGui.QListWidget(self.centralwidget)
        self.palabras_list.setGeometry(QtCore.QRect(250, 360, 231, 191))
        self.palabras_list.setObjectName("palabras_list")
        self.evaluar_pushButton = QtGui.QPushButton(self.centralwidget)
        self.evaluar_pushButton.setEnabled(False)
        self.evaluar_pushButton.setGeometry(QtCore.QRect(710, 520, 85, 27))
        self.evaluar_pushButton.setCheckable(False)
        self.evaluar_pushButton.setObjectName("evaluar_pushButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 19))
        self.menubar.setObjectName("menubar")
        self.menuDocumentos = QtGui.QMenu(self.menubar)
        self.menuDocumentos.setObjectName("menuDocumentos")
        self.menuAcerca_de = QtGui.QMenu(self.menubar)
        self.menuAcerca_de.setObjectName("menuAcerca_de")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionVer_documentos_de_una_ontolog_a = QtGui.QAction(MainWindow)
        self.actionVer_documentos_de_una_ontolog_a.setObjectName("actionVer_documentos_de_una_ontolog_a")
        self.actionVer_documentos_de_un_corpus_categorizado = QtGui.QAction(MainWindow)
        self.actionVer_documentos_de_un_corpus_categorizado.setObjectName("actionVer_documentos_de_un_corpus_categorizado")
        self.actionM_todo_de_la_poda = QtGui.QAction(MainWindow)
        self.actionM_todo_de_la_poda.setObjectName("actionM_todo_de_la_poda")
        self.actionRedes_bayesianas = QtGui.QAction(MainWindow)
        self.actionRedes_bayesianas.setObjectName("actionRedes_bayesianas")
        self.action_ndice = QtGui.QAction(MainWindow)
        self.action_ndice.setObjectName("action_ndice")
        self.actionAcerca_de = QtGui.QAction(MainWindow)
        self.actionAcerca_de.setObjectName("actionAcerca_de")
        self.actionEvaluaci_n_de_m_todos = QtGui.QAction(MainWindow)
        self.actionEvaluaci_n_de_m_todos.setObjectName("actionEvaluaci_n_de_m_todos")
        self.menuDocumentos.addAction(self.actionVer_documentos_de_una_ontolog_a)
        self.menuAcerca_de.addAction(self.action_ndice)
        self.menuAcerca_de.addAction(self.actionAcerca_de)
        self.menubar.addAction(self.menuDocumentos.menuAction())
        self.menubar.addAction(self.menuAcerca_de.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "Clasificador de artículos periodísticos", None, QtGui.QApplication.UnicodeUTF8))
        self.textos_label.setText(QtGui.QApplication.translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Visor de textos</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.entrenar_pushButton.setText(QtGui.QApplication.translate("MainWindow", "Entrenar", None, QtGui.QApplication.UnicodeUTF8))
        self.clasificar_pushButton.setText(QtGui.QApplication.translate("MainWindow", "Clasificar", None, QtGui.QApplication.UnicodeUTF8))
        self.seleccion_groupBox.setTitle(QtGui.QApplication.translate("MainWindow", "Selección del clasificador", None, QtGui.QApplication.UnicodeUTF8))
        self.poda_radioButton.setText(QtGui.QApplication.translate("MainWindow", "Método de la poda (reglas)", None, QtGui.QApplication.UnicodeUTF8))
        self.bayes_radioButton.setText(QtGui.QApplication.translate("MainWindow", "Redes bayesianas (aprendizaje)", None, QtGui.QApplication.UnicodeUTF8))
        self.seccion_label.setText(QtGui.QApplication.translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Sección</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.propiedades_label.setText(QtGui.QApplication.translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Propiedades del artículo</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.palabras_label.setText(QtGui.QApplication.translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Palabras más frecuentes</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.opciones_groupBox.setTitle(QtGui.QApplication.translate("MainWindow", "Opciones", None, QtGui.QApplication.UnicodeUTF8))
        self.nprop_opc_label.setText(QtGui.QApplication.translate("MainWindow", "Número de propiedades", None, QtGui.QApplication.UnicodeUTF8))
        self.porcentaje_opc_label.setText(QtGui.QApplication.translate("MainWindow", "Porcentaje entrenamiento", None, QtGui.QApplication.UnicodeUTF8))
        self.precision_opc_label.setText(QtGui.QApplication.translate("MainWindow", "Precisión del clasificador", None, QtGui.QApplication.UnicodeUTF8))
        self.porc_entr_spinBox.setSuffix(QtGui.QApplication.translate("MainWindow", "%", None, QtGui.QApplication.UnicodeUTF8))
        self.articulo_label.setText(QtGui.QApplication.translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Sans\'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Artículo</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.evaluar_pushButton.setText(QtGui.QApplication.translate("MainWindow", "Evaluar", None, QtGui.QApplication.UnicodeUTF8))
        self.menuDocumentos.setTitle(QtGui.QApplication.translate("MainWindow", "Documentos", None, QtGui.QApplication.UnicodeUTF8))
        self.menuAcerca_de.setTitle(QtGui.QApplication.translate("MainWindow", "Ayuda", None, QtGui.QApplication.UnicodeUTF8))
        self.actionVer_documentos_de_una_ontolog_a.setText(QtGui.QApplication.translate("MainWindow", "Ver documentos de una ontología", None, QtGui.QApplication.UnicodeUTF8))
        self.actionVer_documentos_de_un_corpus_categorizado.setText(QtGui.QApplication.translate("MainWindow", "Ver documentos de un corpus categorizado", None, QtGui.QApplication.UnicodeUTF8))
        self.actionM_todo_de_la_poda.setText(QtGui.QApplication.translate("MainWindow", "Método de la poda", None, QtGui.QApplication.UnicodeUTF8))
        self.actionRedes_bayesianas.setText(QtGui.QApplication.translate("MainWindow", "Redes bayesianas", None, QtGui.QApplication.UnicodeUTF8))
        self.action_ndice.setText(QtGui.QApplication.translate("MainWindow", "Manual Usuario", None, QtGui.QApplication.UnicodeUTF8))
        self.actionAcerca_de.setText(QtGui.QApplication.translate("MainWindow", "Acerca de...", None, QtGui.QApplication.UnicodeUTF8))
        self.actionEvaluaci_n_de_m_todos.setText(QtGui.QApplication.translate("MainWindow", "Evaluación de métodos", None, QtGui.QApplication.UnicodeUTF8))

