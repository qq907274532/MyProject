#include <stdio.h>
#include <Winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

void main(void)
{
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;
  
  wVersionRequested = MAKEWORD( 2, 2 );
  
  err = WSAStartup( wVersionRequested, &wsaData );
  if ( err != 0 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    return;
  }
  
  /* Confirm that the WinSock DLL supports 2.2.*/
  /* Note that if the DLL supports versions greater    */
  /* than 2.2 in addition to 2.2, it will still return */
  /* 2.2 in wVersion since that is the version we      */
  /* requested.                                        */
  
  if ( LOBYTE( wsaData.wVersion ) != 2 ||
    HIBYTE( wsaData.wVersion ) != 2 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    WSACleanup( );
    return; 
  }
  
  /* The WinSock DLL is acceptable. Proceed. */
  
  SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
  
  SOCKADDR_IN addSrv;
  addSrv.sin_family = AF_INET;
  addSrv.sin_port = htons(8888);
  addSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  
  sendto(sockClient, "Hello Word!", strlen("Hello Word!")+1, 0, (SOCKADDR*)&addSrv, sizeof(SOCKADDR));
  closesocket(sockClient);
  WSACleanup();
}