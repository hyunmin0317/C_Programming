#include <stdio.h>
#include <math.h>
#define N 64
#define MIN -1024

void matrix_make(double(*A)[N], int n);                                     // 행렬의 값을 입력받는 함수
void matrix_print(double(*A)[N], int n, int m);                             // 행렬을 출력하는 함수
int matrix_det(double(*A)[N], int n);                                       // 행렬의 행렬식을 반환하는 함수
void matrix_cpy(double(*A)[N], double(*B)[N], int n);                       // 행렬 A의 값을 행렬 B의 값에 복사하는 함수
void change(double(*A)[N], int n, double m);                                // 고유값을 구하기 위해 행렬의 주대각선에 실수 m을 빼는 함수
void gauss(double(*A)[N], int n);                                           // 가우스-조단소거법을 통해 행렬을 삼각행렬로 변환하는 함수
void backsub(double(*A)[N], int n);                                         // 행렬의 고유벡터를 역대입법을 통해 구하는 함수 
void printout(double(*A)[N], int n);                                        // 가우스-조단소거법 풀이 과정을 출력하여 보여주는 함수

int main(void)
{
    double matrixA[N][N] = { 0, };                                          // 고유값과 고유벡터를 구할 행렬
    double matrixB[N][N] = { 0, };                                          // 처음 입력받은 행렬의 값을 저장할 행렬
    double C[N] = { 0, };                                                   // 행렬의 고유값을 저장할 배열
    int i;                                                                  // 반복변수
    int n;                                                                  // 행렬의 크기
    int count = 0;                                                          // 고유값의 개수
    int value = MIN;                                                        // 고유값(최저값 MIN으로 초기화) 

    printf("\n 행렬의 고유값과 고유벡터 계산 프로그램\n\n");
    printf(" 행렬의 크기 입력: ");
    scanf("%d", &n);                                                        // 행렬의 크기를 n으로 입력받음
    matrix_make(matrixA, n);                                                // 행렬의 값을 matrix_make 함수로 입력받음
    while (count < n)                                                       // 행렬의 고유값의 개수(count)와 행렬의 크기(n)가 같을 때까지 고유값을 검색함  
    {
        matrix_cpy(matrixA, matrixB, n);                                    // 처음 입력받은 행렬(matrixA)의 값을 행렬(matrixB)에 matrix_cpy 함수를 통해 복사하여 저장함
        change(matrixB, n, value);                                          // 고유값을 구하기 위해 change 함수를 통해 행렬(matrixB)의 주대각선에 value를 뺌
        if (matrix_det(matrixB, n) == 0)                                    // 행렬(matrixB)의 행렬식을 matrix_det 함수를 통해 구하고 행렬식이 0 일때
        {
            C[count] = value;                                               // 고유값(value)를 배열(C)에 저장함
            count++;                                                        // 고유값 개수(count)에 1을 더함
        }
        value++;                                                            // 행렬의 크기(n)와 고유값의 개수(count)가 같을 때까지 고유값에 1을 더해가며 검색함
    }

    printf("\n 입력한 행렬\n");
    matrix_print(matrixA, n, n);                                            // 입력한 행렬을 matrix_print 함수를 통해 출력함
    printf("\n 행렬의 고유값\n");
    for (i = 0; i < n; i++)                                                 // 배열(C)에 저장된 고유값을 모두 출력
        printf(" λ%d = %.lf \t", i + 1, C[i]);
    printf("\n\n 행렬의 고유벡터\n");
    for (i = 0; i < n; i++)
    {
        printf(" *********************************************\n\n");
        printf(" 고유값 λ = %.lf일때 고유벡터\n", C[i]);
        matrix_cpy(matrixA, matrixB, n);                                    // 처음 입력받은 행렬(matrixA)의 값을 행렬(matrixB)에 matrix_cpy 함수를 통해 복사하여 저장함
        change(matrixB, n, C[i]);                                           // 고유벡터를 구하기 위해 change 함수를 통해 행렬(matrixB)의 주대각선에 고유값(C[i])를 뺌
        gauss(matrixB, n);                                                  // gauss 함수를 통해 고유벡터를 구함
    }
    return 0;
}

void matrix_make(double(*A)[N], int n)                                      // 행렬의 값을 입력받는 함수
{
    int i, j;
    printf("\n 행렬의 값을 입력하세요.\n");
    for (i = 0; i < n; i++)                                                 // n*n 행렬의 모든 값을 i와 j가 0부터 n까지 변하며 A[i][j](i+1행, j+1열)를 입력받음
        for (j = 0; j < n; j++)
        {
            printf(" %d * %d 행렬의 값을 입력: ", i + 1, j + 1);
            scanf("%lf", &(*(A + i))[j]);
        }
}

void matrix_print(double(*A)[N], int n, int m)                              // 행렬을 출력하는 함수
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        printf(" |  ");
        for (int j = 0; j < m; j++)                                         // n*m 행렬의 모든 값을 출력함
        {
            if (n == m)                                                     // 입력받은 행렬을 출력할 때
                printf("%+3.lf  ", (*(A + i))[j]);
            else                                                            // 고유벡터를 출력할 때
                printf("%+.3lf ", (*(A + i))[j]);
        }
        printf(" |\n");
    }
}

