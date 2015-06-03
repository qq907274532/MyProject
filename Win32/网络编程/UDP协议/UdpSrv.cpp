#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

void main(void)
{
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;
  wVersionRequested = MAKEWORD( 2, 2 );
  err = WSAStartup( wVersionRequested, &wsaData );
  if ( err != 0 ) {
    return;
  }
  if ( LOBYTE( wsaData.wVersion ) != 2 ||
    HIBYTE( wsaData.wVersion ) != 2 ) {
    WSACleanup( );
    return; 
  }
  
  SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
  
  bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
  
  SOCKADDR_IN addrClient;
  int nLen = sizeof(SOCKADDR);	
  char recvBuf[100];	
  
  recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &nLen);
  printf("%s\r\n", recvBuf);
  
  closesocket(sockSrv);
  WSACleanup();
}