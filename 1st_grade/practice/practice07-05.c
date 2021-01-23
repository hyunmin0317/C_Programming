#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void copyArray(int* dest, int* src, int len)
{
	for (int i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
}

int main(void)
{
	int A[MAX];
	int B[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		A[i] = rand() % 10;
		printf("%d\n", A[i]);
	}
	printf("\n");
	copyArray(B, A, MAX);
	for (int i = 0; i < MAX; i++)
	{
		printf("%d\n", B[i]);
	}
	return 0;
}