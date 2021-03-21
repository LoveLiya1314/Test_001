#-*- coding:utf-8-*-
 #e1.1 TempConvert.py
GetStr=input("请输入带符号的金额")
if GetStr[-1] in ['$']:
	RMB=(eval(GetStr[0:-1])*6)
	print("转换后的人民币是{:.2f}RMB".format(RMB))
elif GetStr[-1] in ['￥']:
	Dollar=eval(GetStr[0:-1])/6
	print("转换后的美金是{:.2f}Dollar".format(Dollar))
else:
	print("输入格式错误")




