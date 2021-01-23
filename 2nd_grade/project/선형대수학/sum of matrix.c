#include <stdio.h>
#define MAX 30

int main(void)
{
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixSum[MAX][MAX];
	int n, m;

	printf("행렬의 합 계산 프로그램\n\n");
	printf("덧셈하려는 행렬의 크기를 입력하세요.\n");
	printf("행렬의 행 크기 입력: ");
	scanf("%d", &n);
	printf("행렬의 열 크기 입력: ");
	scanf("%d", &m);

	printf("\n첫번째 행렬의 값을 입력하세요.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d*%d 행렬의 값 입력: ", i+1, j+1);
			scanf("%d", &matrixA[i][j]);
		}
	}

	printf("\n두번째 행렬의 값을 입력하세요.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d*%d 행렬의 값 입력: ", i + 1, j + 1);
			scanf("%d", &matrixB[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{ 
			matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	printf("\n두 행렬 덧셈의 결과값\n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %4d ", matrixSum[i][j]);
		}
		printf("\n");
	}
	return 0;
}