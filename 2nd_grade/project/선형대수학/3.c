#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 64
#define MIN -256

void matrix_make(double(*A)[N], int n);
void matrix_print(double(*A)[N], int n, int m);
int matrix_det(double(*A)[N], int n);
void matrix_cpy(double(*A)[N], double(*B)[N], int n);
void change(double(*A)[N], int n, double m);
void printout(double(*A)[N], int n);
void backsub(double(*A)[N], int n);
void gauss(double(*A)[N], int n);

int main(void)
{
    double matrixA[N][N] = { 0, };
    double matrixB[N][N] = { 0, };
    double C[N] = { 0, };
    int n;
    int i;
    int count = 0;
    int value = MIN;

    printf("\n 행렬의 고유값과 고유벡터 계산 프로그램\n\n");
    printf(" 행렬의 크기 입력: ");
    scanf("%d", &n);
    matrix_make(matrixA, n);
    while (count < n)
    {
        matrix_cpy(matrixA, matrixB, n);
        change(matrixB, n, value);
        if (matrix_det(matrixB, n) == 0)
        {
            C[count] += value;
            count++;
        }
        value++;
    }

    printf("\n 입력한 행렬\n");
    matrix_print(matrixA, n, n);
    printf("\n 행렬의 고유값\n");
    for (i = 0; i < n; i++)
        printf(" λ%d = %.lf \t", i + 1, C[i]);
    printf("\n\n 행렬의 고유벡터\n");
    for (i = 0; i < n; i++)
    {
        printf(" *********************************************\n\n");
        printf(" 고유값 λ = %.lf일때 고유벡터\n", C[i]);
        matrix_cpy(matrixA, matrixB, n);
        change(matrixB, n, C[i]);
        gauss(matrixB, n);
    }
    return 0;
}

void matrix_make(double(*A)[N], int n)
{
    int i, j;
    printf("\n 행렬의 값을 입력하세요.\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf(" %d * %d 행렬의 값을 입력: ", i + 1, j + 1);
            scanf("%lf", &(*(A + i))[j]);
        }
}

void matrix_print(double(*A)[N], int n, int m)
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        printf(" |  ");
        for (int j = 0; j < m; j++)
        {
            if (n == m)
                printf("%+3.lf  ", (*(A + i))[j]);
            else
                printf("%+.3lf ", (*(A + i))[j]);
        }
        printf(" |\n");
    }
}

int matrix_det(double(*A)[N], int n)
{
    int i, j, k, y;
    int det = 0;
    double temp[N][N];
    if (n != 1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                y = 0;
                for (k = 0; k < n; k++)
                    if (k != i)
                        temp[j - 1][y++] = (*A + j * N)[k];
            }
            det += pow(-1, i) * (*A + 0)[i] * matrix_det(temp, n - 1);
        }
        return det;
    }
    else
        return *A[0];
}

void matrix_cpy(double(*A)[N], double(*B)[N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            B[i][j] = A[i][j];
}

void change(double(*A)[N], int n, double m)
{
    int i;
    for (i = 0; i < n; i++)
        A[i][i] -= m;
}

// 연산 결과를 출력
void printout(double(*A)[N], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %+.1lf\t", A[i][j]);
        printf(" x%d ", i + 1);
        printf(" %+.1lf \n", 0.0);
    }
    printf("\n");
}

//역대입법 계산 함수
void backsub(double(*A)[N], int n)
{
    int i = 0, j = 0, k = 0;
    float sum;
    double mat[N][N] = { 0, };
    if (fabs(A[n - 1][n - 1]) < 0.1)
        mat[n - 1][0] = 1;
    else
        mat[n - 1][0] = 0;
    for (i = n - 2; i > -1; i--)
    {
        sum = 0.0f;
        for (j = n - 1; j > i; j--)
            sum = sum + A[i][j] * mat[j][0];
        if (fabs(A[i][i]) < 0.1)
            mat[i][0] = 1;
        else
            mat[i][0] = -sum / A[i][i];
    }
    printf(" 고유값λ의 고유벡터\n");
    matrix_print(mat, n, 1);
    printf("\n");
}

void gauss(double(*A)[N], int n)
{
    int i = 0, j = 0, k = 0, l = 0;
    double multi = 0, temp = 0;
    printf("\n 가우스-조단소거법 풀이 과정\n");
    while (k < n)
    {
        l = k;
        for (j = k + 1; j < n; j++)
        {
            if (fabs(A[j][k]) > fabs(A[l][k]))
                l = j;
            for (j = k; j < n; j++)
            {
                temp = A[k][j];
                A[k][j] = A[l][j];
                A[l][j] = temp;
            }
            if (A[k][k] != 0)
                for (j = k + 1; j < n; j++)
                {
                    multi = -1 * (A[j][k]) / A[k][k];
                    for (i = k; i < n; i++)
                        if (multi != 0)
                            A[j][i] = A[j][i] + multi * A[k][i];
                }
        }
        k = k + 1;
    }
    printout(A, n);
    backsub(A, n);
}