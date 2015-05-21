// SmartPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

class UseRefClass
{
private:
  int m_nRefCount;
  
public:
  UseRefClass()
  {
    m_nRefCount = 1;
  }
  virtual ~UseRefClass()
  {
    m_nRefCount = 0;
  }
  void AddRef()
  {
    m_nRefCount++;
  }
  void Release()
  {
    if(--m_nRefCount == 0)
    {
      delete this;
    }
  }
};

class Student : public UseRefClass
{
public:
  void SayHello() 
  {
    cout << "SayHello" << endl;
  }
};

class NoAddRefStudent : public Student
{
private:
  void AddRef();
  void Release();
};

class SmartPtr
{
public:
  SmartPtr()
  {
    m_lpData = NULL;
  }
  
  virtual ~SmartPtr()
  {
    Release();
  }
  
  void CreateInstance()  //²úÉúÊµÀý
  {
    if(m_lpData == NULL)
      m_lpData = new Student;
  }
  
  void Attach(Student* lpStu)
  {
    m_lpData = lpStu;
    m_lpData->AddRef();
  }
  
  void Release()
  {
    if(m_lpData)
    {
      m_lpData->Release();
      m_lpData = NULL;
    }
  }
  
  NoAddRefStudent* operator->()
  {
    return (NoAddRefStudent*)m_lpData;
  }
  
  Student operator*()
  {
    return *m_lpData;
  }
  
  Student** operator&()
  {
    return &m_lpData;
  } 
  
private:
  Student* m_lpData;
};

int main(int argc, char* argv[])
{
  SmartPtr sp;
  Student* lpStu = new Student;
  
  sp.Attach(lpStu);
  sp->SayHello();
  sp.Release();
  delete lpStu;
  
  sp.CreateInstance();
  sp.CreateInstance();
  sp.Release();
  
  cout << "Hello Word" << endl;
  
  return 0;
}
