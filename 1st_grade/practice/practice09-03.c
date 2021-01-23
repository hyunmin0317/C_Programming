#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
	char word[MAX];
	int sum;
}ASCII;

int sum(char* s)
{
	int sum = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		sum += s[i];
	}
	return sum;
}

int main(void)
{
	int n;
	printf("입력할 단어의 개수: ");
	scanf("%d", &n);
	ASCII* A = (ASCII*)malloc(sizeof(ASCII) * n);
	for (int i = 0; i < n; i++)
	{
		printf("단어%d: ", i + 1);
		scanf("%s", A[i].word);
		A[i].sum = sum(A[i].word);
	}
	for (int i = 0; i < n; i++)
	{
		printf("단어%d의 아스키코드 합: %d\n", i + 1, A[i].sum);
	}
	return 0;
}