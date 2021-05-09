# -*- coding:utf-8 -*-

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

import requests
import itchat
import itchat
import requests

KEY = 'ccad405a8ff1xxxxxxxxa4380e3b1133'  # 可以到图灵机器人官网申请一个，免费的


def get_response(msg):
    # 构造了要发送给服务器的数据
    apiUrl = 'http://www.tuling123.com/openapi/api'
    data = {
        'key': KEY,
        'info': msg,
        'userid': 'wechat-robot',
    }
    try:
        r = requests.post(apiUrl, data=data).json() # 字典的get方法在字典没有'text'值的时候会返回None而不会抛出异常
        return r.get('text')                        # 为了防止服务器没有正常响应导致程序异常退出，这里用try-except捕获了异常    
    except:                                        # 如果服务器没能正常交互（返回非json或无法连接），那么就会进入下面的return        
        return                                    # 将会返回一个None

#注册获取别人发来的信息方法
@itchat.msg_register(['Text','Map', 'Card', 'Note', 'Sharing', 'Picture'])
def tuling_reply(msg):
        print(msg.User['NickName'] +":"+ msg['Text'])    #这里输出给你发微信的人的名字和他发送的内容        
        reply = get_response(msg['Text'])         #调取图灵机器人获取回复
        print(reply+"\n")       #打印机器人回复的消息
        return reply

@itchat.msg_register([itchat.content.TEXT], isGroupChat=True)    #群消息的处理
def print_content(msg):
    if msg.User["NickName"]=='你希望自动回复群的名字'or msg.User["NickName"]=='另外一个你希望自动回复群的名字':    #这里可以在后面加更多的or msg.User["NickName"]=='你希望自动回复群的名字'
        print(msg.User['NickName'] +":"+ msg['Text'])     #打印哪个群给你发了什么消息
        print(get_response(msg['Text'])+"\n")           #打印机器人回复的消息
        return get_response(msg['Text'])
    else:                                         #其他群聊直接忽略
        pass

itchat.auto_login(hotReload=True)
itchat.run()