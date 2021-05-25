"""
Copyright 2021 殇璃雪

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     https://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
class 电影():
    电影名称=""
    导演=""
    演员=[]
    上映时间=""
    主要情节=""
    豆瓣评分=""
    电影类型=""
    国家=""
    def __init__(self, 电影名称,导演,豆瓣评分,国家,电影类型,上映时间):
        self.电影名称=电影名称
        self.豆瓣评分=豆瓣评分
        self.导演=导演
        self.国家=国家
        self.电影类型=电影类型
        self.上映时间=上映时间
    def 情节添加(self,主要情节):
        self.主要情节=主要情节
    def 演员添加(self,演员):
        self.演员=演员
    def 输出电影信息(self):
        print("电影名称:"+self.电影名称)
        print("导演:"+self.导演)
        print("上映时间:"+self.上映时间)
        print("演员:"+str(self.演员))
        print("主要情节:"+self.主要情节)
        print("豆瓣评分:"+self.豆瓣评分)
        print("电影类型"+self.电影类型)
        print("国家:"+self.国家)
赤色黎明=电影("赤色黎明","丹·布拉德利","8.9","美国","战争片","2012年11月23日")
赤色黎明.演员添加("克里斯·海姆斯沃斯、乔希·佩克、乔什·哈切森、阿德琳妮·帕里奇、伊莎贝尔·卢卡斯、康纳·克鲁斯和杰弗里·迪恩·摩根")
赤色黎明.情节添加("影片聚焦于一群帮助家乡抵御北朝鲜入侵的年轻人。")
赤色黎明.输出电影信息()