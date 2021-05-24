# ##################################################################################################
#  Copyright ©  20:18 2021 -5 -18  Lambert All rights reserved.                                    #
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
import requests
import json
import urllib.request


city= input("请输入你要查询的城市：")
with open("city.txt","r",encoding = 'utf-8') as fp:
    data=fp.read().replace("'","\"").replace("city =","")
with open("city.json","w",encoding = 'utf-8') as fp2:
    fp2.write(data)
f = open('city.json', 'rb')
cities = json.load(f)
city = cities.get(city)
url = "http://www.weather.com.cn/data/cityinfo/"+city+".html"
print(url)
response = urllib.request.urlopen(url)
html = response.read().decode('utf-8')
print(html)
jsonDatas=json.loads(html)
城市 =jsonDatas["weatherinfo"]["city"]
最低气温=jsonDatas["weatherinfo"]["temp1"]
最高温度=jsonDatas["weatherinfo"]["temp2"]
发布时间=jsonDatas["weatherinfo"]["ptime"]
天气=jsonDatas["weatherinfo"]["weather"]
print("城市：", 城市)
print("时间：",发布时间)
print("最高温度：",最高温度 )
print("最低气温：",最低气温 )
print("天气：",天气 )
