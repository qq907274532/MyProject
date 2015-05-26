#include "stdafx.h"
#include <stdio.h>

void BubbleSort(int arr[], int len)
{
  int i, j, temp;
  for (i = 0; i < len - 1; i++)
  {
    for (j = 0; j < len - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1]) 
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
  int len = (int)sizeof(arr) / sizeof(*arr);

  BubbleSort(arr, len);

  for(int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  
  printf("\r\n");

  return 0;
}
