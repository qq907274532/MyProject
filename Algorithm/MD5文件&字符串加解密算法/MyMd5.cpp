// MyMd5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "md5.h"

int main(int argc, char* argv[])
{
	printf("MD5 Key of the phrase 'md5Test' = <%s>\n", MD5String("md5Test"));
	printf("MD5 Key of the file 'md5.cpp' = <%s>\n", MD5File("md5.cpp"));

	return 0;
}

