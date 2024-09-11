// 0902_wp_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0902_wp_1.h"
#include "resource.h"
#include <commdlg.h>
#include <CommCtrl.h>
#include <stdio.h>

#define MAX_LOADSTRING 100
using namespace std;

////////////////////////////////////////////////////// for gdi+ 
#include <objidl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

ULONG_PTR g_GdiPlusToken;
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void Gdi_End();
//////////////////////////////////////////////////////


////////////////////////////////////////////////////// double buffering, bitmap animation

#pragma comment(lib, "msimg32.lib")

HWND g_hWnd = NULL;
HINSTANCE g_hInst;

void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DeleteBitmap();
void UpdateFrame(HWND hWnd);

void DrawBitMapDoubleBuffering(HWND hWnd, HDC hdc);
void Update();

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dialog2_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);


////////////////////////////////////////////////////// 모달리스 대화상자

HWND g_hDlg = nullptr;
void MakeColumn(HWND hDlg);
void InsertData(HWND hDlg);

///////////////////////////////////////////////////////


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

    // DIRECT X에서는 이 루프를 사용하지 않고 따로 루틴을 짠다
    // 기본 메시지 루프입니다: 
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //}

    Gdi_Init();
    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            Update();
        }
    }

    Gdi_End();
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
   g_hWnd = hWnd;
   g_hInst = hInst;

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
#define TIMER_KEY 4

// : background
HBITMAP hBackImage;
BITMAP bitBack;

// : front image
HBITMAP hFrontImage;
BITMAP bitFront;

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

POINT ptAni = { 400, 400 };

HBITMAP hDoubleBufferImage;
RECT rectView;

TCHAR sKeyState[128]; // 키가 뭐가 눌렸는지 확인 용도

/// ///////////////////////////////////////////////////////////

void Gdi_Init()
{
    GdiplusStartupInput gpsi;
    GdiplusStartup(&g_GdiPlusToken, &gpsi, NULL);
}

void Gdi_Draw(HDC hdc)
{
    Graphics graphics(hdc);

    // :
    SolidBrush brush(Color(255, 255, 0, 0));
    FontFamily fontFamily(L"Times New Roman");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(10.0f, 20.0f);
    graphics.DrawString(L"Hello GDI+", -1, &font, pointF, &brush);

    // :
    Pen pen(Color(128, 0, 255, 255)); // a, r, g, b
    graphics.DrawLine(&pen, 0, 0, 200, 100);

    // :
    Image img((WCHAR*)L"images/sigong.png");
    int w = img.GetWidth();
    int h = img.GetHeight();
    graphics.DrawImage(&img, 100, 100, w, h);

    // :
    Image img2((WCHAR*)L"images/zero_run.png");
    w = img2.GetWidth() / SPRITE_COUNT;
    h = img2.GetHeight() / SPRITE_DIR;
    int xStart = curFrame * w;
    int yStart = 0;
    
    ImageAttributes imgAttr0;
    imgAttr0.SetColorKey(Color(245, 0, 245), Color(255, 10, 255));
    graphics.DrawImage(
        &img2, Rect(200, 100, w, h),
        xStart, yStart, w, h,
        UnitPixel, &imgAttr0
    );

    // 반투명 박스 :
    brush.SetColor(Color(64, 255, 0, 0));
    graphics.FillRectangle(&brush, 100, 100, 200, 300);

    // 회전 :
    Image* pImg = nullptr;
    pImg = Image::FromFile((WCHAR*)L"images/sigong.png");
    int xPos = 300;
    int yPos = 100;
    if (pImg)
    {
        w = pImg->GetWidth();
        h = pImg->GetHeight();

        Gdiplus::Matrix mat;
        static int rot = 0;

        // 이미지의 중점을 잡아서 회전하는 것이 중요
        mat.RotateAt((rot % 360), Gdiplus::PointF(xPos + (float)(w/2), yPos + (float)(h / 2))); // 이미지의 중간값 보정
        graphics.SetTransform(&mat);
        graphics.DrawImage(pImg, xPos, yPos, w, h);
        rot += 10;

        mat.Reset(); // 다른 이미지들한테도 영향을 미치기 때문에 Reset을 해줘야 한다.
        graphics.SetTransform(&mat);
    }

    // >>
    ImageAttributes imgAttr;
    imgAttr0.SetColorKey(Color(245, 0, 245), Color(255, 10, 255));
    yPos = 200;

    graphics.DrawImage(
        pImg, Rect(xPos, yPos, w, h),
        0, 0, w, h,
        UnitPixel, &imgAttr
    );

    // >>
    if (pImg)
    {
        REAL transparency = 0.5f;
        ColorMatrix colorMatrix =
        {
            1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, transparency, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        };
        imgAttr.SetColorMatrix(&colorMatrix);
        xPos = 400;
        graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);

        // :
        ColorMatrix colorMatrix2 =
        {
            //r     g      b    a
            0.3f, 0.3f, 0.3f, 0.0f, 0.0f,
            0.6f, 0.9f, 0.6f, 0.0f, 0.0f,
            0.1f, 0.1f, 0.1f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        };
        imgAttr.SetColorMatrix(&colorMatrix2);
        xPos = 500;
        graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);

        //// :
        //xPos = 600;
        //pImg->RotateFlip(Rotate90FlipX); // RotateNoneFlipX
        //graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);

        //// :
        //xPos = 700;
        //graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w * 2, h * 2, UnitPixel, &imgAttr);
    }
    if (pImg) delete pImg;
}

