#include <stdio.h>
#include <math.h>

#define MAX 5	//행과 열의 최대값

typedef struct	//행렬 구조체 선언
{
	double a[MAX][MAX];
}matrix;

typedef struct	//해의 배열 구조체 선언 
{
	double c[MAX];
}column;

typedef enum	//True, False 구조체 선언
{
	E_FALSE, E_TRUE
}E_BOOL;

int det(matrix a, int n);	//행렬식 계산함수
void printout(matrix a, column c, int n);	//결과 출력함수
void gauss(matrix a, column c, int n);	//가우스 소거법 계산함수
void backsub(matrix a, column c, int n);	//역대입법 계산함수

int main(void)
{
	int i, j, k, l;	//반복변수 선언
	int n;	//행렬 행과 열의 크기
	int m = 0;	//고유값의 개수
	int eigenvalue = -256;	//고유값
	matrix a, b;	//고유값을 구할 행렬
	column c, value;	//해와 고유값의 배열

	printf(" 가우스 조단 소거법을 이용한 고유값과 고유벡터 계산 프로그램\n\n");
	printf(" 행과 열의 크기를 입력: ");	//행과 열의 크기를 n에 입력						
	scanf("%d", &n);
	printf("\n 행렬의 값을 입력하세요.\n");	//행렬의 값 입력								
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf(" %d * %d 행렬의 값: ", i + 1, j + 1);
			scanf("%lf", &a.a[i][j]);
		}
	for (i = 0; i < n; i++)	//해를 배열에 입력
		c.c[i] = 0;

	while (m < n)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				b.a[i][j] = a.a[i][j];	//행렬 a의 값을 행렬 b의 값에 대입
		for (i = 0; i < n; i++)	//행렬 b의 주대각선에 고유값 변수 eigenvalue를 뺌
			b.a[i][i] -= eigenvalue;
		if (det(b, n) == 0)	//행렬 b의 행렬식이 0일 때 고유값 배열 value에 해당 값을 저장 
		{
			value.c[m] = eigenvalue;
			m++;
		}
		eigenvalue++;
	}
	
	printf("\n 행렬의 고유값\n");
	for (i = 0; i < n; i++)	//고유값 배열 value에 저장된 고유값을 모두 출력
		printf(" λ%d = %.lf\t", i + 1, value.c[i]);
	
	printf("\n\n 행렬의 고유벡터\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				b.a[j][k] = a.a[j][k];	//행렬 a의 값을 행렬 b의 값에 대입
		for (l = 0; l < n; l++)	//행렬 b의 주대각선에 고유값 value.c[i]을 뺌
			b.a[l][l] -= value.c[i];
		printf(" λ%d = %.lf 일때 고유벡터\n", i + 1, value.c[i]);
		gauss(b, c, n);	//해당 고유값의 고유벡터를 gauss 함수를 통해 구함
	}
	return 0;
}

int det(matrix a, int n)	//행렬식 계산함수
{
	int i, j, k, y;
	int sum = 0;
	matrix temp;	//소행렬식을 저장할 행렬
	if (n != 1)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				y = 0;
				for (k = 0; k < n; k++)
					if (k != i)
						temp.a[j - 1][y++] = a.a[j][k];	//1행 i+1열을 기준으로 소행렬식을 만듦
			}
			sum += pow(-1, i) * a.a[0][i] * det(temp, n - 1);	//총합 sum에 여인수를 더함
		}
		return sum;
	}
	else
		return a.a[0][0];
}

void printout(matrix a, column c, int n)	//결과 출력함수
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %+.lf\t", a.a[i][j]);	//가우스-조단 소거법 풀이과정을 출력
		printf(" x%d ", i + 1);
		printf(" %+.lf \n", c.c[i]);
	}
	printf("\n");
}

void gauss(matrix a, column c, int n)	//가우스 소거법 계산함수
{
	E_BOOL error;
	int i, j, k, l;
	double multi = 0, temp = 0;
	printf("\n 가우스 조단소거법 풀이 과정 \n");

	error = E_FALSE;
	k = 0;

	while (k < n && error != E_TRUE)	//가우스-조단 소거법을 통해 행렬을 삼각행렬로 변환
	{
		l = k;
		for (j = k + 1; j < n; j++)
		{
			if (fabs(a.a[j][k]) > fabs(a.a[l][k]))
				l = j;
			for (j = k; j < n; j++)	//a.a[k][j]와 a.a[l][j]의 값을 바꿈
			{
				temp = a.a[k][j];
				a.a[k][j] = a.a[l][j];
				a.a[l][j] = temp;
			}
			temp = c.c[k];	//c.c[k]와 c.c[l]의 값을 바꿈
			c.c[k] = c.c[l];
			c.c[l] = temp;
			if (a.a[k][k] != 0)
			{
				for (j = k + 1; j < n; j++)
				{
					multi = -1 * a.a[j][k] / a.a[k][k];	//a.a[j][k]와 a.a[k][k]의 비를 통해 a.a[j][i]를 소거
					for (i = k; i < n; i++)
						if (multi != 0)
							a.a[j][i] += multi * a.a[k][i];
					c.c[j] += multi * c.c[k];
				}
				printout(a, c, n);
			}
			else
				error = E_TRUE;
		}
		k++;
	}
	if (error == E_TRUE)
		printf(" 조건에 오류가 있음");
	printout(a, c, n);
	backsub(a, c, n);
}

void backsub(matrix a, column c, int n)	//역대입법 계산함수			
{
	int i, j, k;
	float sum;
	column mat = { 0. };
	if (fabs(a.a[n - 1][n - 1]) < 0.01)	//a.a[n-1][n-1]은 0일 때(부동소수점 오류 방지) mat.c[n-1]에 1을 대입
		mat.c[n - 1] = 1;
	else
		mat.c[n - 1] = c.c[n - 1] / (a.a[n - 1][n - 1]); //a.a[n-1][n-1]은 0이 아닐 때 값을 구함
	for (i = n - 2; i > -1; i--)
	{
		sum = 0.0f;
		for (j = n - 1; j > i; j--)
			sum += a.a[i][j] * mat.c[j];	//mat.c[i]를 구하기 위해 전까지 총합을 더함
		if (fabs(a.a[i][i]) < 0.01)	//a.a[i][i]은 0일 때(부동소수점 오류 방지) mat.c[i]에 1을 대입
			mat.c[i] = 1;
		else
			mat.c[i] = (c.c[i] - sum) / a.a[i][i];	//a.a[i][i]은 0이 아닐 때 값을 구함
	}
	for (k = 0; k < n; k++)
	{
		printf(" x%d = ", k + 1);
		printf("%.4lf \t", mat.c[k]);
	}
	printf("\n\n\n");
}