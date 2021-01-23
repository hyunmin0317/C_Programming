#include <stdio.h>
#define MAX 30

print_matrix(int(*A)[MAX], int n, int m);
make_matrix(int(*A)[MAX], int n, int m);
sum_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int m);
multiply_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int s, int m);

int main(void)
{
	int An, Am, Bn, Bm;
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixS[MAX][MAX];
	int matrixM[MAX][MAX];

	printf("행렬 계산 프로그램\n");
	printf("\n첫번째 행렬을 입력하세요.\n");
	printf("행렬의 행 크기 입력: ");
	scanf("%d", &An);
	printf("행렬의 열 크기 입력: ");
	scanf("%d", &Am);
	printf("\n첫번째 행렬의 값을 입력하세요.\n");
	make_matrix(matrixA, An, Am);

	printf("\n두번째 행렬을 입력하세요.\n");
	printf("행렬의 행 크기 입력: ");
	scanf("%d", &Bn);
	printf("행렬의 열 크기 입력: ");
	scanf("%d", &Bm);
	printf("\n두번째 행렬의 값을 입력하세요.\n");
	make_matrix(matrixB, Bn, Bm);

	printf("\n두 행렬의 합\n");
	if (An != Bn || Am != Bm)
		printf("두 행렬의 합이 존재하지 않는다.\n");
	else
	{
		sum_matrix(matrixA, matrixB, matrixS, An, Am);
		print_matrix(matrixS, An, Am);
	}

	printf("\n두 행렬의 곱\n");
	if (Bm == An)
	{
		multiply_matrix(matrixA, matrixB, matrixM, An, Am, Bm);
		print_matrix(matrixM, An, Bm);
	}
	else
		printf("두 행렬의 곱이 존재하지 않는다.\n");
	
	return 0;
}

make_matrix(int(*A)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			printf("%d * %d 행렬의 값 입력: ", i + 1, j + 1);
			scanf("%d", &(*(A + i))[j]);
		}
}

print_matrix(int(*A)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %4d ", (*(A + i))[j]);
		printf("\n");
	}
}

sum_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*(S + i))[j] = (*(A + i))[j] + (*(B + i))[j];
}

multiply_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int s, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			(*(S + i))[j] = 0;
			for (int k = 0; k < s; k++)
				(*(S + i))[j] += (*(A + i))[k] * (*(B + k))[j];
		}
}