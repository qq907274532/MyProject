#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//共用体
union MyTest
{
  char   m_Char;
  short  m_Short;
  int    m_Int;
  double m_Double;
};

//枚举
enum MyType{TYPE_CHAR = 1, TYPE_SHORT = 3, 
TYPE_INT = 100, TYPE_DOUBLE};

struct tagStudent
{
  enum MyType  m_Type;
  char         m_szName[10];  
  union MyTest m_Score;
};

void ShowScore(struct tagStudent *pStu)
{
  switch(pStu->m_Type)
  {
  case TYPE_CHAR:
    {
      printf("%C\r\n", pStu->m_Score.m_Char);
      break;
    }
  case TYPE_DOUBLE:
    {
      printf("%lf\r\n", pStu->m_Score.m_Double);
      break;
    }
  }
}

void main()
{
  //共用体
  union MyTest Test;
  printf("Union:\r\n");
  printf("union size: %d\r\n", sizeof(union MyTest)); 
  Test.m_Char = 'A';
  printf("%c\r\n", Test.m_Char);
  Test.m_Short = 1;
  printf("%d\r\n", Test.m_Short);
  Test.m_Int = 2;
  printf("%d\r\n", Test.m_Int);
  Test.m_Double = 2.25;
  printf("%lf\r\n\r\n", Test.m_Double);
  
  //枚举
  {
    enum MyType Test2;
    printf("Enum:\r\n");
    Test2 = TYPE_CHAR;
    printf("%d\r\n", Test2);
    Test2 = TYPE_SHORT;
    printf("%d\r\n", Test2);
    Test2 = TYPE_INT;
    printf("%d\r\n", Test2);
    Test2 = TYPE_DOUBLE;
    printf("%d\r\n\r\n", Test2);
  }
  
  //例子
  {
    struct tagStudent stu1;
    struct tagStudent stu2;
    printf("Score:\r\n");
    strcpy(stu1.m_szName, "LiLei");
    stu1.m_Type = TYPE_CHAR;
    stu1.m_Score.m_Char = 'A';
    printf("%s\r\n", stu1.m_szName);
    ShowScore(&stu1);
    printf("\r\n");
    
    strcpy(stu2.m_szName, "HanMeimei");
    stu2.m_Type = TYPE_DOUBLE;
    stu2.m_Score.m_Double = 60.4;
    printf("%s\r\n", stu2.m_szName);
    ShowScore(&stu2);
  }
  system("pause");
}

/*
Union:
union size: 8
A
1
2
2.250000

  Enum:
  1
  3
  100
  101
  
    Score:
    LiLei
    A
    
      HanMeimei
      60.400000
*/