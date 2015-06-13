#!/usr/bin/python
#coding:utf-8

def StrCmp(nX, nY = 100):
	if nX == nY:
		print nX, "=", nY
	elif nX > nY:
		print nX, ">", nY
	elif nX < nY:
		print nX, "<", nY


nNumA = raw_input("Plase input nNumA:")
nNumB = raw_input("Plase input nNumB:")

StrCmp(nNumA, nNumB)
StrCmp(20)

print "==================================="

