// 文件流.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream.h"
#include <string.h>

void TestReadFile()
{
  ifstream ifile;
  
  ifile.open("readme.txt");
  
  if ( ifile )
  {
    ifile.seekg(50,ios::beg);
    
    char szBuffer[10];
    
    ifile.read(szBuffer,sizeof(szBuffer));
    
    ifile.seekg(0,ios::beg);
    
    while ( !ifile.eof() )
    {
      char szBuffer[256] = {0};
      
      ifile.read(szBuffer,sizeof(szBuffer)-1);
      
      cout << szBuffer << flush;
    }    
  }
}


class student
{
public:
  student()
  {
    m_lpName = NULL;
    m_nAge   = 0;
  }
  student( char* lpName, int nAge)
  {
    m_lpName = new char[strlen(lpName)+1];
    strcpy(m_lpName,lpName);
    m_nAge = nAge;
  }
  void SetName( const char* lpName )
  {
    if ( m_lpName != NULL )
    {
      delete[] m_lpName;
      m_lpName = NULL;
    }
    m_lpName = new char[strlen(lpName)+1];
    strcpy(m_lpName,lpName);
  }
  virtual ~student()
  {
    if ( m_lpName != NULL )
    {
      delete[] m_lpName;
      m_lpName = NULL;
    }
  }
private:
  int m_nAge;
  char* m_lpName;
  friend ofstream& operator <<( ofstream& of, const student& stu );
  friend ifstream& operator >> ( ifstream& of,  student& stu );
};

ifstream& operator >> ( ifstream& ifile,  student& stu )
{
  int nLen;
  
  ifile >> nLen;
  
  char* lpNew = new char[nLen+1];
  
  ifile.read(lpNew,nLen);
  
  lpNew[nLen] = '\0';
  
  ifile >> stu.m_nAge;
  
  stu.SetName(lpNew);
  
  delete[] lpNew;
  
  return ifile;
}

ofstream& operator << ( ofstream& of, const student& stu )
{
  of << strlen(stu.m_lpName);
  
  of << stu.m_lpName;
  
  of << stu.m_nAge;
  
  return of;
}

int main(int argc, char* argv[])
{
  {
    ofstream ofile;
    
    ofile.open("student.txt");
    
    if ( ofile )
    {
      ofile.seekp(20,ios::beg);
      
      student stu1("张三",20);
      
      ofile << stu1;
    }
  }
  
  {
    ifstream ifile;
    
    ifile.open("student.txt");
    
    if ( ifile )
    {
      ifile.seekg(20,ios::beg);
      
      student tempstu;
      
      ifile >> tempstu;
    }
  }
  return 0;
}

