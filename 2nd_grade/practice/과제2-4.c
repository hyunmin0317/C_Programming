#include <stdio.h>

int main(void)
{
	int n;
	int k;
	int num;

	printf("n: ");
	scanf("%d", &n);
	printf("k: ");
	scanf("%d", &k);

	num = n;
	while (num%k!=0)
	{
		num--;
	}

	printf("%d을 넘지않으면서 가장 가까운 %d의 배수는 %d이다.", n, k, num);
	return 0;
}