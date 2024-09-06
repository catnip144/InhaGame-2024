// 0902_wp_Atari.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#pragma comment(lib, "msimg32.lib")
#pragma once

#include "framework.h"
#include "objects.h"
#include "game_control.h"

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

void CreateBitmap()
{
    hBgImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_BG_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    // >> : Background
    if (hBgImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("배경 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hBgImage, sizeof(BITMAP), &bitBg);
    // << :

    // >> : Multiplier Item
    hMultiplierItemImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_ITEM_MULTIPLER_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hMultiplierItemImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("Multiplier Item 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hMultiplierItemImage, sizeof(BITMAP), &bitMultiplierItem);
    // << :

    // >> : Sticky Item
    hStickyItemImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_ITEM_STICKY_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hStickyItemImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("Sticky Item 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hStickyItemImage, sizeof(BITMAP), &bitStickyItem);
    // << :

    // >> : Stretch Item
    hStretchItemImage = (HBITMAP)LoadImage(NULL, TEXT(IMAGE_ITEM_STRETCH_PATH),
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hStretchItemImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("Stretch Item 이미지 로드 에러"), _T("에러"), MB_OK);
    }
    else
        GetObject(hStretchItemImage, sizeof(BITMAP), &bitStretchItem);
    // << :
}

void DrawBG(HWND& hWnd, HDC& hdc, int screenWidth, int screenHeight)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    hMemDC = CreateCompatibleDC(hdc);
    hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBgImage);
    bx = bitBg.bmWidth;
    by = bitBg.bmHeight;

    BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
    StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hMemDC, 0, 0, bx, by, SRCCOPY);

    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
}

void DrawItems(HDC& hdc, vector<Item*>& items)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    int itemCount = items.size();
    for (int i = 0; i < itemCount; i++)
    {
        hMemDC = CreateCompatibleDC(hdc);

        switch (items[i]->GetType())
        {
        case ITEM_MULTIPLY:
            hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMultiplierItemImage);
            bx = bitMultiplierItem.bmWidth / ITEM_SPRITE_COL;
            by = bitMultiplierItem.bmHeight;
            break;

        case ITEM_STICKY:
            hOldBitmap = (HBITMAP)SelectObject(hMemDC, hStickyItemImage);
            bx = bitStickyItem.bmWidth / ITEM_SPRITE_COL;
            by = bitStickyItem.bmHeight;
            break;

        case ITEM_STRETCH:
            hOldBitmap = (HBITMAP)SelectObject(hMemDC, hStretchItemImage);
            bx = bitStretchItem.bmWidth / ITEM_SPRITE_COL;
            by = bitStretchItem.bmHeight;
            break;

        default:
            return;
        }
        int posX = items[i]->GetPos().left;
        int posY = items[i]->GetPos().top;

        int xStart = items[i]->GetCurrentFrame() * bx;
        int yStart = 0;

        TransparentBlt(hdc, posX, posY, bx * ITEM_IMAGE_SIZE, by * ITEM_IMAGE_SIZE, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
        SelectObject(hMemDC, hOldBitmap);
        DeleteDC(hMemDC);
    }
}

void SetScreenSize(RECT& rectView, int& screenWidth, int& screenHeight)
{
    screenWidth = rectView.right - rectView.left;
    screenHeight = rectView.bottom - rectView.top;
}

void DrawScore(HWND& hWnd, HDC& hdc, int& screenWidth)
{
    HFONT font, oldfont;

    font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    oldfont = (HFONT)SelectObject(hdc, font);

    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    TCHAR str[100];
    swprintf(str, 100, L"Score: %d", gameScore);
    TextOut(hdc, screenWidth / 2 - 50, 10, str, lstrlen(str));

    SelectObject(hdc, oldfont);
    DeleteObject(font);
}

void DrawGameOverScreen(HDC& hdc, int& screenWidth, int& screenHeight)
{
    HFONT font, oldfont;

    font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    oldfont = (HFONT)SelectObject(hdc, font);

    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    TCHAR str[100];
    swprintf(str, 100, L"GAME OVER");
    TextOut(hdc, screenWidth / 2 - 110, screenHeight / 2 - 40, str, lstrlen(str));

    font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    SelectObject(hdc, font);

    swprintf(str, 100, L"Press Enter");
    TextOut(hdc, screenWidth / 2 - 70, screenHeight / 2 + 20, str, lstrlen(str));

    SelectObject(hdc, oldfont);
    DeleteObject(font);
}

