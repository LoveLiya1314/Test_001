# -*-coding:UTF-8-*-
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


