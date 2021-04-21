# -*-coding:UTF-8-*-

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

# from turtle import *
# for i in range(500): #重复500次
#   forward(i)
#   left(90)

import turtle
t = turtle.Pen()
turtle.bgcolor("grey")
<<<<<<< Updated upstream
t.speed(10)
#sides=evali(input("输入要绘制的边的数目，请输入2-6的数字！"))
sides=6################################6,7,8
colors=["red","yellow","green","blue","orange","purple","black","pink"]
=======
#sides=evali(input("输入要绘制的边的数目，请输入2-6的数字！"))
sides=6
colors=["red","yellow","green","blue","orange","purple"]
>>>>>>> Stashed changes
for x in range(360):
    t.pencolor(colors[x%sides])
    t.forward(x*3/sides+x)
    t.left(360/sides+1)
    t.width(x*sides/180)
    t.left(91)
<<<<<<< Updated upstream
turtle.exitonclick()
=======
>>>>>>> Stashed changes
print("####结束####")