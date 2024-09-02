// 0902_wp_2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0902_wp_2.h"
#include "resource.h"
#include "commdlg.h"
#include <fstream>
#include <vector>

#define MAX_LOADSTRING 100

using std::vector;

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
    LoadStringW(hInstance, IDC_MY0902WP2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0902WP2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0902WP2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0902WP2);
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

#define MAX_SENTENCE_LENGTH 1000

void OutFromFile(TCHAR filename[], HWND hwnd, vector<TCHAR*>& chatLogs)
{
    FILE* fPtr;
    HDC hdc;
    int line = 0;
    TCHAR* buffer = new TCHAR[MAX_SENTENCE_LENGTH];
    hdc = GetDC(hwnd);

#ifdef _UNICODE
    _tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
    _tfopen_s(&fPtr, filename, _T("r"));
#endif

    InvalidateRgn(hwnd, NULL, TRUE);

    while (_fgetts(buffer, 100, fPtr) != NULL)
    {
        if (buffer[_tcslen(buffer) - 1] == _T('\n'))
            buffer[_tcslen(buffer) - 1] = NULL;

        //TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
        //line++;

        chatLogs.push_back(buffer);
        buffer = new TCHAR[MAX_SENTENCE_LENGTH];
    }
    fclose(fPtr);
    ReleaseDC(hwnd, hdc);
}

void SaveFile(TCHAR filename[], vector<TCHAR*>& chatLogs)
{
    FILE* fPtr;
    int line = 0;

#ifdef _UNICODE
    _tfopen_s(&fPtr, filename, _T("w, ccs = UNICODE"));
#else
    _tfopen_s(&fPtr, filename, _T("w"));
#endif

    while (line < chatLogs.size())
    {
        _fputts(chatLogs[line], fPtr);
        _fputts(_T("\n"), fPtr);
        line++;
    }
    fclose(fPtr);
}

void ClearChatLogs(vector<TCHAR*>& chatLogs)
{
    for (int i = chatLogs.size() - 1; i >= 0; i--)
        delete[] chatLogs[i];
    chatLogs.clear();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR    str[MAX_SENTENCE_LENGTH];
    static int      count = 0;
    static int      textX = 10;
    static int      textY = 200;
    static int      chatBufferSize = 10;
    static SIZE     caretSize;
    static vector<TCHAR*> chatLogs;

    OPENFILENAME ofn, sfn;
    TCHAR str2[100], lpstrFile[100] = _T("");
    TCHAR filter[] = _T("every File(*.*)\0*.*\0Text File(.doc, .txt)\0*.txt;*.doc\0");

    switch (message)
    {

    case WM_CREATE:
        count = 0;
        CreateCaret(hWnd, NULL, 5, 15);
        ShowCaret(hWnd);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;

            case ID_FileOpen:
                memset(&ofn, 0, sizeof(OPENFILENAME));
                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hWnd;
                ofn.lpstrFilter = filter;
                ofn.lpstrFile = lpstrFile;
                ofn.nMaxFile = 256;
                ofn.lpstrInitialDir = _T("."); // 현재 위치

                if (GetOpenFileName(&ofn) != 0)
                {
                    _stprintf_s(str2, _T("%s 파일을 열겠습니까?"), ofn.lpstrFile);
                    MessageBox(hWnd, str2, _T("열기 선택"), MB_OK);
                    ClearChatLogs(chatLogs);
                    OutFromFile(ofn.lpstrFile, hWnd, chatLogs);
                }
                break;

            case ID_FILESAVE:
                memset(&sfn, 0, sizeof(OPENFILENAME));
                sfn.lStructSize = sizeof(OPENFILENAME);
                sfn.hwndOwner = hWnd;
                sfn.lpstrFilter = filter;
                sfn.lpstrFile = lpstrFile;
                sfn.nMaxFile = 256;
                sfn.lpstrInitialDir = _T(".");
                if (GetSaveFileName(&sfn) != 0)
                {
                    _stprintf_s(str2, _T("%s 파일로 저장하겠습니까?"), sfn.lpstrFile);
                    MessageBox(hWnd, str2, _T("저장하기 선택"), MB_OK);
                    SaveFile(sfn.lpstrFile, chatLogs);
                }
                break;

            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_CHAR:
        if (wParam == VK_BACK)
        {
            if (count > 0)
                count--;
            str[count] = NULL;
        }
        else if (wParam == VK_RETURN)
        {
            TCHAR* copied = new TCHAR[1000];
            for (int i = 0; i < 1000; i++)
            {
                copied[i] = str[i];
                str[i] = NULL;
            }
            chatLogs.push_back(copied);
            count = 0;
        }
        else
            str[count++] = wParam;

        InvalidateRgn(hWnd, NULL, TRUE);
        break;
    
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        SetTextColor(hdc, RGB(0, 0, 0));

        int yPos = textY;
        int chatLogCount = chatLogs.size();

        for (int i = chatLogCount - 1, j = 0; j < chatLogCount; i--, j++)
        {
            yPos -= 20;
            TextOut(hdc, 0, yPos, chatLogs[i], _tcslen(chatLogs[i]));
        }
        SetTextColor(hdc, RGB(0, 0, 255));
        TextOut(hdc, 0, textY, _T(">"), _tcslen(_T(">")));
        TextOut(hdc, textX, textY, str, _tcslen(str));

        GetTextExtentPoint(hdc, str, _tcslen(str), &caretSize);
        SetCaretPos(textX + caretSize.cx, textY);

        EndPaint(hWnd, &ps);
    }
        break;

    case WM_DESTROY:
        HideCaret(hWnd);
        DestroyCaret();
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
