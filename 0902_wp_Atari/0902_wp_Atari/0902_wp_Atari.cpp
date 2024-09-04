// 0902_wp_Atari.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0902_wp_Atari.h"

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
    LoadStringW(hInstance, IDC_MY0902WPATARI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0902WPATARI));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0902WPATARI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0902WPATARI);
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

void CreateBlocks(vector<Block*>& blocks, int offsetX, int offsetY, int blockWidth, int blockHeight)
{
    if (blocks.size())
        blocks.clear();

    int posX = offsetX;
    int posY = offsetY / 2;

    for (int i = 0; i < BLOCK_ROW; i++)
    {
        for (int j = 0; j < BLOCK_COL; j++)
        {
            Block* newBlock = new Block({
                posX + j * blockWidth,
                posY + i * blockHeight,
                posX + j * blockWidth + blockWidth,
                posY + i * blockHeight + blockHeight
            });
            blocks.push_back(newBlock);
        }
    }
}

void DrawBlocks(HDC& hdc, HBRUSH& hBrush, vector<Block*>& blocks)
{
    int blockCount = blocks.size();

    for (int i = 0; i < blockCount; i++)
    {
        blocks[i]->Draw(hdc, hBrush);
    }
    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
}

void DrawBalls(HDC& hdc, vector<Ball*> balls)
{
    int ballCount = balls.size();

    for (int i = 0; i < ballCount; i++)
        balls[i]->Draw(hdc);
}

void SetBlockSize(RECT& rectView, int& offsetX, int& offsetY, int& blockWidth, int& blockHeight)
{
    int screenWidth = rectView.right - rectView.left;
    int screenHeight = rectView.bottom - rectView.top;

    offsetX = screenWidth / OFFSET_X;
    offsetY = screenHeight / OFFSET_Y;

    blockWidth = (screenWidth - (offsetX * 2)) / BLOCK_COL;
    blockHeight = (screenHeight - (offsetY * 6)) / BLOCK_ROW;
}

void ShootBall(RECT& paddlePos, vector<Ball*>& balls)
{
    int posX = paddlePos.left + (paddlePos.right - paddlePos.left) / 2;
    int posY = paddlePos.top - BALL_SIZE;
    Ball* newBall = new Ball(posX, posY);
    balls.push_back(newBall);
}

/* 
# backMemDC
    화면에 보내기 직전의 완성된 메모리 DC
    오브젝트 선택 -> backMemDC로 복사 -> 다른 오브젝트 선택 -> 복사 ...
    backMemDC는 초기 1픽셀의 공간을 가지고 있다.

# backBitmap
    backMemDC의 크기 설정
    backMemDC에 도화지를 펼쳐준다.
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static RECT             rectView;
    static PAINTSTRUCT      ps;
    static HBRUSH           hBrush, oldBrush;
    static HDC              hdc, backMemDC;
    static vector<Block*>   blocks;
    static vector<Ball*>    balls;
    static int              offsetX, offsetY, blockWidth, blockHeight;
    static HBITMAP          backBitmap = NULL, hOldBitmap = NULL;
    static Paddle           paddle;

    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        SetBlockSize(rectView, offsetX, offsetY, blockWidth, blockHeight);
        CreateBlocks(blocks, offsetX, offsetY, blockWidth, blockHeight);
        SetTimer(hWnd, TIMER_ID, TIMER_INTERVAL, NULL);
        paddle.Init(rectView);
        break;

    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        SetBlockSize(rectView, offsetX, offsetY, blockWidth, blockHeight);
        CreateBlocks(blocks, offsetX, offsetY, blockWidth, blockHeight);
        InvalidateRect(hWnd, NULL, false);
        break;

    case WM_TIMER:
        for (int i = balls.size() - 1; i >= 0; i--)
        {
            Ball* ball = balls[i];
            for (int i = blocks.size() - 1; i >= 0; i--)
            {
                Block* block = blocks[i];

                if (ball->Collision(block->GetPos()))
                    block->TakeDamage(blocks, i);
            }
            ball->Collision(paddle.GetPos());
            ball->CheckWall(rectView);

            if (ball->IsDead())
            {
                balls.erase(balls.begin() + i);
                continue;
            }
            ball->Move();
        }
        InvalidateRect(hWnd, NULL, false);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

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

    case WM_KEYDOWN:
        paddle.Move(wParam, rectView);

        if (wParam == VK_SPACE && balls.empty())
            ShootBall(paddle.GetPos(), balls);
        break;

    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);

            // 화면DC 기반 메모리 DC 생성
            backMemDC = CreateCompatibleDC(hdc);

            // 도화지 준비 (비트맵 생성), 비트맵 선택
            backBitmap = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
            hOldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap);

            // 메모리 DC에 그리기
            FillRect(backMemDC, &rectView, (HBRUSH)(GetStockObject)(WHITE_BRUSH));

            DrawBlocks(backMemDC, hBrush, blocks);
            DrawBalls(backMemDC, balls);
            paddle.Draw(backMemDC, hBrush);

            // 화면에 복사
            BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, backMemDC, 0, 0, SRCCOPY);

            // 기존 비트맵 선택
            SelectObject(backMemDC, hOldBitmap);

            DeleteObject(backBitmap);
            DeleteObject(hBrush);
            DeleteDC(backMemDC);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        KillTimer(hWnd, TIMER_ID);
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
