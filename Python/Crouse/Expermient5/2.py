# -*-coding:UTF-8-*-
with open('圆周率.txt','r') as fp2:
    data=fp2.read().replace(" ","")
GetBirthdays=input("")
if GetBirthdays in data :
    print("Yes")
else:
    print("No")