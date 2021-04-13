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
import random

Str = "Welcome to the word guessing game"
print("{0:#^60}".format(Str))
WORDS = ("python", "jumble", "easy", "difficult", "answer", "continue", "phone", "position", "position", "game")
i = "y"
while i in ["Y", "y"]:
    word = random.choice(WORDS)
    word_intermediate = word
    word_res = ""

    for s in word_intermediate:
        pos = random.randrange(len(word_intermediate))
        word_res += word_intermediate[pos]
        word_intermediate = word_intermediate[:pos] + word_intermediate[(pos + 1):]
    print("Out-of-order words:" + word_res)
    GetWord = input("Please guess:")

    while GetWord != word:
        print("Sorry, wrong answer")
        GetWord = input("Keep guessing:")
    if GetWord == word:
        print("You are right, you are awesome,")
        i = input("GO ON？（Y/N）：")