int matrix_det(double(*A)[N], int n)                                        // 행렬의 행렬식을 반환하는 함수
{
    int i, j, k, y;                                                         // 반복변수와 소행렬식의 기준이 되는 행과 열
    int det = 0;                                                            // 행렬식을 저장할 변수 det
    double temp[N][N];                                                      // 소행렬식을 저장할 행렬(temp)
    if (n != 1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                y = 0;
                for (k = 0; k < n; k++)
                    if (k != i)                                             // 행렬(A)의 1행 i+1열을 기준으로 소행렬식(temp)을 만듦
                        temp[j - 1][y++] = (*A + j * N)[k];
            }
            det += pow(-1, i) * (*A + 0)[i] * matrix_det(temp, n - 1);      // 행렬식 값에 1행 i+1열의 여인수(A[0][i])를 더함 
        }
        return det;                                                         // 구한 행렬식을 반환함
    }
    else                                                                    // 행렬의 크기가 1일 때 행렬식은 행렬의 값이므로 이를 반환함 
        return *A[0];
}

void matrix_cpy(double(*A)[N], double(*B)[N], int n)                        // 행렬 A의 값을 행렬 B의 값에 복사하는 함수
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)                                             // n*n 행렬 A, B의 모든 값
            B[i][j] = A[i][j];                                              // 행렬 B의 값에 행렬 A의 값을 대입함
}

void change(double(*A)[N], int n, double m)                                 // 고유값을 구하기 위해 행렬의 주대각선에 실수 m을 빼는 함수
{
    int i;
    for (i = 0; i < n; i++)
        A[i][i] -= m;                                                       // 행렬 A의 주대각선에 실수 m을 뺌
}


void gauss(double(*A)[N], int n)                                            // 가우스-조단소거법을 통해 행렬을 삼각행렬로 변환하는 함수
{
    int i = 0, j = 0, k = 0, l = 0;
    double multi = 0, temp = 0;
    printf("\n 가우스-조단소거법 풀이 과정\n");
    while (k < n)                                                           // 기준 열(k)이 행렬의 크기(n)보다 작을때
    {
        l = k;                                                              // l에 기준열(k)을 대입함
        for (j = k + 1; j < n; j++)
        {
            if (fabs(A[j][k]) > fabs(A[l][k]))
                l = j;                                                      // 절대값 A[j][k]가 절대값 A[l][k]보다 클때 l에 j를 대입함
            for (j = k; j < n; j++)
            {
                temp = A[k][j];                                             // temp를 통해 A[k][j]와 A[l][j]의 값을 변경함
                A[k][j] = A[l][j];
                A[l][j] = temp;
            }
            if (A[k][k] != 0)
                for (j = k + 1; j < n; j++)
                {
                    multi = -1 * (A[j][k]) / A[k][k];                       // A[j][k]와 A[k][k]의 비율에 -부호를 붙여 mulit에 저장함
                    for (i = k; i < n; i++)
                        if (multi != 0)                                     // multi가 0이 아닐때
                            A[j][i] += multi * A[k][i];                     // A[j][k]의 값에 multi와 A[k][i]를 곱한 값을 뺌 
                }
        }
        k++;                                                                // 기준 열(k)에 1을 더함
    }
    printout(A, n);                                                         // printout 함수를 통해 가우스-조단소거법 풀이 과정을 출력함
    backsub(A, n);                                                          // 삼각행렬로 변환된 행렬의 고유벡터를 역대입법을 통해 구함 
}

void backsub(double(*A)[N], int n)                                          // 행렬의 고유벡터를 역대입법을 통해 구하는 함수 
{
    int i = 0, j = 0, k = 0;                                                // 반복변수(0으로 초기화)
    float sum;                                                              // 총합(sum)
    double mat[N][N] = { 0, };                                              // 고유벡터를 저장할 배열(mat)
    if (fabs(A[n - 1][n - 1]) < 0.00000001)                                 // 행렬 A의 n행 n열의 값이 0일 때(0과 같을 때로 하면 부동소수점 오류가 발생하여 0.00000001보다 작을 때로 표시함)
        mat[n - 1][0] = 1;                                                  // 고유벡터의 성분값을 1로 가정
    else
        mat[n - 1][0] = 0;                                                  // 고유벡터의 성분값이 0임
    for (i = n - 2; i > -1; i--)
    {
        sum = 0.0f;                                                         // 총합(sum)을 0으로 초기화
        for (j = n - 1; j > i; j--)
            sum += A[i][j] * mat[j][0];                                     // 행렬 A의 i-1행 j-1열(A[i][j]) 값을 총합 sum에 더함
       if (fabs(A[i][i]) < 0.00000001)                                     // 행렬 A의 n행 n열의 값이 0일 때(0과 같을 때로 하면 부동소수점 오류가 발생하여 0.00000001보다 작을 때로 표시함)
            mat[i][0] = 1;                                                  // 고유벡터의 성분값을 1로 가정
        else
            mat[i][0] = -sum / A[i][i];                                     // 총합(sum)에 -부호를 붙이고 A의 i-1행 i-1열(A[i][i]) 값을 나눠서 고유벡터를 구함
    }
    printf(" 고유값λ의 고유벡터\n");
    matrix_print(mat, n, 1);                                                // 고유값을 저장한 배열을 matrix_print 함수를 통해 출력
    printf("\n");
}

void printout(double(*A)[N], int n)                                         // 가우스-조단소거법 풀이 과정을 출력하여 보여주는 함수
{
    int i, j;                                                               // 반복변수
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %+.1lf\t", A[i][j]);                                   // 행렬(A)의 모든 값을 출력 
        printf(" x%d ", i + 1);
        printf("  %+.lf \n", 0);
    }
    printf("\n");
}