# ##################################################################################################
#  Copyright ©  13:10 2021 -5 -25  Lambert All rights reserved.                                    #
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
class University():
    Chinese=0
    Math=0
    English=0
    Total =0
    def __init__(self,Chinese , Math ,English):
        self.Chinese =Chinese
        self.Math =Math
        self.English =English
        self.Total =Chinese + Math + English
    def enterRule(self):
        if self.Total>=200:
            print("Pass")
        else:
            print("Get out")


class ImportantUniversity(University):
    Chinese = 0
    Math = 0
    English = 0
    Total = 0
    def __init__(self,Chinese , Math , English ):
        super(ImportantUniversity,self).__init__(Chinese,Math,English)
        self.Total =Chinese + Math + English
    def enterRule(self):
        if self.Total>=245:
            print("Pass")
        else:
            print("Get out")


Chinese =eval(input("Chinese:"))
Math=eval(input("Math:"))
English =eval(input("English:"))
test=ImportantUniversity(Chinese,Math,English)
test.enterRule()