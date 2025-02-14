﻿// 0827_wp_WorldOfShapes.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0827_wp_WorldOfShapes.h"

#define MAX_LOADSTRING 100

using namespace std;

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
    LoadStringW(hInstance, IDC_MY0827WPWORLDOFSHAPES, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0827WPWORLDOFSHAPES));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0827WPWORLDOFSHAPES));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0827WPWORLDOFSHAPES);
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

#define TIMER_ID 1
#define TIMER_INTERVAL 1


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static vector<CObject*> objectList;
    static RECT             rectView;
    static PAINTSTRUCT      ps;
    static HDC              hdc;
    static LONG             maxObjectSize;
    static HBRUSH           hBrush          = NULL;
    static HBRUSH           oldBrush        = NULL;
    static TCHAR            countText[15];
    static TCHAR            modes[4][7]     = { {}, { L"Mode 1" }, {L"Mode 2"}, {L"Mode 3"} };
    static int              modeNum         = 1;

    switch (message)
    {
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

    case WM_CREATE:
        srand(time(NULL));
        GetClientRect(hWnd, &rectView);
        SetTimer(hWnd, TIMER_ID, TIMER_INTERVAL, NULL);
        maxObjectSize = rectView.bottom / 2;
        break;

    case WM_TIMER:
        for (int i = objectList.size() - 1; i >= 0; i--)
        {
            CObject& obj1 = *objectList[i];

            if (obj1.GetRadius() < MIN_OBJECT_SIZE || obj1.GetRadius() > maxObjectSize)
            {
                objectList.erase(objectList.begin() + i);
                continue;
            }
            for (int j = 0; j < objectList.size(); j++)
            {
                if (i == j) continue;
                CObject& obj2 = *objectList[j];

                if (obj1.Collision(obj2))
                {
                    obj1.CollisionEvent(modeNum, i, j, objectList, rectView);
                    break;
                }
            }
            obj1.AdjustPosition(rectView);
            obj1.Move();
            obj1.Rotate();
        }
        InvalidateRgn(hWnd, NULL, TRUE);
        break;

    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_NUMPAD1: modeNum = 1; break;
        case VK_NUMPAD2: modeNum = 2; break;
        case VK_NUMPAD3: modeNum = 3; break;
        default: break;
        }
        break;

    case WM_LBUTTONDOWN:
        {
        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        int objectType = rand() % 3;

        switch ((CObjectType)objectType)
        {
        case OBJECT_CIRCLE:
        {
            Circle2D* newCircle = new Circle2D(x, y, OBJECT_CIRCLE);
            objectList.push_back(newCircle);
        }
            break;

        case OBJECT_RECT:
        {
            Rectangle2D* newRect = new Rectangle2D(x, y, OBJECT_RECT);
            objectList.push_back(newRect);
        }
            break;

        case OBJECT_STAR:
        {
            Star2D* newStar = new Star2D(x, y, OBJECT_STAR);
            objectList.push_back(newStar);
        }
            break;
        }
        objectList.back()->AdjustPosition(rectView);
        InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_LBUTTONUP:
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            int objectCount = objectList.size();
            for (int i = objectCount - 1; i >= 0; i--)
            {
                if (objectList[i]->HasCollided())
                {
                    objectList[i]->SetHasCollided(false);
                    hBrush = CreateSolidBrush(RGB(62, 180, 137));
                    oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                }
                objectList[i]->Draw(hdc);

                if (oldBrush) SelectObject(hdc, oldBrush);
                if (hBrush) DeleteObject(hBrush);
            }
            wsprintfW(countText, L"ObjectCount : %d", objectList.size());
            TextOut(hdc, 10, 10, modes[modeNum], _tcslen(modes[modeNum]));
            TextOut(hdc, 10, 30, countText, _tcslen(countText));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
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
