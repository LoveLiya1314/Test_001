# ##################################################################################################
#  Copyright ©  11:55 2021 -6 -24  Lambert All rights reserved.                                    #
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

# -*- code:UTF-8 -*-

'''
from pip._vendor.distlib.compat import raw_input
print("Hello,World!")
a="hello"
a=input("请输入数字：")
a=int(a)
#raw_input("按下 enter 键退出，其他任意键显示...\n")
'''
# from datetime import time
# from random import random

'''
i=1
while i<=9:
    j=1
    while j<=i:
        print("%d*%d=%d\t"%(i,j,i*j),end="")
        j+=1
    print("")
    i+=1
'''
# a="   Hello,  World!!  "
# print(a.strip())
# print(a.lower())
# print(a.upper())
# print(a.split("l"))
# print(a.replace("l", "Kitty"))
# x="Hello" in a
# print(x)


# quantity = 3
# itemno = 567
# price = 49.95
# myorder = "I want to pay {2} dollars for {0} pieces of item {1}."
# print(myorder.format(quantity, itemno, price))

# print(bool(" "))

# thislist = ["apple", "banana", "cherry"]
# for x in thislist:
#   print(x,end="\t")

# a=["hello","world"]
# print(len(a))
# a.append("!")
# print(len(a))

# thislist = ["apple", "banana", "cherry"]
# thislist.pop(2)
# print(thislist)

# list=["111","222","333","444","555"]
# list.remove("111")
# print(list)
# list.pop(0)
# print(list)
# del list[2]
# print(list)
# del list
# print(list)

# thislist = ["apple", "banana", "cherry"]
# mylist = thislist.copy()
# print(mylist)

# thislist = ["apple", "banana", "cherry"]
# mylist = list(thislist)
# print(mylist)


# thisset = {"111", "222", "333","444","555"}
# print(thisset)
# x = thisset.pop()
# print(x)
# print(thisset)

# thisset = {"111", "222", "333","444","555"}
# print(thisset)
# thisset.clear()
# print(thisset)

# thisset = {"111", "222", "333","444","555"}
# for a in thisset:
#     print(a)

# thisdict={
#     "First": 1,
#     "Second": 2,
#     "Third": 3,
# }
# for x, y in thisdict.items():
#   print(x,y)


# def function(i,j):
#
#     for x in range(i):
#         for y in range(x):
#             print("%d*%d=%d"%(x,y,x*y),end="\t")
#         print("")
#     for x in range(j):
#         for y in range(x):
#             print("%d*%d=%d"%(x,y,x*y),end="\t")
#         print("")
# function(9,8)


# a=input()
# a=int(a)
# print(a)
# list=[]
# for x in range(a):
#     b=input()
#     b=int(b)
#     list.append(b)
# list.sort()
# print(list)

# import sys
# dir(sys)


# class first(object):
#     def fun(self,sound):
#         print(sound)
#     def set_color(self,color):
#         self.color=color
# a=first()
# a.set_color("blue")
# print(a.color)


# class secoond(object):
#     def __init__(self,aaa):
#         self.aaa=aaa
#         print(aaa)
#     def fun(self):
#         print(self.aaa)
# a=secoond("bbb")
# a.fun()



# file=open("a.txt","rt")
# print(file.read())
# file.seek(0)
# for x in file:
#     print(x)
# file.close()
# file=open("a.txt","at")
# a=input("insert:")
# file.write(a)
# file.close()
# file=open("a.txt")
# print(file.read())


# def fun():
#    global arg
#    arg=000
# fun()
# print(arg)

# a = 4
# def h():
#     print(a)
#     a = 12
# h()
# print(a)

# class qwe:
#     def __index__(self):
#         self.number=20
#     def aaa(self):
#         print(self.number)
#         self.number+=10
#         print(self.number)
# a=qwe
# a.__init__
# a.aaa   #一个错误的想法


# #str1 = “Computing 5”, str2 = “Thinking#2”
# str1 = 'Computing 5'
# str2="Thinking#2"
# number1 = str1.split()
# number2 = str2.split("#",1)
# st1=number1[0]
# st2=number2[0]
# number1=int(number1[1])
# number2=int(number2[1])
# print (st2*number1)
# print(st1*number2)
#
#
#
# str="!abcABCdEF!!aBCDeFAbC!!"
# str1=str.lower()
# number1=str1.count("abc")
# number2=str1.count("def")
# p1=str1.find("abc")
# p2=str1.find("def")
# res=str1.replace("!","")
# print("abc 字符串 : %d 索引，, %d 个存在"%(p1,number1) )
# print("def 字符串 : %d 索引，, %d 个存在"%(p2,number2) )
# print("!去除的字符串 :%s"%res)


