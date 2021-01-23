#include <stdio.h>

int main(void)
{
	int num;
	printf("양의 정수 입력: ");
	scanf("%d", &num);
	printf("%d의 약수: ", num);
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}