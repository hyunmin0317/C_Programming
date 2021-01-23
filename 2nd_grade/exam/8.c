#include <stdio.h>
#define MAX 7

int main(void)
{
	int a[][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},{21, 22, 23, 24, 25}};
	double A[MAX][MAX] = { 0, };
	int i, j;
	for (i = 0; i < 5; i++)
	{ 
		for (j = 0; j < 5; j++)
		{ 
			A[i][j] = a[i][j];
			A[i][5] += a[i][j];
		}
		A[i][6] = A[i][5] / 5;
		A[6][6] += A[i][6];
	}

	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 5; i++)
			A[5][j] += a[i][j];
		A[5][5] += A[j][5];
		A[6][j] = A[5][j] / 5;
		A[6][6] += A[6][j];
	}
	A[6][6] /= 10;
	for (int i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
			if (A[i][j] == 0)
				printf("       ");
			else
				printf("%6.2f ", A[i][j]);
		printf("\n");
	}
	return 0;
}