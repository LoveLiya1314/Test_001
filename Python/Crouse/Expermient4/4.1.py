# ##################################################################################################
#  Copyright ©  16:54 2021 -4 -27  Lambert All rights reserved.                                    #
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

from random import random

def 轮盘赌(奖项分布):
    本次转盘读数 = random()
    for k, v in 奖项分布.items():
        if v[0] <= 本次转盘读数 < v[1]:
            return k
奖项分布 = {'一等奖': (0, 0.08),
        '二等奖': (0.08, 0.3),
        '三等奖': (0.3, 1.0)}
中奖情况 = dict()
for i in range(10000):
    本次战况 = 轮盘赌(奖项分布)
    中奖情况[本次战况] = 中奖情况.get(本次战况, 0) + 1
for item in 中奖情况.items():
    print(item)
