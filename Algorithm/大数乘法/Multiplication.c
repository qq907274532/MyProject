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
  
  printf("�������һ������ : ");
  scanf("%s", cStrA);
  printf("������ڶ������� : ");
  scanf("%s", cStrB);
  
  SetNum(nArrayA, cStrA);
  SetNum(nArrayB, cStrB);
  Multiplied(nArrayA, nArrayB, nArrayC);    
  while(nArrayC[j] == 0)
  {
    j--;
  }
  
  printf("��������ƽ��Ϊ : ");
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
  //��������г�ʼ��
  for(i = 0; i < N; i++)
  {
    *(nArray+i) = 0;
  }
  for(i = 0; i < nConst; i++)
  {
    *(nArray+nConst-1-i) = *(cStr+i) - '0';  //���ַ����ַ�ת��Ϊ��������洢
  }
}

void Multiplied(int *nArrayA, int *nArrayB, int *nArrayC)
{
  int i, j;   
  //�����ʼ��
  for(i = 0; i < 2*N; i++)
  {
    *(nArrayC+i) = 0;
  }
  //����a�е�ÿһλ������b���,�������������c
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      nArrayC[i+j] += nArrayA[i] * nArrayB[j];           
      nArrayC[i+j+1] += nArrayC[i+j]/10;   //��ʮλ�ϵ�����ǰ��λ������ԭ������
      nArrayC[i+j] %= 10;                  //��ʣ���������ԭ����λ����
    }
  }
}
