# ##################################################################################################
#  Copyright ©  16:25 2021 -4 -27  Lambert All rights reserved.                                    #
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

# -*-coding:UTF-8-*-
import math
def IsPrime(n):
    flag = True
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            flag = False
            break
    return flag


def GiveYouPrimmes(n):
    if n > 0 and n % 2 == 0:
        for i in range(3, int(n / 2) + 1):
            if IsPrime(i) and IsPrime(n - i):
                print(n, '=', i, '+', n - i)



a = int(input("Please enter a number,the number must is even"))
GiveYouPrimmes(a)
