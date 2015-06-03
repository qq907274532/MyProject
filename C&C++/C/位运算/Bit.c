#include "stdafx.h"
#include <stdio.h>

int Abs(int nNumber)
{
//   x ^ 1 = ~x;
//   x ^ 0 = x;
  return (nNumber ^ (nNumber >> 31)) - (nNumber >> 31);
}

int main(int argc, char* argv[])
{
  int nNumber = 5;

//   "&"������
//   1 & 1 = 1;
//   1 & 0 = 0;
//   0 & 0 = 0;
//   ���ã�ȡ(��)ĳЩΪ������λ��Ϊ0
  
  printf("ȡ%d��4λ:%d\r\n", nNumber, nNumber & 8 == 0 ? 0 : 1);

//   "|" ������
//   1 | 1 = 1;
//   1 | 0 = 1;
//   0 | 0 = 0;
//   ���ã���ĳЩλ������λ����

  printf("��%d��2λ�͵���λ1:%X\r\n", nNumber, nNumber | 0xA);

//   "^"�������
//   1 ^ 1 = 0;
//   1 ^ 0 = 1;
//   0 ^ 0 = 0;
//   ���ã�ĳдλȡ��

  printf("��%d��3λ�͵�4λȡ��:%X\r\n", nNumber, nNumber ^ 0xC);

//   "~"��λ������
//   ���ã���ӹ���һ����

  printf("����ȫΪ1����:%X\r\n", ~0);

//   "<<" �������� ��λ��0
//   ���ã��ƶ�һ�ε��� * 2

  printf("2���ƺ�Ϊ��%d\r\n", 2 << 2);

//   ">>" ��������   ��λ������λ
//   ���ã��ƶ�һ�ε��� / 2

  printf("8���ƺ�Ϊ��%d\r\n", 8 >> 2);
  printf("abs: %d\r\n", Abs(-8));
  printf("abs: %d\r\n", Abs(8));

  return 0;
}
