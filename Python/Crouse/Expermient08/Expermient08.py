# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Expermient08.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(431, 293)
        sizePolicy = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMinimumSize(QSize(431, 293))
        MainWindow.setMaximumSize(QSize(431, 293))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.User = QLineEdit(self.centralwidget)
        self.User.setObjectName(u"User")
        self.User.setGeometry(QRect(140, 30, 151, 31))
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(40, 30, 81, 31))
        font = QFont()
        font.setPointSize(15)
        self.label.setFont(font)
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(60, 90, 81, 31))
        self.label_2.setFont(font)
        self.Key = QLineEdit(self.centralwidget)
        self.Key.setObjectName(u"Key")
        self.Key.setGeometry(QRect(140, 90, 151, 31))
        self.Load = QPushButton(self.centralwidget)
        self.Load.setObjectName(u"Load")
        self.Load.setGeometry(QRect(80, 170, 81, 41))
        self.Exit = QPushButton(self.centralwidget)
        self.Exit.setObjectName(u"Exit")
        self.Exit.setGeometry(QRect(210, 170, 81, 41))
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"\u7528\u6237\u540d", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"\u5bc6\u7801", None))
        self.Load.setText(QCoreApplication.translate("MainWindow", u"\u767b\u9646", None))
        self.Exit.setText(QCoreApplication.translate("MainWindow", u"\u53d6\u6d88", None))
    # retranslateUi

