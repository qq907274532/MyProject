#include <stdafx.h>
#include <stdio.h>

int MyStrCmp(const char* szSrc, const char* szDes)
{
  int nRet = 0;

  while( ! (nRet = *(char*)szSrc - *(char*)szDes) && *szDes )
    ++szSrc, ++szDes;

  if(nRet < 0)
    nRet = -1;  // szSrc > szDes
  else if(nRet > 0)
    nRet = 1;   // szSrc < szDes
  else
    nRet = 0;   // szSrc == szDes

  return nRet;
}

int main()
{
  char* szSrc = new char[30];
  char* szDes = new char[30];
  scanf("%s", szSrc);
  scanf("%s", szDes);

  if(MyStrCmp(szSrc, szDes) < 0)
    puts("szSrc > szDes");
  else if(MyStrCmp(szSrc, szDes) > 0)
    puts("szSrc < szDes");
  else if(MyStrCmp(szSrc, szDes) == 0)
    puts("szSrc == szDes");

  return 0;
}