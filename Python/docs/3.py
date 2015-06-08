#!/usr/bin/python
import time

nNumA = raw_input("Pllease input nNumA : ")
nNumB = raw_input("Pllease input nNumB : ")

if nNumA < nNumB:
	print nNumA, "<", nNumB
elif nNumA == nNumB:
	print nNumA, "=", nNumB
else:
	print nNumA, ">", nNumB


print "======================================"

if True and False:
	print "rue and False = Yes"
elif True or False:
	print "True or False = Yes"
elif not False:
	print "not False = Yes"
else:
	print "No"


print "======================================"


for x in "abcde":
	print "55555"

for x in [0, 1, 2, 3, 4, 5, 6, 7]:
	print "88888"

for x in range(3):
	print "3333"

for x in range(1, 6):
	print "55555"

for x in range(1, 9, 2):
	print "44444"

nNum = 0
for x in range(100):
	nNum += x

print nNum


print "======================================"


szName = ["zhang san", "li si", "wang wu", "zhao liu"]

for index in range(len(szName)):
	print szName[index]

szNum = ["One", "Two", "Three", "Four", "Five", "Six"]
for index in szNum:
	print index

print "--------------------------------------"

tagNum = {1:"One", 2:"Two", 3:"Three", 4:"Four", 5:"Five", 6:"Six"}
for index in tagNum:
	print tagNum[index]

for k, v in tagNum.items():
	print k, v

print "--------------------------------------"

for index in range(3):
	print index
	time.sleep(1)
else:
	print "endint"

print "--------------------------------------"

index = 0
while index < 5:
	print "Hello, word!"
	index+=1