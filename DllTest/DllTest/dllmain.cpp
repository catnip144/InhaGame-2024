// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"

int refCount = 0;
int* intPtr = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: // dll 이 로드될 때 한번 호출
        if (refCount == 0)
        {
            intPtr = new int[100];
        }
        refCount++;
        break;
    case DLL_THREAD_ATTACH: break;
    case DLL_THREAD_DETACH: break;
    case DLL_PROCESS_DETACH: // reference count가 0이 될 때 메모리 할당 해제 코드 넣어도 된다.
        refCount--;
        if (refCount == 0)
        {
            delete[] intPtr;
        }
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void dll_TextOut(HDC hdc, char* str)
{
    static TCHAR sText[128];
    wsprintf(sText, TEXT("DLL TextOut : == %s == "), (TCHAR*)str);
    TextOut(hdc, 10, 10, sText, lstrlen(sText));
}