// IO��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#define INT_MAX 2147483647 

streambuf;
ios;

bool InputData( int& nData )
{
  void* lpCin = (cin >> nData);
  
  //��ջ�����
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
    cout << "�������!" << endl;
  }
  
  int nData;
  
  cin >> nData;  //��������������Ͳ�ƥ���ʱ��
  
  if ( cin.good() )
  {
    cout << nData << endl;
  }
  else
  {
    cout << "�������!" << endl;
  }
  
  //��ջ�����
  cin.clear();
  cin.ignore(0x7FFFFFFF,'\n');
  
  
  
  char szdata[5] = {0};
  
  cin.read(szdata,4);
  
  cout << szdata;
  
  return 0;
}


