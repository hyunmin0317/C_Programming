#include <stdio.h>
#define MAX 30

int main(void)
{
	int i, j, k;
	int An, Am, Bn, Bm;
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixS[MAX][MAX];

	printf("행렬의 곱 계산 프로그램\n");
	printf("\n첫번째 행렬을 입력하세요.\n");
	printf("첫번째 행렬의 행 크기 입력: ");
	scanf("%d", &An);
	printf("첫번째 행렬의 열 크기 입력: ");
	scanf("%d", &Am);
	printf("\n첫번째 행렬의 값을 입력하세요.\n");
	for (i = 0; i < An; i++)
		for (j = 0; j < Am; j++)
		{
			printf("%d * %d 행렬의 값 입력: ", i + 1, j + 1);
			scanf("%d", &matrixA[i][j]);
		}

	printf("\n두번째 행렬을 입력하세요.\n");
	printf("두번째 행렬의 행 크기 입력: ");
	scanf("%d", &Bn);
	printf("두번째 행렬의 열 크기 입력: ");
	scanf("%d", &Bm);
	printf("\n두번째 행렬의 값을 입력하세요.\n");
	for (i = 0; i < Bn; i++)
		for (j = 0; j < Bm; j++)
		{
			printf("%d * %d 행렬의 값 입력: ", i + 1, j + 1);
			scanf("%d", &matrixB[i][j]);
		}

	for (i = 0; i < An; i++)
		for (j = 0; j < Bm; j++)
		{
			matrixS[i][j] = 0;
			for (k = 0; k < Am; k++)
				matrixS[i][j] += matrixA[i][k] * matrixB[k][j];
		}

	printf("\n두 행렬 곱의 결과값\n");
	for (i = 0; i < An; i++)
	{
		for (j = 0; j < Bm; j++)
			printf(" %4d ", matrixS[i][j]);
		printf("\n");
	}
	return 0;
}