#!/usr/bin/python

szStrA = 'Hello, word!'
szStrB = "Hello, wrod!"
szStrC = """Hello, word!"""
szStrD = """tom:
	I am jack
	good bye
"""
print szStrA
print szStrB
print szStrC
print "Let's go"
print """Let's "go" """
print "Let's \"go\""
print 'tom:\r\n Hello\r\n I am jack'

print "szStrA type is", type(szStrA)
print "szStrB type is", type(szStrB)
print "szStrC type is", type(szStrC)


print "==========================="
szStr = "chang xiaokang"
print szStr[6] + szStr[10]
print szStr[6:15]
print szStr[:5]
print szStr[6:14]
print szStr[::1]
print szStr[::2]
print szStr[-5]
print szStr[:-9]

print "==========================="
szStr1 = "12345"
szStr2 = "67890"
print "szStr1 len = ", len(szStr1)
print szStr1 + szStr2
print szStr1 * 5
print '246' in szStr1
print '678' in szStr2
print max(szStr1)
print min(szStr2)
print cmp(szStr1, szStr2)

print "==========================="
tagStudent = ("xiaokang", 23, "GG", "BeiJing")
print tagStudent[0]
print tagStudent[1]
print tagStudent[2]
print tagStudent[3]

szName, nAge, szSex, szAdd = tagStudent
print szName, nAge, szSex, szAdd


print "==========================="
tagStudent = ["xiaokang", 23, "GG"]
tagStudent.append("BeiJing")
tagStudent.append("18500607454")
print tagStudent
print tagStudent.count("xiaokang")


print "==========================="
tagType = ["szName", "nAge", "szSex"]
tagStu = ["xiaokang", 23, "GG"]
print zip(tagType, tagStu)

dic = {0:0, 1:1, 2:2, 3:3}
print dic[0], dic[1], dic[2], dic[3]

szName = "Name"
nAge = "Age"
szSex = "Sex"
szAdd = "Add"
dStu = {szName:"xk", nAge:18, szSex:"MM", szAdd:"WuHan"}
print dStu[szName], dStu[nAge], dStu[szSex], dStu[szAdd]

for k in dStu:
	print dStu[k]