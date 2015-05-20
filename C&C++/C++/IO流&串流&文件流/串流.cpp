// 串流.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <strstrea.h>
#include <iomanip.h>

int main(int argc, char* argv[])
{
  __int64 li = (__int64)7000000000;
  
  char szData[20] = {0};
  
  sprintf(szData,"%I64",li);
  
  cout << hex << (int)(li >> 32) << (int)li << endl;
  
  cout << setw(5) << hex  << 1;
  
  //不好用  推荐MyString
  istrstream istr("Hello");
  
  char szBuffer[20];
  
  istr >> szBuffer;
  
  cout << szBuffer << endl;
  
  cout << istr.str()  << endl;
  
  //不好用  推荐MyString
  ostrstream ostr;
  
  ostr << "sdfdasfdasf" << '\0';
  
  cout << ostr.str()  << endl;
  
  return 0;
}

