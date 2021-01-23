#include <stdio.h>
#define MAX 100
#define INF 1000000000

int d[MAX][MAX] = { 0, };
int n, m;

void Floyd()
{
	int k, s, e;
	for (k = 0; k < n; k++)
		for (s = 0; s < n; s++)
			for (e = 0; e < n; e++)
				if (d[s][e] > d[s][k] + d[k][e])
					d[s][e] = d[s][k] + d[k][e];
}

void Print()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (d[i][j] == INF)
				d[i][j] = 0;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i, j;
	int x, y, c;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j)
				d[i][j] = INF;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		if (d[x - 1][y - 1] > c)
			d[x - 1][y - 1] = c;
	}
	Floyd();
	Print();
	return 0;
}