void DrawTitleScreen(HDC& hdc, TCHAR playerName[], int textX, int& screenWidth, int& screenHeight)
{
    HFONT font, oldfont;

    font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    oldfont = (HFONT)SelectObject(hdc, font);

    SetBkMode(hdc, TRANSPARENT);

    TCHAR str[15];
    swprintf(str, 15, L"ATARI PONG");
    TextOut(hdc, screenWidth / 2 - 120, screenHeight / 2 - 100, str, lstrlen(str));

    font = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    SelectObject(hdc, font);
    TextOut(hdc, textX, screenHeight / 2 - 40, playerName, _tcslen(playerName));

    SelectObject(hdc, oldfont);
    DeleteObject(font);
}

void DrawResultScreen(HDC& hdc, TCHAR playerName[], int& screenWidth, int& screenHeight)
{
    HFONT font, oldfont;

    font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    oldfont = (HFONT)SelectObject(hdc, font);

    SetBkMode(hdc, TRANSPARENT);

    TCHAR str[15];
    swprintf(str, 15, L"RESULTS");
    int scoreTextX = screenWidth / 2 - 70;
    int scoreTextY = screenHeight / 9;

    TextOut(hdc, scoreTextX, scoreTextY, str, lstrlen(str));

    SelectObject(hdc, oldfont);
    DeleteObject(font);

    HPEN boxPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    HPEN oldPen = (HPEN)SelectObject(hdc, boxPen);
    HBRUSH myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

    Rectangle(hdc, screenWidth / 3, screenHeight / 4, screenWidth / 4 + 600, screenHeight / 3 + 380);

    font = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 3, 2, 1,
        VARIABLE_PITCH | FF_ROMAN, _T(UI_FONT_NAME));
    SelectObject(hdc, font);

    scoreTextX -= 50;
    scoreTextY += 150;

    TextOut(hdc, scoreTextX + 40, scoreTextY - 30, _T("NAME"), _tcslen(_T("NAME")));
    TextOut(hdc, scoreTextX + 230, scoreTextY - 30, _T("SCORE"), _tcslen(_T("SCORE")));

    for (int i = 0; i < MAX_SCORE_COUNT; i++)
    {
        if (scoreData[i].first == NULL) break;

        TCHAR number[100];
        swprintf(number, 100, L"%d.", i + 1);

        TCHAR scoreText[100];
        swprintf(scoreText, 100, L"%d", scoreData[i].second);

        TextOut(hdc, scoreTextX - 100, scoreTextY + 20 * i, number, _tcslen(number));
        TextOut(hdc, scoreTextX + 50, scoreTextY + 20 * i, scoreData[i].first, _tcslen(scoreData[i].first));
        TextOut(hdc, scoreTextX + 250, scoreTextY + 20 * i, scoreText, _tcslen(scoreText));
    }
    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);
    DeleteObject(boxPen);
    DeleteObject(myBrush);
}

void GetInput(WPARAM& wParam, TCHAR playerName[], int& count, int& textX)
{
    if (wParam == VK_BACK)
    {
        if (count > 0)
        {
            count--;
            textX += 6;
        }
    }
    else if (wParam == VK_RETURN)
        gameState = GAMESTATE_PLAY;
    else
    {
        if (count == MAX_NAME_LENGTH) return;
        playerName[count++] = wParam;
        textX -= 6;
    }
    playerName[count] = NULL;
}

void MoveItems(vector<Item*>& items, vector<Ball*>& balls, Paddle& paddle, RECT& rectView)
{
    int itemCount = items.size();

    for (int i = itemCount - 1; i >= 0; i--)
    {
        bool canMove = items[i]->Move(rectView);
        if (!canMove)
        {
            items.erase(items.begin() + i);
            continue;
        }
        bool hasCollided = items[i]->Collision(paddle.GetPos());
        if (hasCollided)
        {
            items[i]->ItemEffect(balls, paddle);
            items.erase(items.begin() + i);
        }
    }
}

