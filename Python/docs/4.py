#!/usr/bin/python
#coding:utf-8

from __future__  import division

def StrCmp(nX, nY = 100):
	if nX == nY:
		print nX, "=", nY
	elif nX > nY:
		print nX, ">", nY
	elif nX < nY:
		print nX, "<", nY

StrCmp(25, 28)
StrCmp(20)

print "==================================="
def fun():
	return "Hello, wrod!"

fun()

print "==================================="
def Add(nX, nY):
	return nX + nY

def Sub(nX, nY):
	return nX - nY

def Mul(nX, nY):
	return nX * nY

def Div(nX, nY):
	return nX / nY

# def Operator(nX, o, nY):
# 	if o == "+":
# 		print Add(nX, nY)

# 	elif o == "-":
# 		print Sub(nX, nY)

# 	elif o == "*":
# 		print Mul(nX, nY)

# 	elif o == "/":
# 		print Div(nX, nY)

# 	else:
# 		pass

Operator = {"+":Add, "-":Sub, "*":Mul, "/":Div}

def Oper(nX, szOper, nY):
	print Operator.get(szOper)(nX, nY)

nNumA = int(raw_input("Plase input nNumA:"))
nNumB = int(raw_input("Plase input nNumB:"))
szOper = raw_input("Plase input operation method:")
Oper(nNumA, szOper, nNumB)