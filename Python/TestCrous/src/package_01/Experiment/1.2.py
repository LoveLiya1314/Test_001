# -*-coding:UTF-8-*-
adj=input("输入adjective：")
noun=input("输入noun：")
verb=input("输入Verb：")
word = "The "+ adj +" " +noun+" " + verb + " over the lazy brown dog."
print(word)
##（2）
print(word[1])
print(word[5])
print(word[-3])


##（3）
print(word[-5:-1:1].upper())


##（4）
print(sorted(word[4:15:1]))
##(5)
print(word.replace('e','S'))

