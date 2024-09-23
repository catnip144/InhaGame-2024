#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <WinSock2.h>
#include <inaddr.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define Buf_Size 1024

void Server_Code();
void Error(const char* msg);
void Log(const char* msg);

char strServerIP[] = "172.30.1.23";
//char strServerIP[] = "127.0.0.1";

char strPort[] = "12345"; // 8080

int main()
{
    cout << "Server Start!\n";

    Server_Code();

    cout << "Server Finished!\n";

    return 0;
}

void Server_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    char msg[Buf_Size];
    int strLength, i;

    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize;

    // 소켓 라이브러리 초기화 (구조체 초기화)
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error("WSAStartup() error!");
    Log("WSAStartup() OK.");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error!");
    Log("socket() OK.");

    // 서버 구조체
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(strPort));

    // ip 주소, 서버 포트 -> 서버 소켓
    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        Error("bind() error!");
    Log("bind() OK.");

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        Error("listen() error");
    Log("listen() OK");

    clientAddrSize = sizeof(clientAddr);
    i = 0;

    //while (true)
    for (int i = 0; i < SOMAXCONN; i++)
    {
        // 클라이언트 address를 받아오기를 기다림
        clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
        Log("Accept()....");

        if (clientSocket == SOCKET_ERROR)
            Error("accept() error");
        else
            printf("Connected client %d\n", i + 1);

        memset(msg, 0, sizeof(msg));
        while ((strLength = recv(clientSocket, msg, Buf_Size, 0)) > 0)
        {
            printf("%d client : %s", i + 1, msg);
            send(clientSocket, msg, strLength, 0);
            memset(msg, 0, sizeof(msg));
        }

        if (strLength == 0)
        {
            Log("Client disconnected - normal");
        }
        else if (strLength == SOCKET_ERROR)
        {
            int err = WSAGetLastError();
            if (err == WSAECONNRESET)
            {
                Log("Client disconnected - unexpected");
            }
            else
            {
                printf("recv() error : %d\n", err);
            }
        }
        Log("Client connection closed");
        closesocket(clientSocket);
    }
    closesocket(serverSocket);
    WSACleanup();
}

void Error(const char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void Log(const char* msg)
{
    fputs(msg, stdout);
    fputc('\n', stdout);
}

