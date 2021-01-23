#include <stdio.h>
#include <math.h>
#define MAX 5

void make_matrix(int(*A)[MAX], int n, int m);
void print_matrix(int(*A)[MAX], int n, int m, char a);
int det_matrix(int(*A)[MAX], int n);

int main(void)
{
	int matrixA[MAX][MAX];
	int n;
	printf("\n 행렬식 계산 프로그램\n\n");
	printf(" 행렬의 크기 입력: ");
	scanf("%d", &n);
	make_matrix(matrixA, n, n);
	print_matrix(matrixA, n, n, 'A');
	printf("\n 입력한 행렬의 행렬식 값\n");
	printf(" Det(A) = %d\n", det_matrix(matrixA, n));
	return 0;
}

void make_matrix(int(*A)[MAX], int n, int m)
{
	printf("\n 행렬의 값을 입력하세요.\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			printf(" %d * %d 행렬의 값을 입력: ", i + 1, j + 1);
			scanf("%d", &(*(A + i))[j]);
		}
}

void print_matrix(int(*A)[MAX], int n, int m, char a)
{
	printf("\n 입력한 행렬 %c\n", a);
	for (int i = 0; i < n; i++)
	{
		printf(" |\t");
		for (int j = 0; j < m; j++)
			printf("%2d\t", (*(A + i))[j]);
		printf(" l\n");
	}
}

int det_matrix(int(*A)[MAX], int n)
{
	int i, j, k, y;
	int det = 0;
	int temp[MAX][MAX];
	if (n != 1)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				y = 0;
				for (k = 0; k < n; k++)
					if (k != i)
						temp[j - 1][y++] = A[j][k];
			}
			det += pow(-1, i) * A[0][i] * det_matrix(temp, n - 1);
		}
		return det;
	}
	else
		return A[0][0];
}