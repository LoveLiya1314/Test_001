# -*-coding:UTF-8-*-
x=int(input())
if(x>=0):
    x=x%(24*60)
else:
    x=abs(x)
    x=x%(24*60)
    x=24*60-x
y=x%60
x=int(x/60)
print("Time is :%d:%d"%(x,y))
