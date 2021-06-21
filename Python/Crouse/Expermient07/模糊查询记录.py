import sqlite3

conn = sqlite3.connect('stu.db')
c = conn.cursor()
c.execute('select * from addresslist where stuname like "%王%" ')
Values = c.fetchall()
print(Values)
c.close()
conn.commit()
