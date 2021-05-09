# ##################################################################################################
#  Copyright ©  19:49 2021 -5 -5  Lambert All rights reserved.                                     #
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
import random
#######python3支持中文。
lottery = {"一等奖": (0, 0.08, 5), "二等奖": (0.09, 0.3, 3), "三等奖": (0.31, 1, 1)}
dic = {"一等奖": 0, "二等奖": 0, "三等奖": 0}
def 抽奖(lottery):
    for i in range(10):
        n = random.random()
        for k, v in lottery.items():
            if v[0] <= n <= v[1]:
                dic[k] = dic.get(k, 0) + 1
    return dic
def 得分(dec):
    总共得分 = 0
    for k, v in lottery.items():
        总共得分 += dec.get(k) * v[2]
    print("您本轮得分为:", 总共得分)
    奖品 = "adjks"
    if 0 <= 总共得分 < 10:
        奖品 = "魔盒"
    elif 10 <= 总共得分 < 20:
        奖品 = "充电宝"
    elif 20 <= 总共得分 < 30:
        奖品 = "饮水壶"
    else:
        奖品 = "奥运会吉祥物"
    print("恭喜你得到" + 奖品 + "一个！！！")
print("欢迎参加转盘游戏:")
print("您的中奖分布为：")
dec = dict(抽奖(lottery))
for k, v in dec.items():
    print("(%s,%d)" % (k, v))

得分(dec)