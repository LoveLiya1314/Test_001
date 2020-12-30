# -*-coding:UTF-8-*-
import requests,json

url='http://openapi.tuling123.com/openapi/api/v2'
def chat(content):
    data={
        "reqType":0,
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
