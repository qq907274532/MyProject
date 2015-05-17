#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  // Open the file 
  FILE* fpFile = NULL;
  fpFile = fopen("TEST.txt", "rb+");
  if(fpFile == NULL)
  {
    fpFile = fopen("TEST.txt", "wb+");
    if(fpFile == NULL)
    {
      exit(-1);
    }
  }

  char szBuf[] = {"changxiaokang"};
  fwrite(szBuf, strlen(szBuf)+1, 1, fpFile);
  fflush(fpFile);
  
  // Access to the file size 
  rewind(fpFile);
  fseek(fpFile, 0, SEEK_END);
  int nFileSize = ftell(fpFile);

  rewind(fpFile);
  char* lpBuf = new char[nFileSize];
  ::ZeroMemory(lpBuf, nFileSize);
  fread(lpBuf, nFileSize, 1, fpFile);
  puts(lpBuf);

  // Check for errors 
  if(!feof(fpFile))
  {
    // No EOF
  }
  if(ferror(fpFile))
  {
    // File point error
  }

  // Close the file 
  if(fpFile)
  {
    fclose(fpFile);
    fpFile = NULL;
  }

  return 0;
}
