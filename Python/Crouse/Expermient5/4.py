# -*-coding:UTF-8-*-
import jieba
with open("mansea.txt","r") as f:
    data = f.read()
getword=jieba.lcut(data)
count={
}
for i in getword:
    if(len(i)!=1):
        count[i]=count.get(i,0)+1
list=list(count.items())
list.sort(key=lambda x:x[1],reverse=True)
for i in range(10):
    key,value=list[i]
    print("key:"+key,end="\t")
    print("value:"+str(value))