void Gdi_End()
{
    GdiplusShutdown(g_GdiPlusToken);
}

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

    // >> : front
    hFrontImage = (HBITMAP)LoadImage(NULL, TEXT("images/cloud.bmp"),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hFrontImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("donut 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hFrontImage, sizeof(BITMAP), &bitFront);
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

        TransparentBlt(hdc, ptAni.x, ptAni.y, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255)); // 이 색깔을 제외하고 전송

        SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
    // << :

    // >> : front
    {
        HDC hMemDC2;
        HBITMAP hOldBitmap2;

        hMemDC2 = CreateCompatibleDC(hdc);
        hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hFrontImage);

        int bx = bitFront.bmWidth;
        int by = bitFront.bmHeight;

        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC2, hBrush);
        Ellipse(hMemDC2, bx / 4, by / 4, bx / 2, by / 2);

        SelectObject(hMemDC2, oldBrush);
        DeleteObject(hBrush);

        TransparentBlt(hdc, 300, 300, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
        //BitBlt(hdc, 300, 300, rectView.right, rectView.bottom, hMemDC2, 0, 0, SRCCOPY);

        SelectObject(hMemDC2, hOldBitmap2);
        DeleteDC(hMemDC2);
    }
    // << :

    Gdi_Draw(hdc);
}

void DrawBitMapDoubleBuffering(HWND hWnd, HDC hdc)
{
    HDC hDoubleBufferDC;
    HBITMAP hOldDoubleBufferBitmap;
    int dx, dy;

    hDoubleBufferDC = CreateCompatibleDC(hdc);
    if (hDoubleBufferImage == NULL)
        hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);

    hOldDoubleBufferBitmap = (HBITMAP)SelectObject(hDoubleBufferDC, hDoubleBufferImage);

    DrawBitmap(hWnd, hDoubleBufferDC);

    BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hDoubleBufferDC, 0, 0, SRCCOPY);

    SelectObject(hDoubleBufferDC, hOldDoubleBufferBitmap);
    DeleteDC(hDoubleBufferDC);
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

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
    if (GetKeyState('W') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("W-key pressed"));
    }
    else if (GetKeyState('A') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("A-key pressed"));
    }
    else if (GetKeyState('S') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("S-key pressed"));
    }
    else if (GetKeyState('D') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("D-key pressed"));
    }
    else
    {
        wsprintf(sKeyState, TEXT(""));
    }
    return VOID();
}