# original = "This class is Computational Thinking!"
# res=original[::-1]
# print("reversed sentence :%s"%res)

# str=input("")
# number1=str.split()
# a1=int(number1[0])
# a2=int(number1[1])
# average=(a1+a2)/2
# a=number1[2]
# if average>95:
#     if a=='P':
#         print("你的学分是A+")
#     else:
#         print("你的学分是B+")
# elif average>90 and a1>90 and a2>90:
#     if a=='P':
#         print("你的学分是A0")
#     else:
#         print("你的学分是B0")
# elif average>90 and ( a1>90 or a2>90):
#     if a=='P':
#         print("你的学分是A")
#     else:
#         print("你的学分是B")
# elif average>85:
#     if a=='P':
#         print("你的学分是B+")
#     else:
#         print("你的学分是C+")
# elif average>80 and a1>80 and a2>80:
#     if a=='P':
#         print("你的学分是B0")
#     else:
#         print("你的学分是C0")
# elif average>80 and ( a1>80 or a2>80):
#     if a=='P':
#         print("你的学分是B")
#     else:
#         print("你的学分是C")
# elif average>75:
#     if a=='P':
#         print("你的学分是C+")
#     else:
#         print("你的学分是D+")
# elif average>70 and a1>70 and a2>70:
#     if a=='P':
#         print("你的学分是C0")
#     else:
#         print("你的学分是D0")
# elif average>70 and ( a1>70 or a2>70):
#     if a=='P':
#         print("你的学分是C")
#     else:
#         print("你的学分是D")


# L=[12,29,30,0,99]
# while True:
#   a=input("打印单L中添加的data：")
#   try:
#    x=eval(a)
#    if type(x)==int:break
#   except:pass
# a=int(a)
# i=0;
# for x in L:
#     if a==x:
#         i=1;
#         break;
# if i==0:
#     L.append(a)
# print(L)

# M=[]
# L= [10, 'CT', [29, 31.4, 0]]
# if len(L)==3:
#     for a in L:
#         M.append(a)
# print("输入：M：" ,M,end=" ")

# #!/usr/bin/env python
# # -*- coding: utf-8 -*-
# #from Crypto.Util.number import *
# import random
# m = 391190709124527428959489662565274039318305952172936859403855079581402770986890308469084735451207885386318986881041563704825943945069343345307381099559075
# c = 6665851394203214245856789450723658632520816791621796775909766895233000234023642878786025644953797995373211308485605397024123180085924117610802485972584499
#
# n = 2 ** 512
# m = random.randint(2, n-1) | 1
# c = pow(m, bytes_to_long(flag), n)
# print ('m = ' + str(m))
# print ('c = ' + str(c))



# from secret import flag,key
# from random import randint
# from libnum import n2s,s2n
# from Crypto.Util.number import getPrime
# limit = lambda n: n & 0xffffffff
# padding="\xe6\xe6\xe7\xe6\xe5\xe6\xe5\xe9\xe5"
# ek='\xe6\x84\xbf'
#
# def encode(key,data):
#     pad  = randint(0x10000000,0xffffffff)
#     Key  = [ord(i) for i in key]
#     Data = [ord(i) for i in data]
#     a = limit((Key[0] << 24) | (Key[1] << 16) | (Key[2] << 8) | Key[3])
#     b = limit((Key[4] << 24) | (Key[5] << 16) | (Key[6] << 8) | Key[7])
#     c = limit((Key[8] << 24) | (Key[9] << 16) | (Key[10] << 8) | Key[11])
#     d = limit((Key[12] << 24) | (Key[13] << 16) | (Key[14] << 8) | Key[15])
#     y = limit((Data[0] << 24) | (Data[1] << 16) | (Data[2] << 8) | Data[3])
#     z = limit((Data[4] << 24) | (Data[5] << 16) | (Data[6] << 8) | Data[7])
#     pads = 0
#     for j in range(32):
#         pads = limit(pads + pad)
#         y = limit( y + ((z*16 + a) ^ (z + pads) ^ ((z>>5) + b)))
#         z = limit( z + ((y*16 + c) ^ (y + pads) ^ ((y>>5) + d)))
#     print (hex((y << 52) ^ (pads << 20) ^ z))
#
# #pow_check()
# #token_check()
#
# flag=flag.ljust(len(flag)+(-len(flag)&7),'\x00')
# for i in range(0,len(flag)/8):
#     encode(key,flag[8*i:8*i+8])
#
# for i in range(9):
#     ek+=padding[i] + key[2*i:2*i+2]
#
# p=getPrime(2048)
# e=0x10001
#
# for i in range(2):
#     q=getPrime(2048)
#     n=p*q
#     print (n)
#     print( pow(s2n(ek),e,n))

