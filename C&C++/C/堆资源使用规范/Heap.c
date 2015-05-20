// TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  // Set point to NULL
  char *psz = NULL;

  // Get heap
  psz = (char*)malloc(strlen("Hello, word!") + 1);

  // Check it
  if(NULL == psz)
  {
    // Error proc
    goto END_PROC;
  }

  // Use heap
  strcpy(psz, "Hello, word!");

  // Safe free
  if(psz)
  {
    free(psz);  // Free heap
    psz = NULL; // Set point to NULL
  }

  // Safe exit
END_PROC:
  if(psz)
  {
    free(psz);
    psz = NULL;
  }

  system("pause");

  return 0;
}
