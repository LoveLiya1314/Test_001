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

# # 这是一个示例 Python 脚本。
#
# # 按 Shift+F10 执行或将其替换为您的代码。
# # 按 Double Shift 在所有地方搜索类、文件、工具窗口、操作和设置。
#
#
# def print_hi(name):
#     # 在下面的代码行中使用断点来调试脚本。
#     print(f'Hi, {name}')  # 按 Ctrl+F8 切换断点。
#
#
# # 按间距中的绿色按钮以运行脚本。
# if __name__ == '__main__':
#     print_hi('PyCharm')
#
# # 访问 https://www.jetbrains.com/help/pycharm/ 获取 PyCharm 帮助
import hashlib
import random
import string
import time
import urllib

import requests


class Robot:
    def __init__(self):
        pass

    # def qingyunke(self, msg):
    #     url = 'http://api.qingyunke.com/api.php?key=free&appid=0&msg={}'.format(urllib.parse.quote(msg))
    #     html = requests.get(url)
    #     return html.json()["content"]
    #
    # def tuling(self, msg):
    #     index = 0
    #     while True:
    #         api_key = [
    #             "618bd2a9b7c6414ebbda21585f0d0752",  # 提供一下我的
    #         ]
    #         url = 'http://openapi.tuling123.com/openapi/api/v2'
    #         data = {
    #             "perception": {
    #                 "inputText": {
    #                     "text": msg
    #                 },
    #             },
    #             "userInfo": {
    #                 "apiKey": api_key[index],
    #                 "userId": "1"
    #             }
    #         }
    #         datas = json.dumps(data)
    #         html = requests.post(url, datas).json()
    #         if html['intent']['code'] == 4003:
    #             print(">> 次数用完")
    #             index += 1
    #             if index == len(api_key):
    #                 return None
    #             else:
    #                 print(">> 换key重试:", index)
    #                 time.sleep(1)
    #                 continue
    #         break
    #     return html['results'][0]['values']['text']

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

    # def sizhi(self, msg):
    #     url = 'https://api.ownthink.com/bot?spoken={}'.format(urllib.parse.quote(msg))
    #     html = requests.get(url)
    #     return html.json()["data"]['info']['text']
    #
    # def xiaodou(self, msg):
    #     key = 'M1E1OUZJNCtsODZvZndqNj1UV2x4Zz1xWnhvQUFBPT0'
    #     url = 'http://api.douqq.com/?key={}&msg={}'.format(key, msg)
    #     html = requests.get(url)
    #     return html.text
    #
    # def xiaobing(self, msg):
    #     uid = '5175429989'  # !!!!!!!!!!!!这里要改的!!!!!!!!!!!!!!!!!!!!!
    #     source = '209678993'  # !!!!!!!!!!!!这里要改的!!!!!!!!!!!!!!!!!!!!!
    #     SUB = '_2A25zeEw7DeRhGeNG6lQS9SbKyD2IHXVQDDrzrDV8PUNbmtANLWXukW9NS25ufhgLW38wP8yAkpHlxnTZ3CN3dQFy'  # !!!!!!!!!!!!这里要改的!!!!!!!!!!!!!!!!!!!!!
    #     url_send = 'https://api.weibo.com/webim/2/direct_messages/new.json'
    #     data = {
    #         'text': msg,
    #         'uid': uid,
    #         'source': source
    #     }
    #     headers = {
    #         'cookie': 'SUB=' + SUB,
    #         'Content-Type': 'application/x-www-form-urlencoded',
    #         'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36',
    #         'Referer': 'https://api.weibo.com/chat/'
    #     }
    #     response = requests.post(url_send, data=data, headers=headers).json()
    #     sendMsg = response['text']
    #     time.sleep(1)
    #
    #     while True:
    #         url_get = 'https://api.weibo.com/webim/2/direct_messages/conversation.json?uid={}&source={}'.format(uid,
    #                                                                                                             source)
    #         response = requests.get(url_get, headers=headers).json()
    #         getMsg = response['direct_messages'][0]['text']
    #         if sendMsg == getMsg:
    #             time.sleep(1)
    #         else:
    #             return getMsg


 # if __name__ == '__main__':
print('Hi,我是你的Liya！\n回复“再见，Liya”可以退出聊天。')
while True:
    msg = input('我：')
    if msg=='再见，Liya'or msg=="再见":
        print('Liya：好吧，不聊了，再见啦！')
        break
    else:
        robot = Robot()
        print("Liya："+robot.tencent(msg))  # 果然我的魅力无敌，终于把你吸引来了，哈哈哈
    # print(robot.tuling(msg))  # 你说好就好吧。
    # print(robot.qingyunke(msg))  # 你好，我就开心了
    # print(robot.sizhi(msg))  # 感觉不错。你好吗？
    # print(robot.xiaodou(msg))  # 你好哇，很开心你能找我聊天。
    # print(robot.xiaobing(msg))  # (不想登微博了，自行测试吧！)
