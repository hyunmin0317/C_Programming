#include <stdio.h>

int main(void)
{
	int n;
	int k;
	int sum = 1;

	printf("n: ");
	scanf("%d", &n);
	printf("k: ");
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		sum *= n;
	}

	printf("%dÀÇ %d½ÂÀº %dÀÌ´Ù.", n, k, sum);
	return 0;
}