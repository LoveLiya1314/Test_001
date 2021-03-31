# -*-coding:UTF-8-*-
a="adbdcacbdac"
b=input("请输入11个选择题选项：")
while len(b)!=11:
    b=input("请重新输入11个选择题选项：")
b= list(b.lower())
score=0
for i in range(0,11):
    if a[i]==b[i]:
       score+=1
    else:
        b[i]='X'

print(f"You missed %(Score)d questions: " %{'Score':(11-score)},end="")
print(" ".join(b))
print("Your score is: {:.0%} percent".format(score/11))