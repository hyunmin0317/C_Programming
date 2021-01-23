#include <stdio.h>

int main(void)
{
	int num;
	int divisor = 0;
	printf("양의 정수 입력: ");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
		{
			divisor++;
		}
	}
	if (divisor == 2)
	{
		printf("%d는 소수이다.\n", num);
	}
	else
	{
		printf("%d는 소수가 아니다.\n", num);
	}
	return 0;
}