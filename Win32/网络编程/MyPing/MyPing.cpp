// MyPing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

#define   ECHO_REPLY   0
#define   ECHO_REQUEST 8

struct icmp_hdr 
{
  BYTE icmp_type;     //类型
  BYTE icmp_code;     //代码
  USHORT icmp_cksum;  //效验和
  USHORT icmp_id;     //n
  USHORT icmp_seq;    //n
  ULONG  icmp_data;   //GetTickout()
};

struct ip_hdr
{
  unsigned char h_len:4;       //length of header
  unsigned char version:4;      //Version of IP
  unsigned char tos;            //Type of service
  unsigned short total_len;     //total length of the packet
  
  unsigned short ident;          //unique identifier
  unsigned short frag_and_flags; //flags
  
  unsigned char ttl;          //ttl
  unsigned char proto;        //protocol(TCP ,UDP etc)
  unsigned short checksum;    //IP checksum
  
  unsigned int sourceIP;
  unsigned int destIP;
};

//网际校验和生产算法
//网际校验和是被校验数据16位值的反码和(ones-complement sum)
WORD CalcCheckSum(IN unsigned short* addr,IN int len)
{
  int		nleft = len;
  int		sum = 0;
  unsigned short* w = addr;
  unsigned short answer = 0;
  
  while(nleft > 1) {
    sum += *w++;
    nleft -= 2;
  }
  
  if(nleft == 1) {
    *(unsigned char*)(&answer) = *(unsigned char*)w;
    sum += answer;
  }
  
  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  answer = ~sum;
  
  return (answer);
}

int main(int argc, char* argv[])
{
  //初始化
  WORD wVersionRequested;
  WSADATA wsaData;
  wVersionRequested = MAKEWORD( 2, 2 );
  WSAStartup( wVersionRequested, &wsaData );
  
  SOCKET sSocket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sSocket == INVALID_SOCKET)
  {
    return 0;
  }
  
  //域名转换成IP
  hostent *pHostent = gethostbyname(argv[1]);
  if (pHostent == NULL)
  {
    printf("Ping request could not find host %s.\r\n", 
      argv[1]);
    return 0;
  }
  
  char szSend[32] = {0};
  
  for (int i = 0; i < 4; i++)
  {
    //是最用于测试 IP 连接通常称为 PING ICMP。
    //回显请求 ICMP 将具有类型字段为 8 和 0 的代码字段。
    //回送答复具有类型字段为 0 和 0 的代码字段。 
    icmp_hdr *pIcmpHdr = (icmp_hdr*)szSend;
    pIcmpHdr->icmp_type = ECHO_REQUEST;
    pIcmpHdr->icmp_code = 0;
    pIcmpHdr->icmp_cksum = 0;
    pIcmpHdr->icmp_id = i;
    pIcmpHdr->icmp_seq = i;
    pIcmpHdr->icmp_data = GetTickCount();
    strcpy((char*)(pIcmpHdr + 1), "Hello");
    pIcmpHdr->icmp_cksum = CalcCheckSum((unsigned short*)szSend, \
                                        sizeof(szSend));
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = ((long**)pHostent->h_addr_list)[0][0];
    int nRet = sendto(sSocket, szSend, sizeof(szSend), 0, \
                     (sockaddr*)&addr, sizeof(addr));
    if (nRet == 0 || nRet == SOCKET_ERROR)
    {
      puts("Send Error");
      break;
    }
    
    fd_set fReads;
    FD_ZERO(&fReads);
    //FD_SET(sSocket, &fReads);
    timeval tv = {3, 0};
    fReads.fd_array[0] = sSocket;
    fReads.fd_count++;
    
    nRet = select(0, &fReads, NULL, NULL, &tv);
    if (nRet == 0 || nRet == SOCKET_ERROR)
    {
      puts("Time Out");
      continue;
    }
    
    sockaddr_in FormAddr = {0};
    int nLen = sizeof(FormAddr);
    char szRecv[MAXBYTE] = {0};
    nRet = recvfrom(sSocket, szRecv, sizeof(szRecv), 0, \
                   (sockaddr*)&FormAddr, &nLen);
    ip_hdr *pIpHdr = (ip_hdr*)szRecv;
    icmp_hdr *pRecvIcmp = (icmp_hdr*)(pIpHdr + 1);
    if (pRecvIcmp->icmp_id == pIcmpHdr->icmp_id &&
      memcmp((void*)&FormAddr.sin_addr, (void*)&addr.sin_addr, 
      sizeof(addr)))
    {
      printf("Reply from %s: bytes=%d  time<%dms TTL=%d\r\n", \
        inet_ntoa(FormAddr.sin_addr), \
        nRet - sizeof(ip_hdr), \
        GetTickCount() - pIcmpHdr->icmp_data, \
        pIpHdr->ttl);
    }
    
    Sleep(500);
  }
  
  WSACleanup();
  return 0;
}

