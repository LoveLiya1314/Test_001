# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Start.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def __init__(self):
        super(Ui_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(657, 637)
        self.ActionToGluttonousSnake = QAction(MainWindow)
        self.ActionToGluttonousSnake.setObjectName(u"ActionToGluttonousSnake")
        self.ActionToGluttonousSnake.setCheckable(True)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(200, 80, 251, 91))
        self.pushButton_2 = QPushButton(self.centralwidget)
        self.pushButton_2.setObjectName(u"pushButton_2")
        self.pushButton_2.setGeometry(QRect(200, 180, 251, 91))
        self.pushButton_3 = QPushButton(self.centralwidget)
        self.pushButton_3.setObjectName(u"pushButton_3")
        self.pushButton_3.setGeometry(QRect(200, 280, 251, 101))
        self.pushButton_4 = QPushButton(self.centralwidget)
        self.pushButton_4.setObjectName(u"pushButton_4")
        self.pushButton_4.setGeometry(QRect(200, 390, 251, 91))
        self.pushButton_5 = QPushButton(self.centralwidget)
        self.pushButton_5.setObjectName(u"pushButton_5")
        self.pushButton_5.setGeometry(QRect(490, 580, 151, 51))
        self.pushButton_6 = QPushButton(self.centralwidget)
        self.pushButton_6.setObjectName(u"pushButton_6")
        self.pushButton_6.setGeometry(QRect(10, 590, 101, 41))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)

    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Hello", None))
        self.ActionToGluttonousSnake.setText(
            QCoreApplication.translate("MainWindow", u"\u6253\u5f00\u8d2a\u5403\u86c7", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"\u8d2a\u5403\u86c7", None))
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"\u4e94\u5b50\u68cb", None))
        self.pushButton_3.setText(QCoreApplication.translate("MainWindow", u"\u4fc4\u7f57\u65af\u65b9\u5757", None))
        self.pushButton_4.setText(QCoreApplication.translate("MainWindow", u"\u626b\u96f7", None))
        self.pushButton_5.setText(QCoreApplication.translate("MainWindow", u"\u9000\u51fa", None))
        self.pushButton_6.setText(QCoreApplication.translate("MainWindow", u"\u5173\u4e8e", None))
    # retranslateUi


aaa = Ui_MainWindow()

