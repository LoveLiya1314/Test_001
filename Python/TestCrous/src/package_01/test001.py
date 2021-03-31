import PIL
x=10
print(type(x))
x="jfnwalifrvbialgbfv"
print(type(x))
x=1.000003
print(type(x))
x="q"
print(type(x))
x='q'
print(type(x))
x=43
y=x
print(id(x))
print(id(y)) 



x=int(input())
if(x<60*24 and x>=0):
    pass
else if(x>=60*24):
    x=x-24*60
else:
    x=
y=x%60
x=int(x/60)
print(x)
print(y)