# -*-coding:UTF-8-*-
# from turtle import *
# for i in range(500): #重复500次
#   forward(i)
#   left(90)

import turtle
t = turtle.Pen()
turtle.bgcolor("grey")
#sides=evali(input("输入要绘制的边的数目，请输入2-6的数字！"))
sides=6
colors=["red","yellow","green","blue","orange","purple"]
for x in range(360):
    t.pencolor(colors[x%sides])
    t.forward(x*3/sides+x)
    t.left(360/sides+1)
    t.width(x*sides/180)
    t.left(91)
print("####结束####")