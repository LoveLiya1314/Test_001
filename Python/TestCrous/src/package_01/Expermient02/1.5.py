# -*-coding:UTF-8-*-

import matplotlib.pyplot as plt
import numpy as np
from pylab import *

xticks(np.linspace(2021, 2040, 20, endpoint=True))
plt.xticks(rotation=250)
i = 0
y = [10000]
y[0] = y[0] * 1.05
x = [2021]
for i in range(2022, 2041):
    x.append(i)
    y.append(y[i - 2022] * 1.05)
    print("%d  %.2f" % (x[i-2022], y[i-2022]))
print("%d  %.2f" % (x[19], y[19]))
plt.title("Matplotlib ")
plt.xlabel("x axis caption")
plt.ylabel("y axis caption")
plt.plot(x, y)
plt.show()
