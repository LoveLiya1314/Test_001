# ##################################################################################################
#  Copyright ©  16:14 2021 -4 -27  Lambert All rights reserved.                                    #
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
def fun():
    print("Select operations")
    print("1.Add\n 2.Subtract\n 3.Multiply\n 4.Divide\n ")
    operator = input("enter choice(1/2/3/4) is:")
    num1 = input("First Number:\n")
    num2 = input("Second Number:\n")
    num1 = float(num1)
    num2 = float(num2)
    out = None
    if operator == "1":
        out = num1 + num2
    elif operator == "2":
        out = num1 - num2
    elif operator == "3":
        out = num1 * num2
    elif operator == "4":
        out = num1 / num2
    print("Answer: " + str(out))
fun()
