/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	//FILE* fp;
	//fp = fopen("../data/a.txt", "r");

	//if (fp == NULL)
	//{
	//	printf("read file open failed\n");
	//	return;
	//}
	//printf("read file success!\n");

	//int ch;
	//while (1)
	//{
	//	ch = fgetc(fp);
	//	if (ch == EOF)
	//		break;
	//	putchar(ch);
	//}
	//printf("\n");
	//fclose(fp);

	//fp = fopen("../data/b.txt", "w");
	//if (fp == NULL)
	//{
	//	printf("write file open failed\n");
	//	return;
	//}
	//printf("write file open success!\n");
	//
	//char str[] = "banana";
	//ch = 0;
	//while (str[ch] != '\0')
	//{
	//	fputc(str[ch], fp);
	//	ch++;
	//}
	//fputc('\n', fp);
	//fclose(fp);

	////////////////////////////////////////////////////

	//FILE* fp, *fp2;
	//fp = fopen("../data/a.txt", "r");

	//// read file
	//if (fp == NULL)
	//{
	//	printf("read file open failed\n");
	//	return;
	//}
	//printf("read file open success!\n");

	//// write file
	//fp2 = fopen("../data/b.txt", "w");
	//if (fp2 == NULL)
	//{
	//	printf("write file open failed\n");
	//	return;
	//}
	//printf("write file open success!\n");

	//char ch;
	//while (1)
	//{
	//	ch = fgetc(fp);
	//	if (ch == EOF) break;
	//	fputc(ch, fp2);
	//}
	//fputc('\n', fp2);
	//
	//fclose(fp);
	//fclose(fp2);

	////////////////////////////////////////////////////

	//FILE* fp;
	//int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	//int res;

	//fp = fopen("a.txt", "wb");
	//for (int i = 0; i < 10; i++)
	//	fputc(ary[i], fp);
	//fclose(fp);

	//fp = fopen("a.txt", "rt");
	//while (1)
	//{
	//	res = fgetc(fp);
	//	if (res == EOF) break;
	//	printf("%4d", res);
	//}
	//fclose(fp);

	////////////////////////////////////////////////////

	//FILE* fp;
	//char str[20];

	//fp = fopen("../data/a.txt", "a+"); // append
	//if (fp == NULL)
	//{
	//	printf("파일을 만들지 못했습니다.\n");
	//	return;
	//}
	//while (1)
	//{
	//	printf("과일 이름 : ");
	//	scanf("%s", str);

	//	if (!strcmp(str, "end"))
	//		break;
	//	else if (!strcmp(str, "list"))
	//	{
	//		fseek(fp, 0, SEEK_SET);
	//		while (1)
	//		{
	//			fgets(str, sizeof(str), fp);

	//			if (feof(fp))
	//			{
	//				break;
	//			}

	//			printf("%s", str);
	//		}
	//	}
	//	else
	//		fprintf(fp, "%s\n", str);
	//}
	//fclose(fp);

	////////////////////////////////////////////////////

	//FILE* ifp, * ofp;
	//char name[20];
	//int kor, eng, math, total, res;
	//double avg;

	//ifp = fopen("../data/a.txt", "r");
	//if (ifp == NULL)
	//{
	//	printf("입력 파일을 열지 못했습니다.\n");
	//	return;
	//}
	//ofp = fopen("../data/b.txt", "w");
	//if (ofp == NULL)
	//{
	//	printf("출력 파일을 열지 못했습니다.\n");
	//	return;
	//}
	//while (1)
	//{
	//	res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
	//	if (res == EOF)
	//		break;
	//	
	//	total = kor + eng + math;
	//	avg = total / 3.0;
	//	fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	//}
	//fclose(ifp);
	//fclose(ofp);

	////////////////////////////////////////////////////

	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("../data/a.txt", "wt");
	fprintf(afp, "%d", num);

	bfp = fopen("../data/b.txt", "wb");
	fwrite(&num, sizeof(num), 1, bfp);

	fclose(afp);
	fclose(bfp);

	bfp = fopen("../data/b.txt", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);
}