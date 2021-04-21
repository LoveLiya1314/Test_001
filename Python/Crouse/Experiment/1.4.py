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

##（1）请计算并输出其百位、十位和个位上的数字
x=input('请输入一个三位数：')
a,b,c=map(int,x)
print(a,b,c)

##（2）然后计算百位数字的3次方，十位数字的2次方和个位数字的1次方。

a=pow(a,3)
b=pow(b,2)
c=pow(c,1)

##（3）计算出它们的和，并输出。
res=a+b+c
print(res)