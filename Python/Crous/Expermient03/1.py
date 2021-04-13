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
import re

s1 = "The Spring is coming! We go into April happily. We hope less homework and less test .Be better all!12345 "
s2 = "hahahahaha"
# (1)
s3 = s1 + s2
print(s3)

# (2)
print(s3.replace("h", "r"))

# (3)
GetWord = input()
Res = s3.find(GetWord)
print(Res)

# (4)
ls1 = list(s1.split(" "))
print(len(ls1))
print(ls1[1:-2])
ls1.append("I love today!")

# (5)
print(re.split(r"[. !]", s1))
print(re.split(r"[. !]", s1, maxsplit=5))

# (6)
dic = {}
for s in s1:
    if s.isupper():
        dic["UpperWord"] = dic.get("UpperWord", 0) + 1
    elif s.islower():
        dic["LowerWord"] = dic.get("LowerWord", 0) + 1
    elif s.isdigit():
        dic["Digitword"] = dic.get("Digitword", 0) + 1
    else:
        dic["OtherWord"] = dic.get("OtherWord", 0) + 1
for k, v in dic.items():
    print(k, v)
# P.S.:在python 2中，d.items()返回(key，value)元组的列表，而d.iteritems()返回一个提供相同的迭代器：在python 3中，d.items()返回迭代器
