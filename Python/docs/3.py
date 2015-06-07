#!/usr/bin/python

nNumA = raw_input("Pllease input nNumA : ")
nNumB = raw_input("Pllease input nNumB : ")

if nNumA < nNumB:
	print nNumA, "<", nNumB
elif nNumA == nNumB:
	print nNumA, "=", nNumB
else:
	print nNumA, ">", nNumB


if True and False:
	print "rue and False = Yes"
elif True or False:
	print "True or False = Yes"
elif not False:
	print "not False = Yes"
else:
	print "No"