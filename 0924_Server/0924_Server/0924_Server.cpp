// 0924_Server.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#include "framework.h"
#include "0924_Server.h"
#include <list>
#include <WinSock2.h>

#define WM_ASYNC WM_USER+1
#define MY_PORT 12346
#define MY_IP "172.30.1.61"
#define CHAT_LENGTH 100

struct User
{
    SOCKET socket;
    int id;
};

int nextId = 1;
list<User> socketList;

WSADATA wsdata;
SOCKET s, cs;
SOCKADDR_IN addr = { 0 }, c_addr = { 0 };
TCHAR msg[200] = { 0 };

int size, msgLen;
char buffer[CHAT_LENGTH];

int WinSock_Server();
int InitServer(HWND hWnd);
int CloseServer();
SOCKET AcceptSocket(HWND hWnd, SOCKET s, SOCKADDR_IN& c_addr);

void SendMessageToClient(char* buffer);
void ReadMessage(TCHAR* msg, char* buffer);
void CloseClient(SOCKET socket);

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0924SERVER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0924SERVER));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
    //return WinSock_Server();
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0924SERVER));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY0924SERVER);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        return InitServer(hWnd);
    }
    break;

    case WM_ASYNC:
    {
        switch (lParam)
        {
        case FD_ACCEPT:
        {
            cs = AcceptSocket(hWnd, s, c_addr);
        }
        break;
        case FD_READ:
        {
            ReadMessage(msg, buffer);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
        case FD_CLOSE:
        {
            // wParam : 소켓 정보
            CloseClient(wParam);
        }
        break;
        }

    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        if (_tcscmp(msg, _T("")))
            TextOut(hdc, 10, 10, msg, _tcslen(msg));

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        CloseServer();
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


int WinSock_Server()
{
    WSAStartup(MAKEWORD(2, 2), &wsdata);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        MessageBox(NULL, _T("socket() Failed"), _T("Error"), MB_OK);
        return 0;
    }
    MessageBox(NULL, _T("socket() Success"), _T("Success"), MB_OK);

    addr.sin_family = AF_INET;
    addr.sin_port = 12346;
    addr.sin_addr.S_un.S_addr = inet_addr("172.30.1.61");

    if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)))
    {
        MessageBox(NULL, _T("bind() Failed"), _T("Error"), MB_OK);
        return 0;
    }
    MessageBox(NULL, _T("bind() Success"), _T("Success"), MB_OK);

    if (listen(s, 25) == SOCKET_ERROR)
    {
        MessageBox(NULL, _T("listen() Failed"), _T("Error"), MB_OK);
        return 0;
    }
    MessageBox(NULL, _T("listen() Success"), _T("Success"), MB_OK);

    TCHAR message[256];

    do {
        SOCKADDR_IN c_addr;
        int size = sizeof(c_addr);
        SOCKET cs = accept(s, (LPSOCKADDR)&c_addr, &size);

        char buffer[CHAT_LENGTH];
        int msgLen;
        msgLen = recv(cs, buffer, CHAT_LENGTH, 0);
        buffer[msgLen] = NULL;
#ifdef _UNICODE
        TCHAR wBuffer[100];
        msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
        MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), wBuffer, msgLen);
        wBuffer[msgLen] = NULL;
        _stprintf_s(message, _T("Client Message : %s, 서버종료?"), wBuffer);
#else       
        sprintf(message, _T("Client Message : %s, 서버종료?"), buffer);
#endif 
    } while (MessageBox(NULL, message, _T("Server Message"), MB_YESNO) == IDNO);

    closesocket(s);
    WSACleanup();

    return 0;
}

int InitServer(HWND hWnd)
{
    WSAStartup(MAKEWORD(2, 2), &wsdata);
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == INVALID_SOCKET)
    {
        MessageBox(NULL, _T("socket() Failed"), _T("Error"), MB_OK);
        return 0;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = MY_PORT;
    addr.sin_addr.S_un.S_addr = inet_addr(MY_IP);

    if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)))
    {
        MessageBox(NULL, _T("bind() Failed"), _T("Error"), MB_OK);
        return 0;
    }

    if (listen(s, 25) == SOCKET_ERROR)
    {
        MessageBox(NULL, _T("listen() Failed"), _T("Error"), MB_OK);
        return 0;
    }
    WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_ACCEPT);
    return 0;
}

int CloseServer()
{
    closesocket(s);
    WSACleanup();
    return 0;
}

SOCKET AcceptSocket(HWND hWnd, SOCKET s, SOCKADDR_IN& c_addr)
{
    SOCKET cs;
    int size = sizeof(c_addr);
    cs = accept(s, (LPSOCKADDR)&c_addr, &size);
    WSAAsyncSelect(cs, hWnd, WM_ASYNC, FD_READ | FD_CLOSE);

    socketList.push_back({ cs, nextId });
    nextId++;

    char joinMsg[200] = "";
    sprintf_s(joinMsg, "User %d joined the chat. ", socketList.back().id);

    SendMessageToClient(joinMsg);
    return cs;
}

void SendMessageToClient(char* buffer)
{
    for (list<User>::iterator it = socketList.begin(); it != socketList.end(); it++)
    {
        SOCKET cs = (*it).socket;
        send(cs, (LPSTR)buffer, strlen(buffer) + 1, 0);
    }
}

void ReadMessage(TCHAR* msg, char* buffer)
{
    for (list<User>::iterator it = socketList.begin(); it != socketList.end(); it++)
    {
        SOCKET cs = (*it).socket;
        int csId = (*it).id;
        int msgLen = recv(cs, buffer, CHAT_LENGTH, 0);

        if (msgLen > 0)
        {
            buffer[msgLen] = NULL;

#ifdef _UNICODE
            msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
            MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
            msg[msgLen] = NULL;

            char username[100];
            sprintf_s(username, "User %d: ", csId);

            char sendBuffer[200] = "";
            strcat_s(sendBuffer, username);
            strcat_s(sendBuffer, buffer);
#else
            stcpy_s(msg, buffer);
#endif
            SendMessageToClient(sendBuffer);
        }
    }
}

void CloseClient(SOCKET socket)
{
    char leaveMsg[200] = "";

    for (list<User>::iterator it = socketList.begin(); it != socketList.end(); it++)
    {
        SOCKET cs = (*it).socket;
        int csId = (*it).id;

        if (cs == socket)
        {
            sprintf_s(leaveMsg, "User %d left the chat. ", csId);

            closesocket(cs);
            it = socketList.erase(it);
            break;
        }
    }
    SendMessageToClient(leaveMsg);
}
