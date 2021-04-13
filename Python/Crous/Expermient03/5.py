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
import jieba
import matplotlib.pyplot as plt
from wordcloud import WordCloud as wd

txt = open("31592.txt", "r", encoding="utf-8").read()
jieba.add_word("萧炎")
jieba.add_word("纳兰嫣然")
jieba.add_word("萧薰儿")
jieba.add_word("药老")
jieba.add_word("云韵")
words = jieba.lcut(txt)
counts = {}
names = ["萧炎", "纳兰嫣然", "萧薰儿", "药老", "云韵"]
for word in words:
    if word in names:
        counts[word] = counts.get(word, 0) + 1
print("{0:<10}{1:>8}".format("人物", "出场顺序"))
listitem = list(counts.items())
listitem.sort(key=lambda x: x[1], reverse=True)
for i in range(5):
    word, count = listitem[i]
    print("{0:-<10}{1:->10}".format(word, count))
a = " ".join(words)
my_wordcloud = wd(
    background_color="white", max_words=100, width=1600, height=1200, font_path="FZZJ-LongYTJW.ttf"
).generate(a)
plt.imshow(my_wordcloud)
plt.axis("off")
plt.show()
