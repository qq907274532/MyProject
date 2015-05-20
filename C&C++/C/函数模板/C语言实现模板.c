#include "stdafx.h"
#include <stdio.h>

/*
  C语言实现函数模板
*/

#define MY_GETAREA(type)\
type GetArea(type x, type y)\
{\
  return x*y;\
}

#define CALL_GETAREA(type) GetArea

// 模板实例化
MY_GETAREA(int);
// int GetArea(int x, int y)
// {
//   return x*y;
// }

MY_GETAREA(float);
// int GetArea(float x, float y)
// {
//   return x*y;
// }

int main(int argc, char* argv[])
{
  printf("%d\r\n", CALL_GETAREA(int)(1, 2));
  printf("%f\r\n", CALL_GETAREA(float)(1.0f, 2.0f));

  return 0;
}
