#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class CIterator
{
public:
  CIterator(char* pszBuf):pszBuf(pszBuf)
  {
    pszBuf = NULL;
  }
  ~CIterator()
  {
  }

public:
  char*& operator++()
  {
    pszBuf += 1;
    return pszBuf;
  }

private:
  char* pszBuf;
};


int main(int argc, char* argv[])
{
  char* pszBuf = "Hello, word!";

  CIterator it(pszBuf);
  cout << "++֮ǰ" << pszBuf << endl;

  char* pszBuffer = ++it;
  cout << "++֮��" << pszBuffer << endl;

  return 0;
}
