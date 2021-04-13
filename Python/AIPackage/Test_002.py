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

import asyncio

from graia.application import GraiaMiraiApplication, Session
from graia.application.entry import *
from graia.application.friend import Friend
from graia.application.group import Group
from graia.application.message.chain import MessageChain
from graia.application.message.elements.internal import Plain
from graia.broadcast import Broadcast

loop = asyncio.get_event_loop()
###导入关于Tencent AI 的API
import requests
import time
import string
import random
import urllib
import hashlib

bcc = Broadcast(loop=loop)
app = GraiaMiraiApplication(
    broadcast=bcc,
    connect_info=Session(
        host="http://localhost:8080", # 填入 httpapi 服务运行的地址
        authKey="INITKEY6AChRHqy", # 填入 authKey
        account=2014947669, # 你的机器人的 qq 号
        websocket=True # Graia 已经可以根据所配置的消息接收的方式来保证消息接收部分的正常运作.
    )
)


#==============================================================================================================================
#==============================================================================================================================
#==============================================================================================================================


class Robot:
    def __init__(self):
        pass
    def tencent(self, msg):
        APPID = '2155479952'  # !!!!!!!!!!!!这里要改的!!!!!!!!!!!!!!!!!!!!!
        APPKEY = 'zKQ0TpCofLhcWq7s'  # !!!!!!!!!!!!这里要改的!!!!!!!!!!!!!!!!!!!!!
        url = 'https://api.ai.qq.com/fcgi-bin/nlp/nlp_textchat'
        params = {
            'app_id': APPID,
            'time_stamp': str(int(time.time())),
            'nonce_str': ''.join(random.choice(string.ascii_letters + string.digits) for x in range(16)),
            'session': '10000'.encode('utf-8'),
            'question': msg.encode('utf-8')
        }
        sign_before = ''
        for key in sorted(params):
            # 键值拼接过程value部分需要URL编码，URL编码算法用大写字母，例如%E8。quote默认大写。
            sign_before += '{}={}&'.format(key, urllib.parse.quote(params[key], safe=''))
            # 将应用密钥以app_key为键名，拼接到字符串sign_before末尾
        sign_before += 'app_key={}'.format(APPKEY)

        # 对字符串sign_before进行MD5运算，得到接口请求签名
        sign = hashlib.md5(sign_before.encode('UTF-8')).hexdigest().upper()
        params['sign'] = sign
        # print(params)
        html = requests.post(url, data=params).json()
        return html['data']['answer']


#==============================================================================================================================
#==============================================================================================================================
#==============================================================================================================================

# 接收群消息
@bcc.receiver("GroupMessage")
async def group_message_handler(app: GraiaMiraiApplication, message: MessageChain, group: Group,member: Member):
    if(group.id == 788057443 or group.id == 623311856 ):
        msg_Group_Get = message.asDisplay()
        if ("@2014947669" in msg_Group_Get):
            robot = Robot()
            await app.sendGroupMessage(group, MessageChain(__root__ = [Plain( robot.tencent(msg_Group_Get) )]))

#接收私人消息
@bcc.receiver("FriendMessage")
async def friend_message_listener(message: MessageChain, friend: Friend, app: GraiaMiraiApplication):
    print(str(friend.id) + " " + friend.nickname + " " + friend.remark)
    msg_Friend_Get = message.asDisplay()
    robot = Robot()
    await app.sendFriendMessage(friend, MessageChain(__root__=[Plain(robot.tencent(msg_Friend_Get))]))

app.launch_blocking()