#include <stdafx.h>
#include <stdio.h>

int main()
{
  char szBuf[] = {"xiaokang"};
  int nSize = sizeof(szBuf);

  printf("%08X-%c\r\n", szBuf, *szBuf+0);
  printf("%08X-%c\r\n", szBuf+1, *(szBuf+1));
  printf("%08X-%c\r\n", szBuf+2, *(szBuf+2));
  printf("%08X-%c\r\n", szBuf+3, *(szBuf+3));
  printf("%08X-%c\r\n", szBuf+4, *(szBuf+4));
  printf("%08X-%c\r\n", szBuf+5, *(szBuf+5));
  printf("%08X-%c\r\n", szBuf+6, *(szBuf+6));
  printf("%08X-%c\r\n", szBuf+7, *(szBuf+7));
  printf("%08X-%c\r\n", szBuf+8, *(szBuf+8));

  /*
    char szBuf 和 char* szBuf 的区别:
    char szBuf[] ： 内存中申请一块空间存放字符串
    char* szBuf ： 定义一个char类型的的指针变量存放字符串
  */

  return 0;
}