BOOL CALLBACK Dialog2_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        // 이렇게 가져오는 것도 가능
        //HWND hTxt = GetDlgItem(hDlg, IDC_STATIC);
        //SetDlgItemText(hTxt, IDC_STATIC, _T("모달리스 대화상자"));
        
        //SetDlgItemText(hDlg, IDC_STATIC, _T("모달리스 대화상자"));

        SetDlgItemText(hDlg, IDC_STATIC, _T("리스트 컨트롤 테스트"));
        MakeColumn(hDlg);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            DestroyWindow(hDlg);
            g_hDlg = nullptr;
            return 0;
        }
        switch (LOWORD(wParam))
        {
        case IDC_Btn_ListItemInsert:
            InsertData(hDlg);
            break;
        }

        break;
    }
    return 0;
}

void MakeColumn(HWND hDlg)
{
    LPCTSTR name[2] = { _T("이름"), _T("전화번호") };
    LVCOLUMN lvCol = { 0, };
    HWND hList;
    int i;
    hList = GetDlgItem(hDlg, IDC_LIST_CTRL);
    lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvCol.fmt = LVCFMT_LEFT;

    for (int i = 0; i < 2; i++)
    {
        lvCol.cx = 90;
        lvCol.iSubItem = i;
        lvCol.pszText = (LPWSTR)name[i];
        SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
    }
}

void InsertData(HWND hDlg)
{
    LVITEM item;
    LPCTSTR name[20] = { _T("홍길동"), _T("카리나") };
    LPCTSTR phone[20] = { _T("000-0000-0000"), _T("010-9384-3189")};
    HWND hList = GetDlgItem(hDlg, IDC_LIST_CTRL);

    for (int i = 0; i < 2; i++)
    {
        item.mask = LVIF_TEXT;
        item.iItem = i;
        item.iSubItem = 0;
        item.pszText = (LPWSTR)name[i];
        ListView_InsertItem(hList, &item);
        ListView_SetItemText(hList, i, 1, (LPWSTR)phone[i]);
    }
}


BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int Check[3], Radio;
    TCHAR hobby[][30] = { _T("독서"), _T("음악 감상"), _T("게임") };
    TCHAR sex[][30] = { _T("여성"), _T("남성") };
    TCHAR output[200];

    // >> : combo
    static HWND hCombo;
    static int selection;
    static HWND hList;

    TCHAR name[20];
    // << : 

    switch (uMsg)
    {
    case WM_INITDIALOG:
        {
            HWND btn = (HWND)GetDlgItem(hDlg, IDC_Btn_Pause);
            EnableWindow(btn, FALSE);

            // 여성 버튼에 먼저 체크가 되어 있도록 하겠다
            CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);

            hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
            hList = GetDlgItem(hDlg, IDC_LIST_NAME);
        }
        return 1;
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_Btn_Start:
            {
                HWND btn = (HWND)GetDlgItem(hDlg, IDC_Btn_Start);
                EnableWindow(btn, FALSE);

                btn = (HWND)GetDlgItem(hDlg, IDC_Btn_Pause);
                EnableWindow(btn, TRUE);

                SetDlgItemText(hDlg, IDC_Btn_Info, _T("게임 시작"));
            }
            break;

        case IDC_Btn_Pause:
            {
                HWND btn = (HWND)GetDlgItem(hDlg, IDC_Btn_Start);
                EnableWindow(btn, TRUE);

                btn = (HWND)GetDlgItem(hDlg, IDC_Btn_Pause);
                EnableWindow(btn, FALSE);

                SetDlgItemText(hDlg, IDC_Btn_Info, _T("게임 정지"));
            }
            break;

        case IDC_Btn_Close:
            EndDialog(hDlg, 0);
            break;
        case IDOK:
            EndDialog(hDlg, 0);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;

        ///////////////////////////////////////////////////////////////
        case IDC_Btn_Copy:
        {
            TCHAR word[100];
            GetDlgItemText(hDlg, IDC_EDIT_Source, word, 100);
            SetDlgItemText(hDlg, IDC_EDIT_Dest, word);
        }
            break;

        case IDC_Btn_Clear:
            SetDlgItemText(hDlg, IDC_EDIT_Source, _T(""));
            SetDlgItemText(hDlg, IDC_EDIT_Dest, _T(""));
            break;

        case IDC_Btn_Exit:
            EndDialog(hDlg, 0);
            break;
        ///////////////////////////////////////////////////////////////
        case IDC_CHECK_READING:
            Check[0] = 1 - Check[0];
            break;

        case IDC_CHECK_MUSIC:
            Check[1] = 1 - Check[1];
            break;

        case IDC_CHECK_GAME:
            Check[2] = 1 - Check[2];
            break;

        case IDC_RADIO_FEMALE:
            Radio = 0;
            break;

        case IDC_RADIO_MALE:
            Radio = 1;
            break;

        case IDC_Btn_Output:
            _stprintf_s(output,
                _T("선택한 취미는 %s %s %s 입니다.\r\n")
                _T("선택한 성별은 %\s입니다."),
                Check[0] ? hobby[0] : _T(""),
                Check[1] ? hobby[1] : _T(""),
                Check[2] ? hobby[2] : _T(""),
                sex[Radio]
            );
            SetDlgItemText(hDlg, IDC_EDIT_Output, output);
            break;
        /////////////////////////////////////////////////////////////// combo box & list box

        case IDC_Btn_Insert:
            GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
            if (_tcscmp(name, _T("")))
            {
                SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
                SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));

                SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)name);
            }
            break;

        case IDC_Btn_Delete:
            SendMessage(hCombo, CB_DELETESTRING, selection, 0);
            SendMessage(hList, LB_DELETESTRING, selection, 0);
            break;

        case IDC_COMBO_LIST:
            if (HIWORD(wParam) == CBN_SELCHANGE)
                selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
            break;

        case IDC_LIST_NAME:
            if (HIWORD(wParam) == LBN_SELCHANGE)
                selection = SendMessage(hList, LB_GETCURSEL, 0, 0);
            break;

        ///////////////////////////////////////////////////////////////
        }
        break;
    }
    return 0;
}

