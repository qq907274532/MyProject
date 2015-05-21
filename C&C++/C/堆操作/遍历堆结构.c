#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#include <string.h>

#define MY_FREE(p) if(p){free(p);p=NULL;}

#define nNoMansLandSize 4
typedef struct _CrtMemBlockHeader
{
  struct _CrtMemBlockHeader * pBlockHeaderNext;
  struct _CrtMemBlockHeader * pBlockHeaderPrev;
  char *                      szFileName;
  int                         nLine;
  size_t                      nDataSize;
  int                         nBlockUse;
  long                        lRequest;
  unsigned char               gap[nNoMansLandSize];
  /* followed by:
  *  unsigned char           data[nDataSize];
  *  unsigned char           anotherGap[nNoMansLandSize];
  */
} _CrtMemBlockHeader;

void main()
{
  char *psz1 = NULL;
  char *psz2 = NULL;
  _CrtMemBlockHeader *pHead = NULL;
  int nCount = 1;
  
  psz1 = malloc(5);
  if (psz1 == NULL)
  {
    goto END;
  }
  strcpy(psz1, "Hell");
  
  psz2 = malloc(6);
  if (psz2 == NULL)
  {
    goto END;
  }
  
  //±éÀú¶Ñ
  pHead = (_CrtMemBlockHeader*)((int)psz2 - 32);
  while(pHead != NULL)
  {
    printf("%d: 0x%p\r\n", nCount, pHead);
    printf("BlockHeaderNext: 0x%p\r\n", pHead->pBlockHeaderNext);
    printf("BlockHeaderPrev: 0x%p\r\n", pHead->pBlockHeaderPrev);
    if (pHead->szFileName != NULL)
    {
      printf("FileName: %s\r\n", pHead->szFileName);
    }
    else
    {
      printf("FileName: NULL\r\n");
    }
    printf("Line: %d\r\n", pHead->nLine);
    printf("DataSize: %d\r\n", pHead->nDataSize);
    printf("BlockUse: %d\r\n", pHead->nBlockUse);
    printf("Request: %d\r\n", pHead->lRequest);
    printf("Gap: 0x%p\r\n\r\n", *(int*)pHead->gap);
    
    pHead = pHead->pBlockHeaderNext;
    nCount++;
  }
  
END:
  MY_FREE(psz1);
  MY_FREE(psz2);
}