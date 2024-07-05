/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <crtdbg.h>

void main(int argc, char** argv)
{
	// F5로 실행
	// 맨 앞
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	
	// 디버깅 콘솔에서 주소값을 참고, 다시 디버깅해보면 76은 18번째 줄을 가리킴
	_CrtSetBreakAlloc(76);
	
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * 4);

	// 끝내기 직전
	_CrtDumpMemoryLeaks();
}