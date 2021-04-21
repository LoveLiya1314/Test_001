# ##################################################################################################
#  Copyright ©  17:54 2021 -4 -13  Lambert All rights reserved.                                    #
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
GetNumberOne=eval(input("请输入第一个数字："))
GetNumberTwo=eval(input("请输入第二个数字："))
if GetNumberOne==GetNumberTwo:
    print("They are the same.")
elif GetNumberOne!=GetNumberTwo:
    if GetNumberOne>GetNumberTwo:
        print("The   first number is larger")
    else:
        print("The first number is smaller")
    if abs(GetNumberOne-GetNumberTwo)<0.01:
        print("The numbers are close together")
    elif abs(GetNumberOne-GetNumberTwo)==1 :
        print("The numbers are one apart")
    if (GetNumberOne>0 and  GetNumberTwo>0) or (GetNumberOne<0 and GetNumberTwo<0):
        print("The numbers have the same sign")
    else:
        print("The numbers have different signs")

