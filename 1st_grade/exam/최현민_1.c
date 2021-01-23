#include <stdio.h>

int main(void)
{
	int a = 1;
	while (a*a*a*a <= 10000)
	{
		a++;
	}
	printf("a의 4승이 10000을 넘는 가장작은 정수값은 %d 이다.\n", a*a*a*a);
	return 0;
}