#include <stdafx.h>
#include <stdio.h>

#define BUFFER_SIZE 1024  // ��ʶ������
#define NUMBERS 1, \
                2, \
                3
#define MIN(x, y) ((x) < (y)) ? (x) : (y)   // �꺯��

#define WARN_IF(EXP) \
        do { if(EXP) \
          fprintf(stderr, "Warning: "#EXP "\r\n"); } \
        while(0)  // �ַ�����

int main()
{
  char szBuf[BUFFER_SIZE] = {0};
  int nX[] = {NUMBERS};

  printf("%d\r\n", MIN(5, 8));
  WARN_IF(nX != 0);

  return 0;
}