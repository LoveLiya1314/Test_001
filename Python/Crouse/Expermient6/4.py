# ##################################################################################################
#  Copyright ©  16:22 2021 -5 -25  Lambert All rights reserved.                                    #
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
import json
class Studeent():
    def __init__(self):
        with open('gpa.txt','r', encoding = 'utf-8') as file_open:
            data = json.load(file_open)
            姓名=""
            学号=""
            总学分=0
            总绩点数=0
            GPAPrint=0
            for line in data:
                name =line['姓名']
                score =eval(line['总学分'])
                score1=eval(line['总绩点数'])
                Id=line['学号']
                test = StudentGPA(name,Id,score,score1)
                GPA=test.getGpa()
                if GPAPrint <GPA:
                    姓名 =test.get_姓名()
                    学号 = test.get_学号()
                    总学分 = test.get__总学分()
                    总绩点数 = test.get_总绩点数()
                    GPAPrint =test.getGpa()
                else:
                    pass
            print(GPAPrint)
            print(姓名, end="\t")
            print(学号, end="\t")
            print(总学分, end="\t")
            print(总绩点数, end="\n")
class StudentGPA():
    __姓名=""
    __学号=""
    __总学分=0
    __总绩点数=0
    __GPA=0
    def __init__(self,姓名,学号,   总学分,   总绩点数):
        self.__学号=学号
        self.__姓名=姓名
        self.__总学分=总学分
        self.__总绩点数=总绩点数
        #self.__GPA=self.__总绩点数/self.__总学分
    def get_姓名(self):
        return self.__姓名
    def get_学号(self):
        return self.__学号
    def get__总学分(self):
        return self.__总学分
    def get_总绩点数(self):
        return self.__总绩点数
    def getGpa(self):
        self.__GPA = self.__总绩点数 / self.__总学分
        return self.__GPA
aaa=Studeent()