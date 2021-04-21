# -*-coding:UTF-8-*-

# ##################################################################################################
#  Copyright ©  13:21 2021 -4 -20  Lambert All rights reserved.                                    #
#     Licensed under the Apache License, Version 2.0 (the "License");                              #
#     you may not use this file except in compliance with the License.                             #
#     You may obtain a copy of the License at                                                      #
#                                                                                                  #
#       http://www.apache.org/licenses/LICENSE-2.0                                                 #
#                                                                                                  #
#     Unless required by applicable law or agreed to in writing, software                          #
#     distributed under the License is distributed on an "AS IS" BASIS,                            #
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                     #
#     See the License for the specific language governing permissions and                          #
#     limitations under the License.                                                               #
#  Love Liya Forever!                                                                              #
# ##################################################################################################

import time
from concurrent.futures import ThreadPoolExecutor
import random


def RedPacketAllocated(number, money):
    if type(number) == type(1):
        moneyMin = 0.01
        moneyMax = money / number * 2
        if money > number * 0.01:
            getMoney = random.randint(1, 100) / 100 * moneyMax
            if getMoney < moneyMin:
                getMoney = moneyMin
                return round(getMoney, 2)
            else:
                return round(getMoney, 2)
        elif money == round(number * 0.01, 2):
            return 0.01
        elif money < round(number * 0.01, 2):
            print("The amount is too small, please give more. . .")
            exit()
    else:
        print("The input is not an integer, please re-enter...")
        exit()


def getRedPacketByThread(number, money):
    a = []
    pool = ThreadPoolExecutor(int(number))
    temp = number
    for i in range(number):
        if i + 1 == temp:
            getmoney = money
            print("Name:" + str(i + 1) + "\t Get money:" + str(getmoney) + "\t The red envelope has been received！")
        else:
            result = pool.submit(RedPacketAllocated, number, money)
            getmoney = result.result()
            number = number - 1
            money = round(money - getmoney, 2)
            print("Name:" + str(i + 1) + "\t Get money:" + str(getmoney) + "\t Here are " + str(
                number) + "red envelope left and no one can claim it，\t Lave money:" + str(
                money))
        a.append(getmoney)
    return a


if __name__ == "__main__":
    number = int(input("Please enter the number of red envelopes:"))
    money = float(input("Please enter the total amount:"))
    a = time.time()
    arr = []
    arr = getRedPacketByThread(number, money)
    sum = 0
    for item in arr:
        sum = sum + item
    b = time.time()
    c = b - a
    print("Money:" + str(round(sum, 2)) + "\t time" + str(c))
