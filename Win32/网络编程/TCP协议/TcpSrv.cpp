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
  if( err != 0 ) 
  {	
    return;
  }
  
  if( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 ) 
  {
    WSACleanup( );
    return; 
  }
  
  //�������ֽڶ���
  SOCKET SockSrv;
  SockSrv = socket(AF_INET, SOCK_STREAM, 0);
  
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = htons(8888);
  addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
  
  //�󶨱��ص�ַ���˿�
  bind(SockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
  
  //�����׽���Ϊ����״̬
  listen(SockSrv, 5);
  
  SOCKADDR_IN addrClient;
  int len = sizeof(SOCKADDR);
  
  while(1)
  {
    //������������
    SOCKET sockConn = accept(SockSrv, (SOCKADDR*)&addrClient, &len);
    
    char sendBuf[100];
    
    sprintf(sendBuf, "Welcome %s to GitHub", inet_ntoa(addrClient.sin_addr));
    
    //��������
    send(sockConn, sendBuf, (strlen(sendBuf)+1), 0);
    
    char recvBuf[100];
    //��������
    recv(sockConn, recvBuf, 100, 0);
    
    printf("%s\r\n", recvBuf);
    
    //�ر��׽���
    if(SOCKET_ERROR == closesocket(sockConn))
      printf("Error\r\n");
  }
}