# -*-coding:UTF-8-*-
i=0
for i in range(-4,5):
    if i<0:
        j=-i
    else:
        j=i
    print(' '*j+'*'*(9-2*j))
