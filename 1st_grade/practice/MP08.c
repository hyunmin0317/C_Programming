#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

typedef struct
{
	char str[MAX];
	int len;
	int word;
}STR;

int main(void)
{
	int num;
	int length = 0;
	int wordsum = 0;

	printf("입력할 문자열 개수: ");
	scanf("%d", &num);
	getchar();

	STR* A = (STR*)malloc(sizeof(STR) * num);
	
	for (int i = 0; i < num; i++)
	{
		printf("문자열%d: ", i + 1);
		gets(A[i].str);
	}
	
	for (int i = 0; i < num; i++)
	{
		A[i].len = strlen(A[i].str);
	}

	for (int i = 0; i < num; i++)
	{
		int count = 0;
		char* word = strtok(A[i].str, " \t");
		while (word != NULL)
		{
			word = strtok(NULL, " \t");
			count++;
		}
		A[i].word = count;
	}
	
	for (int i = 0; i < num; i++)
	{
		printf("%d번째 문자열의 길이: %d\n", i + 1, A[i].len);
		printf("%d번째 단어의 개수: %d\n", i + 1, A[i].word);
		length += A[i].len;
		wordsum += A[i].word;
	}
	printf("문자열들의 길이의 합: %d\n단어 개수의 합: %d\n", length, wordsum);
	free(A);
	return 0;
}