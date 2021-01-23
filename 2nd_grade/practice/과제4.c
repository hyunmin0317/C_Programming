#include <stdio.h>

int integer_sum(int a, int b);
int b_square(int a, int b);
int k_square(int a, int b);

int main(void)
{
	int num1, num2;
	printf("정수1 입력: ");
	scanf("%d",&num1);
	printf("정수2 입력: ");
	scanf("%d", &num2);
	printf("1) %d, %d를 포함하여 그 사이 정수들의 합은 %d이다.\n", num1, num2, integer_sum(num1, num2));
	printf("2) %d의 %d승은 %d이다.\n", num1, num2, b_square(num1,num2));
	printf("3) %d의 k승 <= %d를 만족하는 정수중 가장 큰 값인 k는 %d이다.\n", num1, num2, k_square(num1,num2));
	return 0;
}

int integer_sum(int a, int b)
{
	int sum = 0;
	while (a<=b)
	{
		sum += a;
		a++;
	}
	return sum;
}

int b_square(int a, int b)
{
	int sum = 1;
	for (int i = 0; i < b; i++)
	{
		sum *= a;
	}
	return sum;
}

int k_square(int a, int b)
{
	int sum = 1;
	int k = 0;
	while (1)
	{
		sum *= a;
		if (sum > b)
			break;
		k++;
	}
	return k;
}