# -*-coding:UTF-8-*-
for x in range(1,100):
    for y in range(1,100):
        z = 100 -x-y
        if (5*x+3*y+z/3==100) and z%3==0:
            print('公鸡：%(X)d只，母鸡：%(Y)d只，小鸡：%(Z)d只。'%{'X':x,'Y':y,'Z':z})
