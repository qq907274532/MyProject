#include <stdio.h>
#include <string.h>

#define N 100

void SetNum(int *nArray, char *cStr);
void Multiplied(int *nArrayA, int *nArrayB, int *nArrayC);

int main(int argc, char* argv[])
{
  int i;
  int nArrayA[N], nArrayB[N], nArrayC[2*N];
  char cStrA[N], cStrB[N];
  int j = 2*N-1;
  
  printf("请输入第一个数字 : ");
  scanf("%s", cStrA);
  printf("请输入第二个数字 : ");
  scanf("%s", cStrB);
  
  SetNum(nArrayA, cStrA);
  SetNum(nArrayB, cStrB);
  Multiplied(nArrayA, nArrayB, nArrayC);    
  while(nArrayC[j] == 0)
  {
    j--;
  }
  
  printf("两大数相称结果为 : ");
  for(i = j; i >= 0; i--)
  {
    printf("%d", nArrayC[i]);
  }
  printf("\n");
  return 0;
}

void SetNum(int *nArray, char *cStr)
{
  int i;
  int nConst = strlen(cStr);
  //对数组进行初始化
  for(i = 0; i < N; i++)
  {
    *(nArray+i) = 0;
  }
  for(i = 0; i < nConst; i++)
  {
    *(nArray+nConst-1-i) = *(cStr+i) - '0';  //将字符串字符转化为整数逆序存储
  }
}

void Multiplied(int *nArrayA, int *nArrayB, int *nArrayC)
{
  int i, j;   
  //数组初始化
  for(i = 0; i < 2*N; i++)
  {
    *(nArrayC+i) = 0;
  }
  //数组a中的每一位与数组b想乘,将结果存入数组c
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      nArrayC[i+j] += nArrayA[i] * nArrayB[j];           
      nArrayC[i+j+1] += nArrayC[i+j]/10;   //将十位上的数向前进位并加上原来的数
      nArrayC[i+j] %= 10;                  //将剩余的数存在原来的位置上
    }
  }
}
