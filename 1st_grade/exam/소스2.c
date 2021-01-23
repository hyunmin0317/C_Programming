#include <stdio.h>

//feof함수 기반의 파일복사 프로그램
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* dest = fopen("dest.txt", "wt");
	int ch;
	if (src == NULL || dest == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}
	while ((ch=fgetc(src)) != EOF)
	{
		fputc(ch, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}

//문자열 단위 파일복사 프로그램
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* dest = fopen("dest.txt", "wt");
	char str;
	if (src == NULL || dest == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}
	while (fgets(str,sizeof(str),src) != NULL)
	{
		fputs(str, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}