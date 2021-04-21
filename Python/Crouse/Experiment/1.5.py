# ##################################################################################################
#  Copyright ©  17:54 2021 -4 -13  Lambert All rights reserved.                                    #
#     Licensed under the Apache License, Version 2.0 (the "License");                              #
#     you may not use this file except in compliance with the License.                             #
#     You may obtain a copy of the License at                                                      #
#                                                                                                  #
#       http://www.apache.org/licenses/LICENSE-2.0                                                 #
#                                                                                                  #
#     Unless required by applicable law or agreed to in writing, software                          #
#     distributed under the License is distributed on an "AS IS" BASIS,                            #
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                     #
#     See the License for the specific language governing permissions and                          #
#     limitations under the License.                                                               #
#  Love Liya Forever!                                                                              #
# ##################################################################################################

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
