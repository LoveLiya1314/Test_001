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

import random

s='Hello,Welcome to Doraemon pizza store'
print("{0:*^50}".format(s))
Number=int(input("请问你想要的披萨数量："))
Prise=float(input("输入单价："))
Pay=Number*Prise

Tax=Pay*0.08
print("{:.2f}".format(Tax))
res='一共'+str(Pay)+'元钱，其中pizza‘+str(Number)’个，税收为'+str(Tax)
print(res)
getdata = input("是否配送？（y/n）")
while(getdata!='y' and getdata!='n'):
    getdata=input("是否配送？（y/n）")
if(getdata=='y'):
    getwhere=input("请输入地址：")
    arrivetime='快递大约' + str(random.randint(15,100))+'分钟后送达'+getwhere+'!'
    print(arrivetime)
else:
    arrivetime = '请在' + str(random.randint(15, 100)) + '分钟后到店自取！'
    print(arrivetime)
print("{0:*^50}".format("谢谢惠顾！"))


