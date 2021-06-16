# -*-coding:UTF-8-*-
import tkinter
import tkinter.messagebox

# 创建应用程序窗口
root = tkinter.Tk()
varName = tkinter.StringVar()
varName.set('')
varPwd = tkinter.StringVar()
varPwd.set('')
# 创建标签
labelName = tkinter.Label(root, text='用户名:', justify=tkinter.RIGHT, width=80)
# 将标签放到窗口上
labelName.place(x=10, y=5, width=80, height=20)
# 创建文本框，同时设置关联的变量
entryName = tkinter.Entry(root, width=80, textvariable=varName)
entryName.place(x=100, y=5, width=80, height=20)

labelPwd = tkinter.Label(root, text='密 码:', justify=tkinter.RIGHT, width=80)
labelPwd.place(x=10, y=30, width=80, height=20)
# 创建密码文本框
entryPwd = tkinter.Entry(root, show='*', width=80, textvariable=varPwd)
entryPwd.place(x=100, y=30, width=80, height=20)

# 获取用户名和密码


# 登录按钮事件处理函数
def login():
    name = entryName.get()
    pwd = entryPwd.get()
    import sqlite3
    conn = sqlite3.connect('user.db')
    c = conn.cursor()
    c.execute('select * from User where user=?', (name,))
    Values = c.fetchall()
    if Values:
        c.close()
        conn.commit()
        if (name == Values[0][0]):
            if ( pwd == Values[0][1]):
                tkinter.messagebox.showinfo(title='Python tkinter', message='登录成功！')
            else:
                tkinter.messagebox.showerror('Python tkinter', message='ERROR User Name or Password is Wrong!')
    else:
        tkinter.messagebox.showerror('Python tkinter', message='ERROR:No User Name Or No User Name!')
    # 创建按钮组件，同时设置按钮事件处理函数
buttonOk = tkinter.Button(root, text='登录', command=login)
buttonOk.place(x=20, y=70, width=80, height=40)

# 取消按钮的事件处理函数
def cancel():
    # 清空用户输入的用户名和密码
    varName.set('')
    varPwd.set('')
buttonCancel = tkinter.Button(root, text='取消', command=cancel)
buttonCancel.place(x=100, y=70, width=80, height=40)

# 启动消息循环
root.mainloop()