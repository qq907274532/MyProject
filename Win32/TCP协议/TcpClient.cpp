#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

void main(void)
{
  //套节字初始化
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;
  
  wVersionRequested = MAKEWORD( 1, 1 );
  
  err = WSAStartup( wVersionRequested, &wsaData );
  if ( err != 0 ) 
  {	
    return;
  }
  
  if ( LOBYTE( wsaData.wVersion ) != 1 ||
    HIBYTE( wsaData.wVersion ) != 1 ) 
  {
    WSACleanup( );
    return; 
  }
  
  //创建套节字对象
  SOCKET sockClient;
  sockClient = socket(AF_INET, SOCK_STREAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  
  //请求与服务器连接
  connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
  
  char recvBuf[100];
  //接受数据
  recv(sockClient, recvBuf, 100, 0);
  printf("%s\r\n", recvBuf);
  
  //发送数据
  send(sockClient, "This is KangKang", strlen("This is KangKang") + 1, 0);
  
  //关闭套节字
  if(SOCKET_ERROR == closesocket(sockClient))
    printf("Error\r\n");
  
  //终止Winsock 2 DLL (Ws2_32.dll) 的使用
  WSACleanup();
}