void MoveBalls(vector<Ball*>& balls, vector<Block*>& blocks, vector<Item*>& items, Paddle& paddle, RECT& rectView)
{
    for (int i = balls.size() - 1; i >= 0; i--)
    {
        Ball* ball = balls[i];
        for (int i = blocks.size() - 1; i >= 0; i--)
        {
            Block* block = blocks[i];

            if (ball->Collision(block->GetPos()))
                block->TakeDamage(blocks, items, i);
        }
        bool hasCollided = ball->Collision(paddle.GetPos());

        if (hasCollided && !ball->IsStuck() && paddle.IsSticky())
            paddle.CollectBalls(ball);

        ball->CheckWall(rectView);
        if (ball->IsDead())
        {
            balls.erase(balls.begin() + i);
            CheckGameOver(balls.empty());
            continue;
        }
        ball->Move();
    }
}

void CreateBlocks(vector<Block*>& blocks, int offsetX, int offsetY, int blockWidth, int blockHeight)
{
    if (blocks.size())
        blocks.clear();

    int posX = offsetX;
    int posY = offsetY;

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
            int hp = max(1, min(MAX_BLOCK_HP, BLOCK_ROW - i));
            newBlock->SetHp(hp);
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
}

void DrawBalls(HDC& hdc, HBRUSH& hBrush, vector<Ball*>& balls)
{
    int ballCount = balls.size();

    for (int i = 0; i < ballCount; i++)
        balls[i]->Draw(hdc, hBrush);
}

