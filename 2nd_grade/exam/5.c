#include <stdio.h>

int main(void)
{
	int num;
	printf("Input Integer: ");
	scanf("%d", &num);
	for (int i = 2; i <= num; i++)
	{
		while (num % i == 0)
		{
			if (num == i)
				printf("%d\n", i);
			else
				printf("%d * ", i);
			num = num / i;
		}
	}
	return 0;
}