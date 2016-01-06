#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: pythonchallenge7 
# Created: 2016-01-06 16:00:35
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#   本关提示少， 只有图片， 涉及到 图片， 灰度等
#  
#####################################################

# 首先是用库， 读图片
# 其次是图片中部的那个灰度条， 要用 ascii码 解析

import Image

im = Image.open("oxygen.png")
print im.format, im.mode, im.size

w,h=im.size

print ''.join([chr(im.getpixel((i,h//2))[0]) for i in range(0,w,7)])

print ''.join(map(chr,[105, 110, 116, 101, 103, 114, 105, 116, 121]))