# import random
#
# from secret import flag
#
# N = 100
# MASK = 2 ** (N + 1) - 1
#
#
# def lfsr(state, mask):
#     feedback = state & mask
#     feed_bit = bin(feedback)[2:].count("1") & 1
#     output_bit = state & 1
#     state = (state >> 1) | (feed_bit << (N - 1))
#     return state, output_bit
#
#
# def main():
#     assert flag.startswith("flag{")
#     assert flag.endswith("}")
#
#     mask = int(flag[5:-1])
#     assert mask.bit_length() == N
#
#     state = random.randint(0, MASK)
#     print(state)
#
#     outputs = ''
#     for _ in range(N ** 2):
#         state, output_bit = lfsr(state, mask)
#         outputs += str(output_bit)
#
#     with open("output.txt", "w") as f:
#         f.write(outputs)
#
#
# main()

# # from secret import flag
#
# from Crypto.Util.number import *
#
# m = bytes_to_long()
#
# p = getPrime(512)
# q = getPrime(512)
# N = p * q
# phi = (p-1) * (q-1)
# while True:
#     d = getRandomNBitInteger(200)
#     if GCD(d, phi) == 1:
#         e = inverse(d, phi)
#         break
#
# c = pow(m, e, N)
#
# print(c, e, N, sep='\n')

# 37625098109081701774571613785279343908814425141123915351527903477451570893536663171806089364574293449414561630485312247061686191366669404389142347972565020570877175992098033759403318443705791866939363061966538210758611679849037990315161035649389943256526167843576617469134413191950908582922902210791377220066
# 46867417013414476511855705167486515292101865210840925173161828985833867821644239088991107524584028941183216735115986313719966458608881689802377181633111389920813814350964315420422257050287517851213109465823444767895817372377616723406116946259672358254060231210263961445286931270444042869857616609048537240249
# 86966590627372918010571457840724456774194080910694231109811773050866217415975647358784246153710824794652840306389428729923771431340699346354646708396564203957270393882105042714920060055401541794748437242707186192941546185666953574082803056612193004258064074902605834799171191314001030749992715155125694272289

