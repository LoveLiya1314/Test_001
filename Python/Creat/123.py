# -*-coding:UTF-8-*-
from tkinter import *
root = Tk()
root.title("登录")
root.geometry('600x400')
Label(root,text = '用户名',width=5).place(x=230,y=150)
Entry(root,width=20).place(x=275,y=150)                  #绝对坐标（45，20）
Label(root,text = '密码',width=6).place(x=230,y=190)     #绝对坐标（1，20）
Entry(root,width=20, show='*').place(x=275,y=190)       #绝对坐标（45，20）
Button(root,text = '登录',width=8).place(x=275,y=300)   #绝对坐标（40，40）
Button(root,text = '取消',width=8).place(x=325,y=300)  #绝对坐标（110，40）
root.mainloop()
