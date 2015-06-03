// IO流.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#define INT_MAX 2147483647 

streambuf;
ios;

bool InputData( int& nData )
{
  void* lpCin = (cin >> nData);
  
  //清空缓冲区
  cin.clear();
  cin.ignore(INT_MAX,'\n');
  
  int nData1;
  cin >> nData1;
  
  return lpCin!=NULL;
}

int main(int argc, char* argv[])
{
  //istream_withassign 
  
  if ( InputData(argc ) )
  {
    cout << "argc" << argc << endl;
  }
  else
  {
    cout << "输入错误!" << endl;
  }
  
  int nData;
  
  cin >> nData;  //当输入的数据类型不匹配的时候
  
  if ( cin.good() )
  {
    cout << nData << endl;
  }
  else
  {
    cout << "输入错误!" << endl;
  }
  
  //清空缓冲区
  cin.clear();
  cin.ignore(0x7FFFFFFF,'\n');
  
  
  
  char szdata[5] = {0};
  
  cin.read(szdata,4);
  
  cout << szdata;
  
  return 0;
}