import signal
import random
import os
import time
import string
import hashlib
# from flag import getflag
#
# def get_user_input(s):
#     try:
#         data = bytes.fromhex(input(s))
#     except:
#         print("Invalid input format")
#         exit(0)
#     return data
#
# def proof():
#     difficulty = 24
#     prefix = ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(8))
#     answer = get_user_input(f"sha256('{prefix}'+ ? ).binary.startswith('0'*{difficulty}): ")
#     hashresult=hashlib.sha256(prefix.encode()+answer).digest()
#     bits=''.join(bin(_)[2:].zfill(8) for _ in hashresult)
#     if not bits.startswith('0'*difficulty):
#         exit(0)
#
# signal.alarm(15)
# proof()
# flag = getflag(get_user_input("Input your team token: ").decode())
#
# signal.alarm(10)
# random.seed(int(time.time()))
# random_constants = [random.randint(0, 2**32 - 1) for i in range(64)]
# random_iv = [random.randint(0, 2**32 - 1) for i in range(4)]
#
# def left_rotate(x, amount):
#     x &= 0xFFFFFFFF
#     return ((x<<amount) | (x>>(32-amount))) & 0xFFFFFFFF
#
# def random_hash(message):
#     rotate_amounts = [7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
#                       5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
#                       8, 11, 16, 23, 8, 11, 16, 23, 8, 11, 16, 23, 8, 11, 16, 23,
#                       6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21]
#
#     functions = 16*[lambda b, c, d: (b & c) | (~b & d)] + \
#                 16*[lambda b, c, d: (d & b) | (~d & c)] + \
#                 16*[lambda b, c, d: b ^ c ^ d] + \
#                 16*[lambda b, c, d: c ^ (b | ~d)]
#
#     index_functions = 16*[lambda i: i] + \
#                       16*[lambda i: (5*i + 1)%16] + \
#                       16*[lambda i: (3*i + 5)%16] + \
#                       16*[lambda i: (7*i)%16]
#
#     message = bytearray(message)
#     orig_len_in_bits = (8 * len(message)) & 0xffffffffffffffff
#     message.append(0x80)
#     while len(message)%64 != 56:
#         message.append(0)
#     message += orig_len_in_bits.to_bytes(8, 'little')
#
#     hash_pieces = random_iv[:]
#
#     for chunk_ofst in range(0, len(message), 64):
#         a, b, c, d = hash_pieces
#         chunk = message[chunk_ofst:chunk_ofst+64]
#         for i in range(64):
#             f = functions[i](b, c, d)
#             g = index_functions[i](i)
#             to_rotate = a + f + random_constants[i] + int.from_bytes(chunk[4*g:4*g+4], 'little')
#             a, b, c, d = d, (b + left_rotate(to_rotate, rotate_amounts[i])) & 0xFFFFFFFF, b, c
#         for i, val in enumerate([a, b, c, d]):
#             hash_pieces[i] += val
#             hash_pieces[i] &= 0xFFFFFFFF
#
#     return sum(x<<(32*i) for i, x in enumerate(hash_pieces)).to_bytes(16, "little")
#
# def isPrime(n):
#     r, s = 0, n - 1
#     while s % 2 == 0:
#         r += 1
#         s //= 2
#     for _ in range(20):
#         a = random.randrange(2, n - 1)
#         x = pow(a, s, n)
#         if x == 1 or x == n - 1:
#             continue
#         for _ in range(r - 1):
#             x = pow(x, 2, n)
#             if x == n - 1:
#                 break
#         else:
#             return False
#     return True
#
# def randprime():
#     p = int.from_bytes(os.urandom(64), "little")
#     p -= (p%2) - 1
#     while not isPrime(p):
#         p += 2
#     return p
#
# def egcd(a, b):
#     if a == 0:
#         return (b, 0, 1)
#     else:
#         g, y, x = egcd(b % a, a)
#         return (g, x - (b // a) * y, y)
#
# def modinv(a, m):
#     g, x, y = egcd(a, m)
#     if g != 1:
#         return 0
#     else:
#         return x % m
#
# e = 65537
# p = randprime()
# q = randprime()
# N = p*q
# print(f"pubkey = ({N}, {e})")
# phi = (p-1)*(q-1)
# d = modinv(e, phi)
#
# def sign(data):
#     return pow(int.from_bytes(random_hash(data), "little"), d, N).to_bytes(128, "little")
#
# def verify(data, sig):
#     return pow(int.from_bytes(sig, "little"), e, N) == int.from_bytes(random_hash(data), "little")
#
# def unserialize_data(userdata):
#     if userdata[:3] != b"QWB":
#         return '', 0
#     offset = 3
#     name = ''
#     perm = 0
#     while offset < len(userdata):
#         length = int.from_bytes(userdata[offset+1:offset+3], "little")
#         data = userdata[offset+3:offset+3+length]
#         if userdata[offset] == 0xFF:
#             perm = int.from_bytes(data, "little")
#         elif userdata[offset] == 0xCC:
#             name = data
#         else:
#             return '', 0
#         offset += 3 + length
#     return name, perm
#
# def serialize_data(data, permission):
#     return b"QWB"  + \
#            b"\xFF" + b"\x01\x00"                         + permission.to_bytes(1, "little") + \
#            b"\xCC" + len(data).to_bytes(2, "little") + data
#
# def login():
#     userdata = get_user_input("Give me your secret login token: ")
#     sig = userdata[:128]
#     userdata = userdata[128:]
#     if verify(userdata, sig):
#         data, permission = unserialize_data(userdata)
#         if permission == 0xFF:
#             print(f"{flag}")
#         else:
#             print(f"Welcome {data.decode()}!")
#     else:
#         print("Wrong login token, please register first.")
#
# def reg():
#     data = get_user_input("Give me your name: ")
#     userdata = serialize_data(data, 0)
#     userdata = sign(userdata) + userdata
#     print(f"Here's your login token: {userdata.hex()}")
#
# while True:
#     if get_user_input("Register? ") == b'\x00':
#         reg()
#     else:
#         login()



###===================================================================================================================================================================###
###===================================================================================================================================================================###
###===================================================================================================================================================================###
# class Person:
#     'About Persion Class'   #类文档字符串
#     姓名=""
#     属相="";
#     身高=0;
#     体重=0;
#     def __init__(self, 姓名,属相,身高,体重):
#         self.姓名 = 姓名
#         self.属相 = 属相
#         self.身高=身高
#         self.体重=体重
#     def printname(self):
#         print ("Name : ", self.姓名)
#         if self.属相=="狗":
#             print("狗年大吉!")
#     def sing(self):
#         print("回忆啊我们的青春啊")
# test=Person("233","狗",49,175)
# test.printname()
# test.sing()





###===================================================================================================================================================================###
###===================================================================================================================================================================###
###===================================================================================================================================================================###


import time

def calc(n, i=0, cols=0, diags=0, trans=0):
    if i == n:
        return 1
    else:
        rt = 0
        for j in range(n):
            col = 1 << j
            diag = 1 << (i - j + n - 1)
            tran = 1 << (i + j)
            if (col & cols) == 0 and (diag & diags) == 0 and (tran & trans) == 0:
                rt += calc(n, i+1, cols | col, diags | diag, trans | tran)
        return rt

if __name__ == '__main__':
    t = time.time()
    print(calc(13))
    print(time.time() - t)