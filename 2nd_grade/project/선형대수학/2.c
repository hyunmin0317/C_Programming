#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 64

void make_matrix(double(*A)[MAX], int n);
void print_matrix(double(*A)[MAX], int n);
int det_matrix(double(*A)[MAX], int n);
void gauss(double(*a)[MAX], int n);
void backsub(double(*a)[MAX], int n);
void printout(double(*a)[MAX], int n);
void change(double(*a)[MAX], int n, double m);
void matrix_cpy(double(*a)[MAX], double(*b)[MAX], int n);

int main(void)
{
    double matrixA[MAX][MAX] = { 0, };
    double matrixB[MAX][MAX] = { 0, };
    double C[MAX] = { 0, };
    int n;
    int i, j, e;
    int count = 0;
    int ind = -256;

    printf("\n 고유값과 고유벡터 계산 프로그램\n\n");
    printf(" 행렬의 크기 입력: ");
    scanf("%d", &n);
    make_matrix(matrixA, n);
    while (count < 3)
    {
        matrix_cpy(matrixA, matrixB, n);
        change(matrixB, n, ind);
        if (det_matrix(matrixB, n) == 0)
        {
            C[count] += ind;
            count++;
        }
        ind++;
    }

    printf("\n 입력한 행렬의 고유값\n");
    for (i = 0; i < n; i++)
        printf(" x%d = %.2lf \t", i + 1, C[i]);
    printf("\n\n 행렬의 고유벡터\n");
    for (e = 0; e < n; e++)
    {
        matrix_cpy(matrixA, matrixB, n);
        change(matrixB, n, C[e]);
        gauss(matrixB, n);
    }
    return 0;
}

void make_matrix(double(*A)[MAX], int n)
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

void print_matrix(double(*A)[MAX], int n)
{
    int i, j;
    printf("\n 입력한 행렬\n");
    for (int i = 0; i < n; i++)
    {
        printf(" |\t");
        for (int j = 0; j < n; j++)
            printf("%.2lf\t", (*(A + i))[j]);
        printf(" |\n");
    }
}

int det_matrix(double(*A)[MAX], int n)
{
    int i, j, k, y;
    int det = 0;
    double temp[MAX][MAX];
    if (n != 1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                y = 0;
                for (k = 0; k < n; k++)
                    if (k != i)
                        temp[j - 1][y++] = (*A + j * MAX)[k];
            }
            det += pow(-1, i) * (*A + 0)[i] * det_matrix(temp, n - 1);
        }
        return det;
    }
    else
        return *A[0];
}

// 연산 결과를 출력
void printout(double(*a)[MAX], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %+.1f\t", a[i][j]);
        }
        printf(" x%d ", i + 1);
        printf(" %+.1f \n", 0.0);
    }
    printf("\n");
}

void gauss(double(*a)[MAX], int n)
{
    int i = 0, j = 0, k = 0, l = 0;
    double multi = 0, temp = 0;

    printf("\n 가우스-조단소거법 풀이 과정: \n ");
    printf("***********************************************\n\n");

    while (k < n)
    {
        l = k;
        for (j = k + 1; j < n; j++)
        {
            if (fabs(a[j][k]) > fabs(a[l][k]))
            {
                l = j;
            }
            for (j = k; j < n; j++)
            {
                temp = a[k][j];
                a[k][j] = a[l][j];
                a[l][j] = temp;
            }
            if (a[k][k] != 0)
            {
                for (j = k + 1; j < n; j++)
                {
                    multi = -1 * (a[j][k]) / a[k][k];
                    for (i = k; i < n; i++)
                        if (multi != 0)
                            a[j][i] = a[j][i] + multi * a[k][i];
                }
            }
        }
        k = k + 1;
    }
    printout(a, n);
    printf(" ********************************************* \n\n");
    backsub(a, n);
}

//역대입법 계산 함수
void backsub(double(*a)[MAX], int n)
{
    int i = 0, j = 0, k = 0;
    float sum;
    double mat[MAX] = { 0, };
    if (fabs(a[n - 1][n - 1]) < 0.1 || fabs(a[n - 1][n - 1]) < 1 / 1000000)
    {
        mat[n - 1] = 1;
    }
    else
    {
        mat[n - 1] = 0;
    }
    for (i = n - 2; i > -1; i--)
    {
        sum = 0.0f;
        for (j = n - 1; j > i; j--)
        {
            sum = sum + a[i][j] * mat[j];
        }
        if (fabs(a[i][i]) < 0.1 || fabs(a[i][i]) < 1 / 1000000)
        {
            mat[i] += 1;
        }
        else
        {
            mat[i] = -sum / a[i][i];
        }
    }

    printf(" 입력한 선형방정식의 해답\n");
    for (k = 0; k < n; k++)
    {
        printf(" x%d = ", k + 1);
        printf("%lf \t", mat[k]);
    }
    printf("\n\n");

}

void change(double(*a)[MAX], int n, double m)
{
    int i;
    for (i = 0; i < n; i++)
        a[i][i] -= m;
}

void matrix_cpy(double(*a)[MAX], double(*b)[MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            b[i][j] = a[i][j];
}

