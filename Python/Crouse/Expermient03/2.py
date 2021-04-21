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

# -*-coding:UTF-8-*-
def PrintfKeys(GetData, str):
    print(str, end='')
    for i in GetData:
        print(i, end=" ")
    print()


def PrintValues(GetData, str):
    print(str, end='')
    for i in GetData:
        print(GetData[i], end=" ")
    print()


def PrintItems(GetData, str):
    print(str, end='')
    for key, value in GetData.items():
        print(key + " =>" + value, end="\t")
    print()


favorite_languages = {"周杰伦": "java", "李云龙": "c", "铁林": "c++", "乔丹": "c#", "马拉多纳": "python"}
PrintItems(favorite_languages, "数据：")
PrintfKeys(favorite_languages, "人员：")
PrintValues(favorite_languages, "语言：")
Persion = ["詹姆斯", "乔丹", "邓肯"]
for p in Persion:
    if p in favorite_languages:
        print("{0},{1}".format(p, "感谢参与"))
    else:
        print("{0},{1}".format(p, "希望您能参与调查"))
