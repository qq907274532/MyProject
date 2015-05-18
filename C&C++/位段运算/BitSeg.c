#include <stdio.h>
#include <Windows.h>

struct tagFlag
{
  unsigned short Flag1: 1;  //低位
  unsigned short      : 2;  //无名位段，占用不使用
  unsigned short Flag2: 4;
  unsigned short      : 0; //为0从下一个类型大小位置开始
  unsigned short Flag3: 4; //高位
};

union MyFloat
{
  struct tagFloat
  {
    unsigned  Data : 23;  
    unsigned  Index: 8; //127
    unsigned  Sign : 1; 
  };
  float m_fNumber;
};

//ULONGLONG不是标准
union MyDouble
{
  struct tagDouble
  {
    ULONGLONG  Data : 52;  
    ULONGLONG  Index: 11; //1023
    ULONGLONG  Sign : 1; 
  };
  double m_dNumber;
};

void main()
{
  struct tagFlag flag = {0};
  printf("size: %d\r\n", sizeof(struct tagFlag));
  flag.Flag1 = 3;
  printf("Flag1: %x\r\n", flag.Flag1);
  flag.Flag2 = 3;
  printf("Flag2: %d\r\n", flag.Flag2);
  flag.Flag3 = 3;
  printf("Flag3: %d\r\n\r\n", flag.Flag3);
  
  //   {
  //     struct tagFloat *pFloat = NULL;
  //     float fNumber = -3.14f;
  //     printf("Sign: %d\r\n", 
  //            ((struct tagFloat *)&fNumber)->Sign);
  //     printf("Index: %d\r\n", 
  //            ((struct tagFloat *)&fNumber)->Index);
  //     printf("Sign: 0x%X\r\n", 
  //            ((struct tagFloat *)&fNumber)->Data);
  //   }
  {
    union MyFloat Float;
    union MyDouble Double;
    
    printf("Float:\r\n");
    Float.m_fNumber = -3.14f;
    printf("Sign: %d\r\n",   Float.Sign);
    printf("Index: %d\r\n",  Float.Index);
    printf("Data: 0x%X\r\n\r\n", Float.Data);
    
    printf("Double:\r\n");
    Double.m_dNumber = -3.14;
    printf("Sign: %d\r\n",   Double.Sign);
    printf("Index: %d\r\n",  Double.Index);
    printf("Data: 0x%X\r\n\r\n", Double.Data);
  }
}

/*
  运行结果：

  size: 4
  Flag1: 1
  Flag2: 3
  Flag3: 3

  Float:
  Sign: 1
  Index: 128
  Data: 0x48F5C3

  Double:
  Sign: 1
  Index: 1024
  Data: 0x51EB851F

*/