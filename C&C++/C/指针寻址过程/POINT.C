#include <stdafx.h>
#include <stdio.h>

int main()
{
  int n = 9;
  int* p = NULL;    // 变量 [p] 是一个指针变量，将所存储地址解释为 [int]
  int** pp = NULL;  // 变量 [pp] 是一个指针变量，将所存储地址解释为 [int*]

  p = &n;
  pp = &p;

  printf("p = %p\r\n", p);
  printf("pp = %p\r\n", pp);
  printf("*pp = %p\r\n", *pp);
  printf("**pp = %p\r\n", **pp);

  int ary[2][3] = 
  {
    1, 2, 3, 
    4, 5, 6
  };

  // 定义一个[*]类型的指针变量[*],保存[*]的地址。
  // type *p;
  // *p => 访问指针变量[p]的地址，取出其中的值，
  // 将其值视为地址，并再次访问。
  // 访问后，将目标地址解释为[type]类型的数据

  // type Ary[M];
  // [Ary]是数组名称，等价于类型为[type]的指针变量，
  // 用于表示第0个元素的地址

  // 定义一个int [3]类型的指针变量pAry,保存ary的地址
  int (*pAry)[3] = ary;
  // pAry++; => + sizeof(int[3])
  

  // **pAry
  // *pAry => 访问指针变量pAry的地址，取出其中的值，
  // 将其值视为地址，并再次访问。
  // 访问后，将目标地址解释为int[3]类型数据
  // *pAry得到数据int[3]，*pAry等价于数组名称
  // *pAry是数据名称，等价于类型为int的指针常量，
  
  // *(*pAry)访问指针变量*pAry的地址，取出其中的值，
  // 将其视为地址，并再次访问。
  // 访问后，将目标地址解释为int类型的数据

  printf("**pAry+0 = %p\r\n", **pAry);
  printf("**pAry+1 = %p\r\n", **pAry+1);
  printf("**pAry+2 = %p\r\n", **pAry+2);
  printf("**pAry+3 = %p\r\n", **pAry+3);
  printf("**pAry+4 = %p\r\n", **pAry+4);
  printf("**pAry+5 = %p\r\n", **pAry+5);

  // 定义一个int*类型的指针变量pp,保存强制转换后ary的地址
  // int** pp = (int**)ary;
  // pp++; // ＋ sizeof(int*)

  // **pp
  // *p => 访问指针变量pp的地址，取出其中的值
  // 将其值视为地址，并再次访问
  // 访问后，将目标地址解释为int*类型的数据
  // *pp得到int*,*pp等价于int*

  // *(*pp)访问指针变量*pp的地址，取出其中的值，
  // 将其视为地址，并再次访问。
  // 访问后，将目标地址解释为int类型的数据
  // printf("%p\r\n", **pp);

  return 0; 
}

/*
  p = 0013FF7C
  pp = 0013FF78
  *pp = 0013FF7C
  **pp = 00000009
  **pAry+0 = 00000001
  **pAry+1 = 00000002
  **pAry+2 = 00000003
  **pAry+3 = 00000004
  **pAry+4 = 00000005
  **pAry+5 = 00000006
*/