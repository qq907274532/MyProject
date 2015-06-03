#include <stdio.h>
#include <winsock2.H>

#pragma comment(lib, "Ws2_32.lib")

void main(void)
{
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;
  
  wVersionRequested = MAKEWORD( 1, 1 );
  
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
  
  if ( LOBYTE( wsaData.wVersion ) != 1 ||
    HIBYTE( wsaData.wVersion ) != 1 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    WSACleanup( );
    return; 
  }
  
  /* The WinSock DLL is acceptable. Proceed. */
  
  SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.0.128");
  
  char recvBuf[100];
  char sendBuf[100];
  char tempBuf[100];
  int nLen = sizeof(SOCKADDR);
  
  while(1)
  {
    puts("��������������:");
    gets(sendBuf);
    sendto(sockClient, sendBuf, 100, 0, (SOCKADDR*)&addrSrv, nLen);
    
    recvfrom(sockClient, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &nLen);
    if('q' == recvBuf[0])
    {
      sendto(sockClient, "q", strlen("q")+1, 0, (SOCKADDR*)&addrSrv, nLen);
      puts("�������");
      break;
    }
    sprintf(tempBuf, "%s : %s", inet_ntoa(addrSrv.sin_addr), recvBuf);
    printf("%s\r\n", tempBuf);
  }
  
  closesocket(sockClient);
  WSACleanup();
}
