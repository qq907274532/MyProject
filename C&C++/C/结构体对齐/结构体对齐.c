#include "stdafx.h"
#include <stdio.h>

struct MYDATE
{
  int nYear;
  int nMonth;
  double nDay;
};

#pragma pack(push)
#pragma pack(1)

/*
  结构体变量对齐值 = max(sizeof(成员1), sizeof(成员2)...)
  结构体变量实际对齐值 ＝ mix(结构体变量对齐值, Alignment)
*/

struct PERSON
{
  // min(sizeof(char), Alignment)
  char szName[3];   // [1]
  // min(sizeof(double), Alignment)
  double db;  // [2]
  // min(sizeof(short), Alignment)
  short sn;   // [2]
  struct MYDATE Dob;
  // min(sizeof(float), Alignment)
  float fHeight;  // [2]
};
#pragma pack(pop)

int main(int argc, char* argv[])
{
  struct PERSON jack = 
  {
    "xk",
    1.0,
    1,
    {1992,6,2},
    3.14f
  };

  printf("%d\r\n", sizeof(jack));

  printf("char = %d\r\n", sizeof(char));
  printf("short = %d\r\n", sizeof(short));
  printf("int = %d\r\n", sizeof(int));
  printf("float = %d\r\n", sizeof(float));
  printf("long = %d\r\n", sizeof(long));
  printf("double = %d\r\n", sizeof(double));

  return 0;
}

/*
  33
  char = 1
  short = 2
  int = 4
  float = 4
  long = 4
  double = 8
*/