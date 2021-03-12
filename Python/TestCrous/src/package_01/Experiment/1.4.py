# -*-coding:UTF-8-*-
import math
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