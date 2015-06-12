#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>

char* MyStrCpy(char* szDst, const char* szSrc)
{
  char* szTemp = szDst;

  while(*szTemp++ = *szSrc++) ;

  return szDst;
}

int main()
{
  char* szBuf = "changxiaokang";
  char* szTemp = new char[13];
  if(NULL == szTemp)
  {
    exit(-1);
  }

  MyStrCpy(szTemp, szBuf);
  puts(szTemp);

  if(szTemp)
  {
    delete szTemp;
    szTemp = NULL;
  }

  return 0;
}
