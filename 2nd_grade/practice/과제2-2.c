#include <stdio.h>

int main(void)
{
	int num;
	int number;
	printf("숫자 입력: ");
	scanf("%d",&num);
	while (num!=0)
	{
		number = num % 10;
		num = num / 10;
		printf("%d",number);
	}
	return 0;
}