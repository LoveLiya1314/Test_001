#-*- coding:utf-8-*-
 #e1.1 TempConvert.py
# GetStr=input("请输入带符号的金额")
# if GetStr[-1] in ['$']:
# 	RMB=(eval(GetStr[0:-1])*6)
# 	print("转换后的人民币是{:.2f}RMB".format(RMB))
# elif GetStr[-1] in ['￥']:
# 	Dollar=eval(GetStr[0:-1])/6
# 	print("转换后的美金是{:.2f}Dollar".format(Dollar))
# else:
# 	print("输入格式错误")




# str=input()
# lenght=len(str)
# Res=' '
# for i in range(lenght):
#     if str[i]=='X'or str[i]=='x':
#          Res+=chr(ord(str[i])-23)
#     elif str[i]=='Y' or str[i]=='y':
#          Res+=chr(ord(str[i])-23)
#     elif str[i]=='Z' or str[i]=='z':
#          Res+=chr(ord(str[i])-23)
#     elif str[i]==' ':
#          Res+=str[i]
#     else:
#         Res+=chr(ord(str[i])+3)
# print(Res[1:lenght+1])

import math
from math import *
print(math.pi)
print(math.e)
a,b=input("输入a，b:").split()
a=int(a)
b=int(b)
print(math.gcd(a,b))
x=int(input("输入x："))
print(math.factorial(x))
print(math.exp(x))
print(math.log2(x))
print(math.sqrt(x))