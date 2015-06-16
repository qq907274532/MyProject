#!/usr/bin/python
import re
import urllib

def LoopUrl(szBuf):
	nNum = 2
	for x in range(56):
		Urllist = szBuf + (str(nNum + x))

		print Urllist

		page = urllib.urlopen(Urllist)
		szHtml = page.read()

		reg = r'href=\'(http://girl-atlas.com/a/[0-9]{20,20})\'>'
		url = re.compile(reg)

		for strUrl in url:
			res = r'src=\'(.*?\.jpg!mid)\''
			ImgRe = re.compile(res)
			imglist = re.findall(res, ImgRe)
			x = 0
			for imgurl in imglist
				urllib.urlretrieve(imgurl, '%s.jpg' %x)
				print imgurl
				x+=1

LoopUrl("http://girl-atlas.com/t/")
