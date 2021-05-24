# -*-coding:UTF-8-*-
from PIL import Image

image = Image.open('00048.jpg')
print(image.mode, image.size, image.format)
image.show()
grey_image = image.convert('L')
grey_image.show()
