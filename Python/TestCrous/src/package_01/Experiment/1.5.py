# -*-coding:UTF-8-*-
import turtle
#试着观察一下效果，理解一下代码import turtle #导入库
t = turtle.Pen()#拿起钢笔
t.pencolor("red")#给钢笔添加“墨水”
for x in range(100): #循环开始
    t.forward(x)#钢笔往前移动x个点
    t.left(90)
#下面试着改变角度，你看到了什么
    t.left(91)


t = turtle.Pen() #拿起钢笔
t.pencolor("blue")#给钢笔添加“墨水
for x in range(100): #循环开始
    t.circle(x)
    t.left(91)

t = turtle.Pen() #拿起钢笔
turtle.bgcolor("black") #加上背景
colors = ["red" ,"yellow" ,"blue","green"] #列表
for x in range(100):#循环开始
    t.pencolor(colors[x%4])#啥意思?
    t.forward(x)
    t.left(91)





t = turtle.Pen() #拿起钢笔
turtle.bgcolor("black")#加上背景
colors = ["red" , "yellow" ,"blue"," green"] #列表
for x in range(100):#循环开始
    t.pencolor(colors[x%4])#啥意思?
    t.circle(x)
    t.left(91)