void Update()
{
    DWORD newTime = GetTickCount(); // 딜레이
    static DWORD oldTime = newTime;
    static DWORD accumulate = 0;
    int count = 1;

    if (newTime - oldTime < 100)
        return;

    // 시간보간
    accumulate += (newTime - oldTime);
    oldTime = newTime;

    if (accumulate >= 100)
    {
        count = accumulate / 100;
        accumulate %= 100;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        ptAni.x -= 10 * count;
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        ptAni.x += 10 * count;
    }
    else if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        ptAni.y -= 10 * count;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        ptAni.y += 10 * count;
    }
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
        GetClientRect(hWnd, &rectView);

        hMenu = GetMenu(hWnd);
        hSubMenu = GetSubMenu(hMenu, 0);

        Select = false;
        Copy = false;
        x = y = 50;

        SetTimer(hWnd, TIMER_ANI, 33, AniProc);
        //SetTimer(hWnd, TIMER_KEY, 1, KeyStateProc);
        CreateBitmap();
        break;

    //case WM_TIMER:
    //    switch (wParam)
    //    {
    //    //case TIMER_ANI:
    //    //    UpdateFrame(hWnd);
    //    }
    //    break;

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

    case WM_RBUTTONDOWN:
        //DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dialog1_Proc);
        if (!IsWindow(g_hDlg))
        {
            g_hDlg = CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_MotherlessDialog), hWnd, Dialog2_Proc);
            ShowWindow(g_hDlg, SW_SHOW);
        }
        break;

    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);

            //EnableMenuItem(hSubMenu, ID_EDITCOPY,  Select ? MF_ENABLED : MF_GRAYED);
            //EnableMenuItem(hSubMenu, ID_EDITPASTE, Copy   ? MF_ENABLED : MF_GRAYED);

            //if (Select)
            //    Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

            //Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

            DrawBitMapDoubleBuffering(hWnd, hdc);

            TextOut(hdc, 10, 10, sKeyState, _tcslen(sKeyState));

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