void SetBlockSize(int screenWidth, int screenHeight, int& offsetX, int& offsetY, int& blockWidth, int& blockHeight)
{
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

void ResetGame(vector<Block*>& blocks, vector<Ball*>& balls, vector<Item*>& items, Paddle& paddle, RECT& rectView)
{
    for (int i = 0; i < blocks.size(); i++)
        delete blocks[i];

    for (int i = 0; i < balls.size(); i++)
        delete balls[i];

    for (int i = 0; i < items.size(); i++)
        delete items[i];

    blocks.clear();
    balls.clear();
    items.clear();
    paddle.ReleaseStuckBalls();
    paddle.Init(rectView);

    gameScore = 0;
    isGameOver = false;
}

void SaveScore()
{
    FILE* fPtr;
    int line = 0;

#ifdef _UNICODE
    _tfopen_s(&fPtr, _T(SCORE_FILE_PATH), _T("w, ccs = UNICODE"));
#else
    _tfopen_s(&fPtr, _T(SCORE_FILE_PATH), _T("w"));
#endif

    if (fPtr == NULL)
        return;

    for (int i = 0; i < MAX_SCORE_COUNT; i++)
    {
        if (scoreData[i].first == NULL)
            break;

        _fputts(scoreData[i].first, fPtr);
        _fputts(_T("\n"), fPtr);

        TCHAR score[100];
        swprintf(score, 100, L"%d", scoreData[i].second);

        _fputts(score, fPtr);
        _fputts(_T("\n"), fPtr);
        line++;
    }
    fclose(fPtr);
}

void LoadScore(TCHAR playerName[])
{
    FILE* fPtr;
    TCHAR* buffer = new TCHAR[50];
    int line = 0;
    int minScore = gameScore;
    int minScoreIndex = -1;

#ifdef _UNICODE
    _tfopen_s(&fPtr, _T(SCORE_FILE_PATH), _T("r, ccs = UNICODE"));
#else
    _tfopen_s(&fPtr, _T(SCORE_FILE_PATH), _T("r"));
#endif

    if (fPtr == NULL)
        return;
    
    while (_fgetts(buffer, 50, fPtr) != NULL)
    {  

        if (line / 2 >= MAX_SCORE_COUNT)
            break;
        
        if (buffer[_tcslen(buffer) - 1] == _T('\n'))
            buffer[_tcslen(buffer) - 1] = NULL;

        if (line % 2 == 0)
        {
            scoreData[line / 2].first = buffer;
        }
        else
        {
            scoreData[line / 2].second = _ttoi(buffer);
            minScore = min(minScore, scoreData[line / 2].second);
            minScoreIndex = line / 2;
        }
        buffer = new TCHAR[50];
        ++line;
    }
    if (line / 2 < MAX_SCORE_COUNT)
        scoreData[line / 2] = { playerName, gameScore };

    else if (minScore != gameScore)
        scoreData[minScoreIndex] = { playerName, gameScore };

    fclose(fPtr);
    sort(scoreData.begin(), scoreData.end(), CompareScore);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC              hdc, backMemDC;
    static RECT             rectView;
    static PAINTSTRUCT      ps;
    static HBRUSH           hBrush, oldBrush;
    static vector<Block*>   blocks;
    static vector<Ball*>    balls;
    static vector<Item*>    items;
    static HBITMAP          backBitmap, hOldBitmap;
    static Paddle           paddle;
    static int              offsetX, offsetY, blockWidth, blockHeight, screenWidth, screenHeight;

    static TCHAR            playerName[MAX_NAME_LENGTH + 1] = { 0, };
    static int              count = 0;
    static int              textX;

    switch (message)
    {
    case WM_CREATE:
        srand(time(NULL));
        GetClientRect(hWnd, &rectView);
        SetScreenSize(rectView, screenWidth, screenHeight);

        SetBlockSize(screenWidth, screenHeight, offsetX, offsetY, blockWidth, blockHeight);
        CreateBlocks(blocks, offsetX, offsetY, blockWidth, blockHeight);
        CreateBitmap();

        SetTimer(hWnd, TIMER_ID, TIMER_INTERVAL, NULL);
        SetTimer(hWnd, TIMER_ANI, 140, NULL);

        paddle.Init(rectView);
        textX = screenWidth / 2 - 10;
        break;

    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        SetScreenSize(rectView, screenWidth, screenHeight);

        SetBlockSize(screenWidth, screenHeight, offsetX, offsetY, blockWidth, blockHeight);
        CreateBlocks(blocks, offsetX, offsetY, blockWidth, blockHeight);

        InvalidateRect(hWnd, NULL, false);
        break;

    case WM_TIMER:
        switch (wParam)
        {
            case TIMER_ID:
            {
                if (!isGameOver)
                {
                    MoveBalls(balls, blocks, items, paddle, rectView);
                    MoveItems(items, balls, paddle, rectView);
                }
                break;
            }
            case TIMER_ANI:
            {
                if (!isGameOver)
                {
                    for (Item* item : items)
                        item->UpdateFrame();
                    break;
                }
            }
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
        switch (gameState)
        {
        case GAMESTATE_TITLE:
            GetInput(wParam, playerName, count, textX);
            break;

        case GAMESTATE_PLAY:
            paddle.Move(wParam, rectView);

            if (wParam == VK_SPACE)
            {
                if (!isGameOver && balls.empty())
                    ShootBall(paddle.GetPos(), balls);

                else if (paddle.IsSticky())
                {
                    paddle.SetIsSticky(false);
                    paddle.ReleaseStuckBalls();
                }
                break;
            }
            else if (wParam == VK_RETURN)
            {
                if (isGameOver)
                {
                    LoadScore(playerName);
                    SaveScore();
                    gameState = GAMESTATE_RESULTS;
                }
            }
            break;

        case GAMESTATE_RESULTS:
            ResetGame(blocks, balls, items, paddle, rectView);
            CreateBlocks(blocks, offsetX, offsetY, blockWidth, blockHeight);
            gameState = GAMESTATE_TITLE;
            break;

        default:
            break;
        }
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

            DrawBG(hWnd, backMemDC, screenWidth, screenHeight);

            switch (gameState)
            {
            case GAMESTATE_TITLE:
                DrawTitleScreen(backMemDC, playerName, textX, screenWidth, screenHeight);
                break;

            case GAMESTATE_PLAY:
                DrawScore(hWnd, backMemDC, screenWidth);
                DrawBlocks(backMemDC, hBrush, blocks);
                DrawItems(backMemDC, items);
                DrawBalls(backMemDC, hBrush, balls);
                paddle.Draw(backMemDC, hBrush);

                if (isGameOver)
                    DrawGameOverScreen(backMemDC, screenWidth, screenHeight);
                break;

            case GAMESTATE_RESULTS:
                DrawResultScreen(backMemDC, playerName, screenWidth, screenHeight);
                break;

            default:
                break;
            }
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
        DeleteObject(backBitmap);
        DeleteObject(hOldBitmap);
        DeleteObject(hBgImage);
        DeleteObject(hMultiplierItemImage);

        KillTimer(hWnd, TIMER_ID);
        KillTimer(hWnd, TIMER_ANI);

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
