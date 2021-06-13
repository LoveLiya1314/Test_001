# -*-coding:UTF-8-*-
from PySide2.QtWidgets import QApplication,QMessageBox
from PySide2.QtUiTools import  QUiLoader
class start_ui:
    def __init__(self):
        self.ui = QUiLoader().load('Start.ui')
        self.ui.GluttonousSnake.clicked.connect(self.GluttonousSnakeFun)
        self.ui.Gomoku.clicked.connect(self.GomokuFun)
        self.ui.Exit.clicked.connect(self.Exit)


    def GluttonousSnakeFun(self):
        from GluttonousSnake import GluttonousSnake
        GluttonousSnake.main()

    def GomokuFun(self):
        from Gomoku import Gomoku
        Gomoku.main()

    def Exit(self):
        exit(0)
class About_ui:
    def __init__(self):
        self.ui = QUiLoader().load('About.ui')

app=QApplication([])
stats=start_ui()
about=About_ui()
bt=stats.ui.About
bt.clicked.connect(about.ui.show)
stats.ui.show()
app.exec_()