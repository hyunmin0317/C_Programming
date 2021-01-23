#include<stdio.h>

int main(void)
{
	int n1, n2, n3;
	int a, b, c;
	int repeat = 1;

	while (repeat == 1)
	{
		printf("\n삼각형 유형 확인 프로그램\n");
		printf("양의 정수1: ");
		scanf("%d", &n1);
		printf("양의 정수2: ");
		scanf("%d", &n2);
		printf("양의 정수3: ");
		scanf("%d", &n3);

		if (n1 > n2)
		{
			if (n1 > n3)
			{
				c = n1;
				if (n2 > n3)
				{
					b = n2;
					a = n3;
				}
				else
				{
					b = n3;
					a = n2;
				}
			}
			else
			{
				c = n3;
				b = n1;
				a = n2;
			}
		}
		else
		{
			if (n2 > n3)
			{
				c = n2;
				if (n1 > n3)
				{
					b = n1;
					a = n3;
				}
				else
				{
					b = n3;
					a = n1;
				}
			}
			else
			{
				c = n3;
				b = n2;
				a = n1;
			}
		}

		printf("%d, %d, %d 로 이루어진 삼각형은 ", n1, n2, n3);
		if (a + b > c)
		{
			if (a * a + b * b == c * c)
				printf("직각삼각형이다.\n");
			else if (a == b && b == c)
				printf("정삼각형이다.\n");
			else if (c == a || c == b)
				printf("이등변삼각형이다.\n");
			else
				printf("일반삼각형이다.\n");
		}
		else
			printf("존재하지 않는다.\n");

		printf("1 입력시 다시 시작 : ");
		scanf("%d", &repeat);
	}
	return 0;
}