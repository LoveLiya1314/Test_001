import sqlite3

conn = sqlite3.connect('stu.db')
c = conn.cursor()
a = input("请输入你想要删除的学生的姓名：")
c.execute("Delete from  addresslist where stuname = '{}'".format(a))
c.execute('select * from addresslist')
Values = c.fetchall()

print(Values)
c.close()
conn.commit()
