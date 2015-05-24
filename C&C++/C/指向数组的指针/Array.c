#include <stdafx.h>
#include <stdio.h>

int main()
{
  int ary[2][3] = 
  {
    {1, 2, 3},
    {4, 5, 6}
  };

  printf("ary = %p\r\n", ary);
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 3; j++)
      printf("ary[%d][%d] = %p\r\n", i, j, &ary[i][j]);

  // [数组名]是[元素]类型的指针常量
  //  ary 是 int[3] 类型的指针常量
  //  ary[0] 是 int 类型的指针常量
  int *p = ary[0];
  int (*pAry)[3] = ary; 

  printf("p + 1 = %p\r\n", p + 1);
  printf("(int)p + 1 * sizeof(int) ＝ %p\r\n", (int)p + 1 * sizeof(int));
  printf("pAry + 1 = %p\r\n", pAry + 1);
  printf("(int)pAry + 1 * sizeof(int[3]) ＝ %p\r\n", \
        (int)pAry + 1 * sizeof(int[3]));
  
  return 0; 
}

 /*
   ary = 0013FF68
   ary[0][0] = 0013FF68
   ary[0][1] = 0013FF6C
   ary[0][2] = 0013FF70
   ary[1][0] = 0013FF74
   ary[1][1] = 0013FF78
   ary[1][2] = 0013FF7C
   p + 1 = 0013FF6C
   (int)p + 1 * sizeof(int) ＝ 0013FF6C
   pAry + 1 = 0013FF74
  (int)pAry + 1 * sizeof(int[3]) ＝ 0013FF74
*/