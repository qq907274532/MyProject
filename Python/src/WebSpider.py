#!/usr/bin/python
import re
import urllib

def getHtml(url):
	page = urllib.urlopen(url)
	html = page.read()
	return html

def getImg(html):
	reg = r'src=\'(.*?\.jpg!mid)\''
	imgre = re.compile(reg)
	imglist = re.findall(imgre, html)
	x = 0
	for imgurl in imglist:
		urllib.urlretrieve(imgurl, '%s.jpg' %x)
		print imgurl
		x+=1

html = getHtml("http://girl-atlas.com/a/10150201145400000135")
getImg(html)
