#!/usr/bin/python
#coding:utf8

import re

p = re.compile("ab")

s1 = "tcp"
s2 = "tcp tbp tcp"
s3 = "tap tbp tcp tbp tcp tdp"
s4 = "tcp tbp tcp tdp tep tfp"
s5 = "tcp tbp tcp tdp tep tfp"
s6 = "tcp tbp tcp tdp tep tfp"

re1 = r"tcp" 		# 匹配 tcp的任意字符
re2 = r"t[a-z]p" 	# 匹配 t[这里表示任意字符]p
re3 = r"t[cd]p" 	# 匹配 t[c或者d]p
re4 = r"^tap" 		# 匹配 开头为tap的字符
re5 = r"tfp$"		# 匹配 结尾为tfp的字符
re6 = r"t[^def]" 	# 匹配 t[不包含def]的字符
re7 = r"t[0-9a-zA-Z]" # 匹配 t[0-9a-zA-Z]之间字符




print re1, re.findall(re1, s1)
print re2, re.findall(re2, s2)
print re3, re.findall(re3, s3)
print re4, re.findall(re4, s4)
print re5, re.findall(re5, s5)
print re6, re.findall(re6, s6)