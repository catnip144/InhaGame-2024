// 0902_wp_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0902_wp_1.h"
#include "resource.h"
#include "commdlg.h"

#define MAX_LOADSTRING 100

using namespace std;

//////////////////////////////////////////////////////

#pragma comment(lib, "msimg32.lib")

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DeleteBitmap();
void UpdateFrame(HWND hWnd);

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

//////////////////////////////////////////////////////

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
    LoadStringW(hInstance, IDC_MY0902WP1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0902WP1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0902WP1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0902WP1);
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

#include <math.h>
#define BSIZE 40

double LengthPts(int x1, int y1, int x2, int y2)
{
    return (sqrt((float)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));
}

bool InCircle(int x, int y, int mx, int my)
{
    return (LengthPts(x, y, mx, my) < BSIZE);
}

/// ///////////////////////////////////////////////////////////

#define TIMER_ANI 3

// : background
HBITMAP hBackImage;
BITMAP bitBack;

// : sigong
HBITMAP hTransparentImage;
BITMAP bitTransparent;

// : ani
HBITMAP hAniImage; // 포인터
BITMAP bitAni; // 구조체
const int SPRITE_SIZE_X = 57;
const int SPRITE_SIZE_Y = 52;
const int SPRITE_COUNT = 16;
const int SPRITE_DIR = 2;

int Run_Frame_Max = 0;
int Run_Frame_Min = 0;
int curFrame = Run_Frame_Min;

/// ///////////////////////////////////////////////////////////

void CreateBitmap()
{
    // >> : background image
    hBackImage = (HBITMAP)LoadImage(NULL, TEXT("images/donut.bmp"),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hBackImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("donut 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hBackImage, sizeof(BITMAP), &bitBack);
    // << :

    // >> : sigong
    hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("images/sigong.bmp"),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hTransparentImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("sigong 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);
    // << :

    // >> : Ani
    hAniImage = (HBITMAP)LoadImage(NULL, TEXT("images/zero_run.bmp"),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hAniImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("ani 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hAniImage, sizeof(BITMAP), &bitAni);

    Run_Frame_Max = bitAni.bmWidth / SPRITE_SIZE_X - 1;
    Run_Frame_Min = 2;
    curFrame = Run_Frame_Min;
    // << :
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    // >> : Donut
    {
        hMemDC = CreateCompatibleDC(hdc); // hdc와 호환되는 장치를 생성하라
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
        bx = bitBack.bmWidth;
        by = bitBack.bmHeight;

        //BitBlt(hdc, 100, 100, bx - 100, by - 100, hMemDC, 100, 100, SRCCOPY);
        BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
        StretchBlt(hdc, bx, 0, bx / 4, by / 4, hMemDC, 0, 0, bx, by, SRCCOPY);

        SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
    // << :
    
    // >> : sigong
    {
        hMemDC = CreateCompatibleDC(hdc);
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
        bx = SPRITE_SIZE_X;
        by = SPRITE_SIZE_Y;

        TransparentBlt(hdc, 200, 200, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255)); // 이 색깔을 제외하고 전송

        SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
    // << :

    // >> : ani
    {
        hMemDC = CreateCompatibleDC(hdc);
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
        bx = bitAni.bmWidth / SPRITE_COUNT;
        by = bitAni.bmHeight / SPRITE_DIR;

        int xStart = curFrame * bx;
        int yStart = 0;

        TransparentBlt(hdc, 400, 400, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255)); // 이 색깔을 제외하고 전송

        SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
    // << :
}

void DeleteBitmap()
{
    DeleteObject(hBackImage);
    DeleteObject(hTransparentImage);
    DeleteObject(hAniImage);
}

void UpdateFrame(HWND hWnd)
{
    curFrame++;
    if (curFrame > Run_Frame_Max)
        curFrame = Run_Frame_Min;
}

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
    UpdateFrame(hWnd);
    InvalidateRect(hWnd, NULL, false);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC hdc;
    static PAINTSTRUCT ps;
    static bool Select;
    static bool Copy;
    static int mx, my;
    static int x, y;

    static HMENU hMenu, hSubMenu;

    switch (message)
    {
    case WM_CREATE:
        hMenu = GetMenu(hWnd);
        hSubMenu = GetSubMenu(hMenu, 0);

        Select = false;
        Copy = false;
        x = y = 50;

        SetTimer(hWnd, TIMER_ANI, 33, AniProc);
        CreateBitmap();
        break;

    case WM_TIMER:
        switch (wParam)
        {
        //case TIMER_ANI:
        //    UpdateFrame(hWnd);
        }
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:

            if (LOWORD(wParam) == ID_EDITCOPY)
            {
                Copy = true;
                InvalidateRgn(hWnd, NULL, TRUE);
            }
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

    case WM_LBUTTONDOWN:
        mx = LOWORD(lParam);
        my = HIWORD(lParam);

        if (InCircle(x, y, mx, my))
            Select = true;

        InvalidateRgn(hWnd, NULL, false);
        break;


    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);

            //EnableMenuItem(hSubMenu, ID_EDITCOPY,  Select ? MF_ENABLED : MF_GRAYED);
            //EnableMenuItem(hSubMenu, ID_EDITPASTE, Copy   ? MF_ENABLED : MF_GRAYED);

            //if (Select)
            //    Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

            //Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

            DrawBitmap(hWnd, hdc);
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        KillTimer(hWnd, TIMER_ANI);
        PostQuitMessage(0);
        DeleteBitmap();
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
