﻿// 0827_wp_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0827_wp_1.h"
#include <cmath>

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
    LoadStringW(hInstance, IDC_MY0827WP1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0827WP1));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0827WP1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0827WP1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

// : User Define
#define TIMER_ID1 1
#define TIMER_ID2 3
#define CIRCLE_RADIUS 40

BOOL InCircle(int x1, int y1, int x2, int y2, int radius)
{
    double len = sqrt((float)pow((x2 - x1), 2) + pow((y2 - y1), 2));
    if (len < radius) return TRUE;
    return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT pos;
    static RECT rectView;
    static bool flag = false;
    static bool mouseFlag = false;

    switch (message)
    {
    case WM_CREATE:
        pos.x = CIRCLE_RADIUS; pos.y = CIRCLE_RADIUS;
        GetClientRect(hWnd, &rectView);

        //SetTimer(hWnd, TIMER_ID1, 500, NULL);  // 0.5초
        //SetTimer(hWnd, TIMER_ID2, 1300, NULL); // 1.3초마다
        break;

    // 윈도우 사이즈가 변경되었을 때
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        InvalidateRect(hWnd, NULL, TRUE);
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
    
    case WM_TIMER:
        switch (wParam)
        {
        case TIMER_ID1:
            pos.x += CIRCLE_RADIUS;
            if (pos.x > rectView.right - CIRCLE_RADIUS)
                pos.x = rectView.right - CIRCLE_RADIUS;
            break;

        case TIMER_ID2:
            pos.x -= 60;
            if (pos.x < rectView.left + CIRCLE_RADIUS)
                pos.x = rectView.left + CIRCLE_RADIUS;
            break;
        }
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_RIGHT:
            pos.x += CIRCLE_RADIUS;
            if (pos.x > rectView.right - CIRCLE_RADIUS)
                pos.x = rectView.right - CIRCLE_RADIUS;
            break;

        case VK_LEFT:
            pos.x -= CIRCLE_RADIUS;
            if (pos.x < rectView.left + CIRCLE_RADIUS)
                pos.x = rectView.left + CIRCLE_RADIUS;
            break;

        case VK_UP:
            pos.y -= CIRCLE_RADIUS;
            if (pos.y < rectView.top + CIRCLE_RADIUS)
                pos.y = rectView.top + CIRCLE_RADIUS;
            break;

        case VK_DOWN:
            pos.y += CIRCLE_RADIUS;
            if (pos.y > rectView.bottom - CIRCLE_RADIUS)
                pos.y = rectView.bottom - CIRCLE_RADIUS;
            break;

        default:
            break;
        }
        flag = true;
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    /*  [ WM_LBUTTONDOWN ]
        마우스, 주로 메뉴 상호작용에서 쓰임 (FPS게임에서 쓰기에는 너무 느림)
        마우스 버튼을 풀었을 때(누른 순간x) 메뉴 이벤트가 발생하도록 하는게 좋다.
    */
    case WM_LBUTTONDOWN:
        //pos.x = LOWORD(lParam); // : x
        //pos.y = HIWORD(lParam); // : y

        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);

        if (InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS))
            mouseFlag = TRUE;
        else
            mouseFlag = FALSE;

        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_LBUTTONUP:
        mouseFlag = FALSE;
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_RBUTTONDOWN:
        break;

    case WM_RBUTTONUP:
    {
        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        flag = InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS);
        InvalidateRect(hWnd, NULL, TRUE);
    }
        break;

    case WM_MOUSEWHEEL:
        break;
    
    case WM_MOUSEMOVE:
    {
        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);

        if (mouseFlag)
        {
            pos.x = x;
            pos.y = y;
            InvalidateRect(hWnd, NULL, TRUE);
        }
    }
        break;

    case WM_KEYUP:
        flag = false;
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HBRUSH hBrush, oldBrush;
            hBrush = CreateSolidBrush(RGB(0, 255, 0));

            if (flag)
                oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            else
                oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

            Ellipse(hdc, pos.x - CIRCLE_RADIUS, pos.y - CIRCLE_RADIUS, pos.x + CIRCLE_RADIUS, pos.y + CIRCLE_RADIUS);

            SelectObject(hdc, oldBrush);
            DeleteObject(hBrush);

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        // 타이머 해제
        KillTimer(hWnd, TIMER_ID1);
        KillTimer(hWnd, TIMER_ID2);

        PostQuitMessage(0);
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