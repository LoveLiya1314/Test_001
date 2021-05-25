# ##################################################################################################
#  Copyright ©  13:39 2021 -5 -25  殇璃雪   All rights reserved.                                    #
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
class User():
    __UserName="admin"
    __UserPassword="123456"
    @classmethod
    def set_UserName(self,value):
        self.__UserName = value
    def get_UserName(self):
        return self.__UserName
    def set_UserPassword(self,value):
        self.__UserPassword=value
    def get_UserPassword(self):
        return self.__UserPassword

class Login(User):
    getUserName=""
    getUserPassword=""
    def __init__(self,UserName,UserPassword):
        self.getUserName=UserName
        self.getUserPassword=UserPassword
    def login(self):
        user = User()
        username = user.get_UserName()
        userpassword = user.get_UserPassword()
        if self.getUserName==username:
            if  self.getUserPassword==userpassword:
                print("Welcome back!")
            else:
                print("Password Wrong!")
        else:
            print("Login Falsed!")
name=input("Uswe Name:")
passwd=input("Password:")
aaa=Login(name,passwd)
aaa.login()
