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

//   "&"与运算
//   1 & 1 = 1;
//   1 & 0 = 0;
//   0 & 0 = 0;
//   作用：取(置)某些为，其它位置为0
  
  printf("取%d第4位:%d\r\n", nNumber, nNumber & 8 == 0 ? 0 : 1);

//   "|" 或运算
//   1 | 1 = 1;
//   1 | 0 = 1;
//   0 | 0 = 0;
//   作用：置某些位，其它位不变

  printf("置%d第2位和第四位1:%X\r\n", nNumber, nNumber | 0xA);

//   "^"异或运算
//   1 ^ 1 = 0;
//   1 ^ 0 = 1;
//   0 ^ 0 = 0;
//   作用：某写位取反

  printf("置%d第3位和第4位取反:%X\r\n", nNumber, nNumber ^ 0xC);

//   "~"按位求反运算
//   作用：间接构造一个数

  printf("构造全为1的数:%X\r\n", ~0);

//   "<<" 左移运算 地位补0
//   作用：移动一次等于 * 2

  printf("2左移后为：%d\r\n", 2 << 2);

//   ">>" 右移运算   高位补符号位
//   作用：移动一次等于 / 2

  printf("8右移后为：%d\r\n", 8 >> 2);
  printf("abs: %d\r\n", Abs(-8));
  printf("abs: %d\r\n", Abs(8));

  return 0;
}
