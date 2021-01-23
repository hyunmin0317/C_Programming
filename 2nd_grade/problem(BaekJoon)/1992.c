#include <stdio.h>
#define N 64

int S[N][N];

void Print(int x, int y, int n)
{
    int i, j;
    int num = S[x][y];
    for (i = x; i < x + n; i++)
        for (j = y; j < y + n; j++)
            if (num != S[i][j])
                num = -1;
    if (num == -1)
    {
        printf("(");
        Print(x, y, n / 2);
        Print(x, y + n / 2, n / 2);
        Print(x + n / 2, y, n / 2);
        Print(x + n / 2, y + n / 2, n / 2);
        printf(")");
    }
    else if (num == 0)
        printf("%d", 0);
    else
        printf("%d", 1);
}

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%1d", &S[i][j]);
    Print(0, 0, n);
    return 0;
}