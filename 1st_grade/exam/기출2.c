#include <stdio.h>
#include <stdlib.h>
#define MAX 256

typedef struct
{
	int a;
	char A[MAX];
}SENTENCE;


int main(void)
{
	FILE* fp = fopen("eq.txt", "rt");
	if (fp == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	int a;
	fscanf(fp, "%d", &a);
	SENTENCE* A = (SENTENCE*)malloc(sizeof(SENTENCE) * a);

	char* p = fgets(A->A, MAX, fp);
	while (p != NULL)
	{
		printf("%s", A->A);
		p = fgets(A->A, MAX, fp);
	}


	char B[MAX];
	printf("개수를 세고 싶은 단어(종료 QUIT): ");
	gets(B, MAX);
	while (strcmp(B, "QUIT") != 0)
	{
		printf("개수를 세고 싶은 단어(종료 QUIT): ");
		int len = strlen(A->A);
		for (int i = 0; i < len; i++)
		{

		}
		
		gets(B, MAX);
	}
	
	fclose(fp);
	return 0;
}

