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
    char szBuf �� char* szBuf ������:
    char szBuf[] �� �ڴ�������һ��ռ����ַ���
    char* szBuf �� ����һ��char���͵ĵ�ָ���������ַ���
  */

  return 0;
}
