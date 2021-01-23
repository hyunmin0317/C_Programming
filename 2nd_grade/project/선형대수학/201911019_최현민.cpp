#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void input_equation(double(*A)[N], int n);								// 선형방정식의 수식을 입력받는 함수
void input_sum(double* A, int n);										// 선형방정식의 결과값을 입력받는 함수
void print_equation(double(*A)[N], double C[N], int n);					// 선형방정식의 결과를 출력하는 함수
double det(double(*A)[N], int n);										// 행렬식을 구하는 함수
void crammer(double(*A)[N], double C[N], int n, int c);					// 크래머의 규칙을 통해 선형방정식의 해를 구하는 함수

int main(void)
{
	int i, j;															// 반복문 사용을 위한 변수 선언
	int n;																// 선형방정식의 최대 차수 선언
	double A[N][N] = {0, };												// 선형방정식의 계수를 담을 2차원 배열을 생성 후 0으로 초기화
	double C[N] = { 0, };												// 선형방정식의 결과값을 담을 1차원 배열을 생성 후 0으로 초기화
	printf(" 크래머의 규칙을 이용한 선형방정식 계산 프로그램\n\n");
	printf(" 선형방정식의 최대 차수 입력: ");
	scanf("%d", &n);													// 선형방정식의 최대 차수 입력

	input_equation(A, n);												// 2차원 배열 A에 선형방정식의 수식을 입력받는 함수(input_equation)를 통해 계수 입력
	input_sum(C, n);													// 1차원 배열 C에 선형방정식의 결과값을 입력받는 함수(input_sum)를 통해 결과값 입력 
	print_equation(A, C, n);											// 선형방정식의 결과를 출력하는 함수(print_equation)이 방정식의 수식과 결과값인 A와 C를 받아 결과 출력

	printf("\n 입력한 선형방정식의 행렬식 값\n");
	printf(" Det(A) = %.f\n\n", det(A, n));								// 행렬식을 구하는 함수(det)를 통해 2차원 배열 A의 행렬식 구함
	printf(" 입력한 선형방정식의 해답\n");
	for (i = 1; i < n + 1; i++)
		crammer(A, C, n, i);											// 선형방정식의 해를 구하는 함수(crammer)를 통해 방정식의 해 출력
	printf("\n\n");
}

void input_equation(double(*A)[N], int n)
{
	int i, j;
	printf("\n 선형방정식의 수식을 입력하세요. \n");					// 선형방정식의 수식을 입력
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf(" %d 번째 선형방정식 x%d 의 값: ", i + 1, j + 1);
			scanf("%lf", &A[i][j]);										// 주어진 2차원 배열 A의 A[i][j]에 i+1 번째 선형방정식 x(j+1)의 값(계수)을 입력 
		}
}

void input_sum(double* A, int n)
{
	int i;
	printf("\n 선형방정식의 결과 값을 입력하세요. \n");					// 선형방정식의 결과값을 입력
	for (i = 0; i < n; i++)
	{
		printf(" %d 번째 선형방정식의 결과 값: ", i + 1);
		scanf("%lf", &A[i]);											// 주어진 1차원 배열 A의 A[i]에 i+1 번째 선형방정식의 결과값을 입력
	}
}

void print_equation(double(*A)[N], double B[N], int n)
{
	int i, j;
	printf("\n 입력한 선형방정식의 행렬 = \n\n");						// 입력한 선형방정식의 행렬 출력
	for (i = 0; i < n; i++)
	{
		printf(" |\t");
		for (j = 0; j < n; j++)
			printf(" %.f x%d\t", A[i][j], j + 1);						// 선형방정식의 수식을 담은 2차원 배열 A를 출력
		printf("=\t");
		printf("%.f\t", B[i]);											// 선형방정식의 결과값을 담은 1차원 배열 B를 출력
		printf("|\n");
	}
}

double det(double(*A)[N], int n)
{
	int i, j, k, y;														// 반복문 사용을 위한 변수 선언
	double det_a = 0;													// 행렬식 저장 변수
	double temp[N][N];													// 기준이 되는 수의 소행렬식을 저장할 임시 배열

	if (n != 1)															// n이 1이 아닐 때 여인수를 통해 행렬식을 구함
	{
		for (i = 0; i < n; i++)											// A행렬의 1열부터 n열까지 이동(i는 0부터 n-1), A행렬의 i열을 기준으로 소행렬식을 구함
		{
			for (j = 1; j < n; j++)										// A행렬의 2행부터 n행까지 이동(i는 1부터 n-1), A행렬의 1행을 기준으로 소행렬식을 구함 
			{
				y = 0;													// 소행렬식 행렬의 열
				for (k = 0; k < n; k++)									// k는 기준이 되는 수가 해당하는 i+1열을 제외한 A의 열
					if (k != i)
						temp[j - 1][y++] = (*A + j * N)[k];				// temp는 기준이 되는 수 A[0][i]의 소행렬식, 이때 (*A + j * N)[k] 는 A행렬의 j+1행 k+1을 가르킴  
			}																
			det_a = det_a + *(A[0] + i) * (pow(-1, i)) * det(temp, n - 1);	// 소행렬식을 이용해 행렬식을 구함 
		}
		return det_a;												    // 행렬식 반환 
	}
	else															    // n이 1일 때 값 그대로 행렬식이므로 그대로 반환
		return *A[0];
}

void crammer(double(*A)[N], double C[N], int n, int c)
{
	int i, j ;															// 반복문 사용을 위한 변수 선언
	double temp[N][N] = {0, };											// 2차원 배열 temp는 A행렬에 기준 열을 대체한 임시 행렬
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			temp[i][j] = A[i][j];										// 2차원 배열 temp에 A행렬 입력
	for (i = 0; i < n; i++)	
		temp[i][c-1] = C[i];											// A행렬인 temp에 c열을 결과값인 C행렬로 대체
	printf(" x%d = %.f\t", c, det(temp, n) / det(A, n));				// 선형방정식의 해를 출력
}