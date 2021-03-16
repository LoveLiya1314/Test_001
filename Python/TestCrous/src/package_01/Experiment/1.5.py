import turtle

""" # -*-coding:UTF-8-*-
import turtle
#试着观察一下效果，理解一下代码import turtle #导入库
t = turtle.Pen()#拿起钢笔
t.pencolor("red")#给钢笔添加“墨水”
for x in range(100): #循环开始
    t.forward(x)#钢笔往前移动x个点
    t.left(90)
#下面试着改变角度，你看到了什么
    t.left(91)

#(2)
t = turtle.Pen() #拿起钢笔
t.pencolor("blue")#给钢笔添加“墨水
for x in range(100): #循环开始
    t.circle(x)
    t.left(91)
#(3)
t = turtle.Pen() #拿起钢笔
turtle.bgcolor("black") #加上背景
colors = ["red" ,"yellow" ,"blue","green"] #列表
for x in range(100):#循环开始
    t.pencolor(colors[x%4])#啥意思?
    t.forward(x)
    t.left(91)


#(4)
t = turtle.Pen() #拿起钢笔
turtle.bgcolor("black")#加上背景
colors = ["red" , "yellow" ,"blue"," green"] #列表
for x in range(100):#循环开始
    t.pencolor(colors[x%4])#啥意思?
    t.circle(x)
    t.left(91)
#(5)
t= turtle.Pen() #拿起钢笔
turtle.bgcolor("black")
sides=3
colors=["red" ,"yellow" ,"blue","orange","green","purple"]
for x in range(360):
    t.pencolor(colors[x%sides])
    t.forward(x*3/sides+x)
    t.left(360/sides+1)
    t.width(x*sides/200)


 """
#(6)

t=turtle.Pen() #拿起钢笔
turtle.bgcolor("black")
colors= ["red" ,"yellow" ,"blue","green"]
My_Name=turtle.textinput("殇璃雪","Name")
for i in range(100):
    t.pencolor(colors[i%4])
    t.penup()
    t.forward(i*4)
    t.pendown()
    t.write(My_Name,font=("Arial",int((i+4)/4),"bold"))
    t.left(92)
