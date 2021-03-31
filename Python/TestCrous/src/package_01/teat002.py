import time
scale=10
print("------START--------")
for i in range(scale+1):
    a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:^3.0f}%[{}->{}]".format(c,a,b))
    time.sleep(0.1)
print("-------END----------")

scale=100

print("------START--------")
for i in range(scale+1):
   # a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:.0f}%".format(c))
    time.sleep(0.03)
print()
print("-------END----------")


scale=100

print("------START--------")
for i in range(scale+1):
   # a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:.0f}% ".format(c),end=" ")
    time.sleep(0.01)
print()
print("-------END----------")

