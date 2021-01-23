#include <stdio.h>

int main(void)
{
	int num;
	int sum = 0;
	printf("정수 입력: ");
	scanf("%d", &num);
	while (num!=0)
	{
		sum += num % 10;
		num = num / 10;
	}
	printf("각 자릿수의 합은 %d이다.\n", sum);
	return 0;
}