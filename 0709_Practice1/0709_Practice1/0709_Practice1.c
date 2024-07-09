/* Q. 파일 복사 프로그램
복사할 파일명과 복사 후 생성되는 파일명을 입력받아서 파일을 복사하는 프로그램을 작성하라.
단, txt파일 뿐만 아니라 이미지 파일 등, 모든 종류의 파일에 다 동일하게 적용할 수 있어야 한다.
복사 진행 관정을 백분율로 화면에 표시해주도록 하고 한번에 n 바이트씩 복사하도록 한다.

ex > 4 바이트
원본파일 : source.txt
대상파일 : dest.txt

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

long GetFileSize(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	long fileSize = ftell(fp);
	rewind(fp);
	return fileSize;
}

void MyCopyFile(FILE* fpSource, FILE** fpDest, int chunkSize)
{
	long totalFileSize = GetFileSize(fpSource);
	long currentFileSize = 0;
	double progress;
	char* buffer = (char*)malloc((chunkSize + 1) * sizeof(char));

	while (!feof(fpSource))
	{
		system("cls");
		buffer = memset(buffer, 0, (chunkSize + 1) * sizeof(char));

		fread(buffer, sizeof(char), chunkSize, fpSource);
		fwrite(buffer, sizeof(char), chunkSize, *fpDest);
		
		currentFileSize = ftell(fpSource);
		progress = (double)currentFileSize / totalFileSize * 100;

		printf("복사 진행 정도 : %d%%\n", (int)progress);
		printf("파일 사이즈 : %ld bytes\n", currentFileSize);
		Sleep(10);
	}
	printf("복사 완료!\n");
	free(buffer);
}

void main()
{
	int chunkSize;
	char sourcePath[100], destPath[100], fileName[100];

	printf("파일명 : ");
	scanf("%s", fileName);
	sprintf_s(sourcePath, sizeof(sourcePath), "../data/%s", fileName);

	printf("복사할 파일명 : ");
	scanf("%s", fileName);
	sprintf_s(destPath, sizeof(destPath), "../data/%s", fileName);

	printf("복사할 바이트 단위 : ");
	scanf("%d", &chunkSize);

	FILE* fpSource = fopen(sourcePath, "rb");
	FILE* fpDest = fopen(destPath, "wb");

	MyCopyFile(fpSource, &fpDest, chunkSize);

	fclose(fpSource);
	fclose(fpDest);
}