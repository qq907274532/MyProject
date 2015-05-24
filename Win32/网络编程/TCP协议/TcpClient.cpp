#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

void main(void)
{
  //�׽��ֳ�ʼ��
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
  
  //�����׽��ֶ���
  SOCKET sockClient;
  sockClient = socket(AF_INET, SOCK_STREAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  
  //���������������
  connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
  
  char recvBuf[100];
  //��������
  recv(sockClient, recvBuf, 100, 0);
  printf("%s\r\n", recvBuf);
  
  //��������
  send(sockClient, "This is KangKang", strlen("This is KangKang") + 1, 0);
  
  //�ر��׽���
  if(SOCKET_ERROR == closesocket(sockClient))
    printf("Error\r\n");
  
  //��ֹWinsock 2 DLL (Ws2_32.dll) ��ʹ��
  WSACleanup();
}