import sqlite3

conn = sqlite3.connect('stu.db')
c = conn.cursor()
a = input("请输入你想要更新人员的学号：")
b = input("请输入你更新后的人员姓名：")
c.execute("Update addresslist set stuname= ? where stuno =?", (b, a))
c.execute('select * from addresslist where stuno=?', (a,))
Values = c.fetchall()
print(Values)
c.close()
conn.commit()
