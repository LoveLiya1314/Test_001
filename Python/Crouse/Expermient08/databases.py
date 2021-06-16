# # -*-coding:UTF-8-*-
# import sqlite3
# conn = sqlite3.connect('user.db')
# c=conn.cursor()
# c.execute('create table User (user varchar(10) primary key,passwd varchar(20))');
# c.execute("insert into User (user, passwd) values('admin','233')")
# Values = c.fetchall()
# print(Values)
# c.close()
# conn.commit()
# import sqlite3
#
# conn = sqlite3.connect('user.db')
# c = conn.cursor()
# a='admi'
# c.execute('select * from User where user=?', (a,))
# Values = c.fetchall()
# print(Values)
# c.close()
# conn.commit()
import tkinter as tk
from tkinter import messagebox
from tkinter.scrolledtext import ScrolledText
import webbrowser
import time
import pymysql
import os

root = tk.Tk()

screen_width = root.winfo_screenwidth()  # 获得屏幕宽度
screen_height = root.winfo_screenheight()  # 获得屏幕高度

root.geometry('%dx%d+%d+%d' % (370, 255, (screen_width - 370) / 2, (screen_height - 255) / 2))
root.resizable(width=False, height=False)

# 判断SAM密码储存文件是否存在
SAM = os.path.exists('./SAM')
if SAM != 1:
    f = open('./SAM', 'w')
    f.close()

with open('./SAM', 'r', encoding='utf-8', errors='ignore') as f:
    user = f.readline()
    passwd = f.readline()

Account_number = user.strip()  # Set account number variable
Account_password = passwd.strip()  # Set Account password variable

# 获取复选按键"0"或"1"
v = tk.IntVar()


def Landing_success():
    with open('./SAM', 'w', encoding='utf-8', errors='ignore') as f:
        if v.get() == 1:
            user = entry1.get()
            passwd = entry2.get()
            f.write(user + '\n')
            f.write(passwd + '\n')
        else:
            user = entry1.get()
            f.write(user + '\n')


def Login_failed():
    phone = entry1.get()
    passwd1 = entry2.get()
    try:
        conn = pymysql.connect(host="127.0.0.1", user="py", passwd="xxxxx", db='mydb', charset='utf8', port=3306)
        cursor = conn.cursor()
        Query_phone = cursor.execute("select phone from user where phone='%s' " % (phone))
        uid_phone = cursor.fetchall()
        uid = uid_phone[0]
        user = ''.join(uid)

        Query_passwd = cursor.execute("select passwd from user where phone='%s' " % (phone))
        uid_passwd = cursor.fetchall()
        uid = uid_passwd[0]
        passwd = ''.join(uid)

        if phone == user and passwd1 == passwd:
            print('success')
            Landing_success()
            root.destroy()
        else:
            failed = tk.Label(root, text="手机号或密码不正确", fg='red')
            failed.place(x=125, y=65)

        # 提交到数据库执行
        conn.commit()
        # 关闭游标
        cursor.close()
        # 关闭连接
        conn.close()

    except IndexError:
        failed = tk.Label(root, text="手机号或密码不正确", fg='red')
        failed.place(x=125, y=65)

    except pymysql.err.OperationalError:
        tk.messagebox.showerror("警告!", "网络不通,联网后重试")


# 定义回车
def enter(self):
    Login_failed()


# Open the registration page
def enrol():
    # webbrowser.open("http://127.0.0.1:3000")
    def register():
        name = entry1.get()
        passwd = entry2.get()
        email = entry3.get()
        phone = entry4.get()
        captcha = entry5.get()
        nums = '1234'

        try:
            conn = pymysql.connect(host="127.0.0.1", user="py", passwd="xxxxx", db='mydb', charset='utf8', port=3306)
            cursor = conn.cursor()
            if len(name) < 1:
                lsb1.delete('end')
                lsb1.insert('end', '请输入用户名')
            elif len(passwd) < 6:
                lsb1.delete('end')
                lsb1.insert('end', '密码长度应为6～16个字符')
            elif len(phone) < 11:
                lsb1.delete('end')
                lsb1.insert('end', '请输入正确的手机号')
            elif captcha != nums:
                lsb1.delete('end')
                lsb1.insert('end', '验证码错误')
            else:
                data = (name, passwd, email, phone, captcha)
                sql = "insert into user(name, passwd, email, phone, captcha) values('%s','%s','%s','%s','%s')" % (data)
                reg = cursor.execute(sql)
                conn.commit()

        except Exception as err:
            print('sql语句', err)

        cursor.close()
        conn.close()

    enrol = tk.Tk()
    enrol.geometry('255x300+%d+%d' % ((screen_width - 750), (screen_height - 300) / 2))
    enrol.resizable(width=False, height=False)

    label1 = tk.Label(enrol, text="*用户名")
    label1.place(x=40, y=50)

    entry1 = tk.Entry(enrol, bd=1, width=18)
    entry1.place(x=88, y=50)

    label2 = tk.Label(enrol, text="*密   码")
    label2.place(x=40, y=90)

    entry2 = tk.Entry(enrol, bd=1, width=18)
    entry2.place(x=88, y=90)

    label3 = tk.Label(enrol, text=" 邮   箱")
    label3.place(x=40, y=130)

    entry3 = tk.Entry(enrol, bd=1, width=18)
    entry3.place(x=88, y=130)

    label4 = tk.Label(enrol, text="*手机号")
    label4.place(x=40, y=170)

    entry4 = tk.Entry(enrol, bd=1, width=18)
    entry4.place(x=88, y=170)

    label5 = tk.Label(enrol, text="*验证码")
    label5.place(x=40, y=204)

    entry5 = tk.Entry(enrol, bd=1, width=6)
    entry5.place(x=88, y=204)

    button2 = tk.Button(enrol, text="获取验证码", bd=1)
    button2.place(x=150, y=200)

    button1 = tk.Button(enrol, text="注册", bd=1, command=register)
    button1.place(x=110, y=235)

    lsb1 = tk.Listbox(enrol, width=32, height=1, fg='red')
    lsb1.place(x=12, y=275)

    enrol.mainloop()


# Binding variable
var1 = tk.Variable()
var1.set(Account_number)  # Set account number value

var2 = tk.Variable()  # Binding variable
var2.set(Account_password)  # Set Account password value

label1 = tk.Label(root, text="手机号")
label1.place(x=72, y=90)

entry1 = tk.Entry(root, bd=1, width=20, textvariable=var1)
entry1.place(x=120, y=90)

label2 = tk.Label(root, text="密   码")
label2.place(x=72, y=130)

entry2 = tk.Entry(root, bd=1, width=20, show="*", textvariable=var2)
entry2.place(x=120, y=130)

button1 = tk.Button(root, bd=1, text="登录", command=Login_failed)
button1.place(x=175, y=180)
entry2.bind("<Return>", enter)

button2 = tk.Button(root, bd=0, text="立即注册", command=enrol)
button2.place(x=308, y=230)

button3 = tk.Button(root, bd=0, text="忘记密码")
button3.place(x=8, y=230)

cipher = tk.Checkbutton(root, bd=0, text="记住密码", variable=v, command=Landing_success)
cipher.select()
cipher.place(x=120, y=155)

root.mainloop()