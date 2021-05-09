# -*-coding:UTF-8-*-
import random
import numpy as np


def binarySearch(array, l, r, x):
    # 基本判断
    if r >= l:

        mid = int(l + (r - l) / 2)

        # 元素整好的中间位置
        if array[mid] == x:
            return mid

            # 元素小于中间位置的元素，只需要再比较左边的元素
        elif array[mid] > x:
            return binarySearch(array, l, mid - 1, x)

            # 元素大于中间位置的元素，只需要再比较右边的元素
        else:
            return binarySearch(array, mid + 1, r, x)

    else:
        # 不存在
        return -1
def getarray(ranlist=None):
    ranlist = [random.randint(0, 50) for i in range(20)]
    ranlist=list(ranlist)
    ranlist.sort()
    return ranlist
def main():
    array=getarray()
    a=int(input("Please enter a number,the number must is even"))
    a=0
    res=binarySearch(array,0,len(array),a)
    a = np.array(array)
    print(a)
    if res==-1:
        print("No")
    else:
        print(res)
for i in range(100)  :
    main()