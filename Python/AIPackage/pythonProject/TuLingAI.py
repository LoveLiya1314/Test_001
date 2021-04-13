# -*-coding:UTF-8-*-

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

import json
import requests

url = 'http://openapi.tuling123.com/openapi/api/v2'


def chat(content):
    data = {
        "reqType": 0,
        "perception": {
            "inputText": {
                "text": text
            },
            "selfInfo": {
                "location": {
                    "city": "陕西",
                    "province": "西安",
                    "street": "雁塔南路"
                }
            }
        },
        "userInfo": {
            "apiKey": "6d7ecac2720341a1932626c510a06768",
            "userId": "tsfy2003"
        }
    }
    data=json.dumps(data)
    # 图灵接口接收的是json格式，而上面创建的data是字典，所以需要格式转化
    res=requests.post(url,data=data)
    result=res.json()
    for reply in result['results']:
        print('Anatee：'+reply['values']['text'])

print('Hi,我是你的Liya！\n回复“再见，Liya”可以退出聊天。')
while True:
    text=input('我：')
    if text=='再见，Liya' :
        print('Liya：好吧，不聊了，再见啦！')
        break
    else:
        chat(text)
