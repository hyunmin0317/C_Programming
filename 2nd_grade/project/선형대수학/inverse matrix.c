#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	double** m_data;
	int m_size;
}MATRIX;

void initMatrix(MATRIX* A, int n);
void deleteMatrix(MATRIX* A);
void inputMatrix(MATRIX* A);
void printMatrix(MATRIX matrix);
double determinant(MATRIX matrix);
MATRIX transpose(MATRIX matrix);
MATRIX minorMatrix(MATRIX matrix, int col, int row);
MATRIX cofactorMatrix(MATRIX matrix);
MATRIX adjoint(MATRIX matrix);
MATRIX inverseMatrix(MATRIX matrix);

int main(void)
{
	MATRIX matrix;
	MATRIX inverse;
	int n;
	double det = 0;
	printf(" 수반행렬을 이용한 역행렬 계산 프로그램\n");
	printf("\n 행렬의 크기입력: ");
	scanf("%d", &n);
	initMatrix(&matrix, n);
	initMatrix(&inverse, n);
	inputMatrix(&matrix);
	det = determinant(matrix);
	inverse = inverseMatrix(matrix);
	printf("\n 입력한 행렬의 행렬식 값\n");
	printf(" Det(A) = %.3lf\n\n", det);
	printf(" 역행렬 = \n");
	printMatrix(inverse);
	printf("\n");
	deleteMatrix(&matrix);
	deleteMatrix(&inverse);
	return 0;
}

void initMatrix(MATRIX* A, int n)
{
	A->m_data = (double**)malloc(sizeof(double*) * n);
	for (int i = 0; i < n; i++)
		A->m_data[i] = (double*)malloc(sizeof(double) * n);
	A->m_size = n;
}

void deleteMatrix(MATRIX* A)
{
	for (int i = 0; i < A->m_size; i++)
		free(A->m_data[i]);
	free(A->m_data);
}

void inputMatrix(MATRIX* A)
{
	printf("\n 행렬의 값을 입력하세요.\n");
	for (int i = 0; i < A->m_size; i++)
		for (int j = 0; j < A->m_size; j++)
		{
			printf(" %d * %d 행렬의 값을 입력: ", i + 1, j + 1);
			scanf("%lf", &A->m_data[i][j]);
		}
}

void printMatrix(MATRIX matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
	{ 
		printf("\t|\t");
		for (int j = 0; j < matrix.m_size; j++)
			printf("%.3lf \t", matrix.m_data[i][j]);
		printf("|\n");
	}
}

double determinant(MATRIX matrix)
{
	double det = 0;
	int sign = -1;
	if (matrix.m_size == 2)
	{
		det = matrix.m_data[0][0] * matrix.m_data[1][1] - matrix.m_data[1][0] * matrix.m_data[0][1];
		return det;
	}
	for (int i = 0; i < matrix.m_size; i++)
	{
		MATRIX minor;
		initMatrix(&minor, matrix.m_size);
		minor = minorMatrix(matrix, 0, i);
		det = det + sign * matrix.m_data[i][0] * determinant(minor);
		sign *= -1;
	}
	return det;
}

MATRIX transpose(MATRIX matrix)
{
	MATRIX Result;
	initMatrix(&Result, matrix.m_size);
	for (int i = 0; i < matrix.m_size; i++)
		for (int j = 0; j < matrix.m_size; j++)
			Result.m_data[i][j] = matrix.m_data[j][i];
	return Result;
}

MATRIX minorMatrix(MATRIX matrix, int col, int row)
{
	MATRIX Result;
	int rowIndex = 0;
	int colIndex = 0;
	int i, j;
	initMatrix(&Result, matrix.m_size - 1);
	for (i = 0; i < matrix.m_size; i++)
	{
		for (j = 0; j < matrix.m_size; j++)
			if (i != row && j != col)
			{
				Result.m_data[rowIndex][colIndex] = matrix.m_data[i][j];
				colIndex++;
			}
		if (i != row && j != col)
		{
			colIndex = 0;
			rowIndex++;
		}
		return Result;
	}
}

MATRIX cofactorMatrix(MATRIX matrix)
{
	MATRIX Result;
	initMatrix(&Result, matrix.m_size);
	for (int i = 0; i < matrix.m_size; i++)
		for (int j = 0; j < matrix.m_size; j++)
			Result.m_data[j][i] = determinant(minorMatrix(matrix, i, j));
	return Result;
}

MATRIX adjoint(MATRIX matrix)
{
	MATRIX Result, confactor, transposed;
	double ipow = -1;
	initMatrix(&Result, matrix.m_size);
	initMatrix(&confactor, matrix.m_size);
	initMatrix(&transposed, matrix.m_size);
	confactor = cofactorMatrix(matrix);
	transposed = transpose(confactor);
	for (int i = 0; i < matrix.m_size; i++)
		for (int j = 0; j < matrix.m_size; j++)
		{
			ipow = pow(-1, (i + j));
			Result.m_data[i][j] = ipow * transposed.m_data[i][j];
		}
	deleteMatrix(&confactor);
	deleteMatrix(&transposed);
	return Result;
}

MATRIX inverseMatrix(MATRIX matrix)
{
	MATRIX Result, temp;
	double det;
	det = determinant(matrix);
	initMatrix(&temp, matrix.m_size);
	initMatrix(&Result, matrix.m_size);
	if (matrix.m_size == 2)
	{
		temp.m_data[0][0] = matrix.m_data[1][1];
		temp.m_data[1][1] = matrix.m_data[0][0];
		temp.m_data[0][1] = -(matrix.m_data[0][1]);
		temp.m_data[1][0] = -(matrix.m_data[1][0]);
		for (int i = 0; i < matrix.m_size; i++)
			for (int j = 0; j < matrix.m_size; j++)
				Result.m_data[i][j] = (double)((double)1 / det) * temp.m_data[i][j];
		deleteMatrix(&temp);
		return Result;
	}
	temp = adjoint(matrix);
	for (int i = 0; i < matrix.m_size; i++)
		for (int j = 0; j < matrix.m_size; j++)
			Result.m_data[i][j] = (double)((double)1 / det) * temp.m_data[i][j];
	deleteMatrix(&temp);
	return Result;
}