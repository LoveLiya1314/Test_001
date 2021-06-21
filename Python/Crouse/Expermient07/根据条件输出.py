import sqlite3

conn = sqlite3.connect('stu.db')
c = conn.cursor()
a = input("请输入你想要查询的学号信息：")
c.execute('select * from addresslist where stuno=?', (a,))
# c.execute('select * from addresslist')
Values = c.fetchall()
print(Values)
c.close()
conn.commit()
