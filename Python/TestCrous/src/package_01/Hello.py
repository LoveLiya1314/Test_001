
import math
import PIL

def circle(r):
    print(math.pi*r*r)
circle(20)

import sys
for i in range(0,10):
    print(sys.path[i])

from PIL import Image
from PIL import ImageFilter
im = Image.open('test.jpg')
e33 = im.filter(ImageFilter.CONTOUR)
e33.save('E(33).jpg')
