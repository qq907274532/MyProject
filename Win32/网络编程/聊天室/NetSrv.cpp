#include <stdio.h>
#include <string.h>
#include <winsock2.h>


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
  
  SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
  
  bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
  
  char recvBuf[100];
  char sendBuf[100];
  char tempBuf[100];
  SOCKADDR_IN addrClient;
  int nLen = sizeof(SOCKADDR);
  
  while(1)
  {
    recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &nLen);
    if('q' == recvBuf[0])
    {
      sendto(sockSrv, "q", strlen("q")+1, 0, (SOCKADDR*)&addrClient, nLen);
      puts("聊天结束");
      break;
    }
    sprintf(tempBuf, "%s : %s", inet_ntoa(addrClient.sin_addr), recvBuf);
    printf("%s\r\n", tempBuf);
    puts("请输入聊天内容:");
    gets(sendBuf);
    sendto(sockSrv, sendBuf, 100, 0, (SOCKADDR*)&addrClient, nLen);
  }
  closesocket(sockSrv);
  WSACleanup();
}

