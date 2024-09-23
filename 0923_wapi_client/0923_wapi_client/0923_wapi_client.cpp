#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <inaddr.h>
#pragma comment(lib, "ws2_32.lib")

#define Buf_Size 1024

void Client_Code();
void Error(const char* msg);
void Log(const char* msg);

//char strServerIP[] = "172.30.1.12"; // 선생님 ip
//char strServerIP[] = "172.30.1.35"; // 덕상님 ip
char strServerIP[] = "172.30.1.23";

char strClientIP[] = "127.0.0.1";
char strPort[] = "12345"; // 8080

using namespace std;

int main()
{
    cout << "Client Start!\n";

    Client_Code();

    cout << "Client Finished!\n";
    return 0;
}

void Client_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    char msg[Buf_Size];
    int strLength, i;

    SOCKADDR_IN serverAddr;

    // 구조체 초기화
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        Error("WSAStartup() error!");
    Log("WSAStartup() OK.");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error");
    Log("socket() OK.");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr(strServerIP);
    serverAddr.sin_port = htons(atoi(strPort));

    if (connect(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        Error("connect() error");
    else
        puts("Connection Success!");

    while (1)
    {
        fputs("Input Message(Q to quit) : ", stdout);
        fgets(msg, Buf_Size, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;

        send(serverSocket, msg, strlen(msg), 0);
        strLength = recv(serverSocket, msg, Buf_Size - 1, 0);
        msg[strLength] = 0;
        printf("Message from server : %s\n", msg);
    }
    closesocket(serverSocket);
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