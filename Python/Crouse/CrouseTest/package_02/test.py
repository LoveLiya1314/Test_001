# ##################################################################################################
#  Copyright ©  16:11 2021 -4 -27  Lambert All rights reserved.                                    #
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

# # -*-coding:UTF-8-*-
#
# #第一题：
# total=person=score=0
# while(score!=-1):
#     person+=1
#     total=score+total
#     score=int(input("请输入第%d个学生的成绩：" %person))
# average=total/(person-1)
# print(.....)
# #第二题：
# i=0
# while(i%3==2 and i%5==3 and i%7==2):
#     i+=1
# print(i)
# #第三题：
# n=int(input("请输入大于1的整数："))
# if(n==2):
#     print("2是质数")
# else:
#     for i in range(n)
#         if(n%i==0):
#             print("%d不是质数" %n)
#             break
#     else:
#         print("...")
# #第四题：
# for i in range(0,100):
#     for j in range(0,100):
#         if (5*i+3*j+(100-i-j)/3==100 and 100-i-j>=0):
#             print('公鸡: %d只, 母鸡: %d只, 小鸡: %d只' % (i, j, (100-i-j)))
# # total=0
# # for i in range(31):
# #     total=i+total
# # print(total)
# from tkinter import *
# from tkinter.messagebox import *
# root =Tk()
# root.title("Login")
# Label(root,text="User",width="6").place(x=1,y=1)
# Entry(root,width="20").place(x=45,y=1)
# Button(root,text="Register" ,width="15",relief=GROOVE,bg="red").place(x=10,y=10)
#
# root.mainloop()


import sqlite3

connect = sqlite3.connect("test.db")
cursor = connect.cursor()
cursor.execute("create table user (id varchar(20) primary key,name varchar(20))")
cursor.execute("insert into user (id,name) values ('002', 'xmj')")

cursor.execute("insert into user (id,name) values ('003','peter')")



cursor.close()
connect.commit()
connect.close()
