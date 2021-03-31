def func(m):
    if m>=90:
        print("Pretty Good")
        pass
    elif m>=80 and m<90:
        print("Good")
        pass
    elif 70<=m<80:
        print("middle")
    elif 60<=m<70:
        print("Just OK")
    elif m<60:
        print("Bad!!!")





for i in range(1, 10):
    for j in range(1, i+1):
        print('{}x{}={}\t'.format(j, i, i*j), end='')
    print()
    