#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int randint(int min, int max)
{
	int n = floor(rand() / (float)RAND_MAX
		* (max - min + 1) + min);
	if (n > max) return max;
	if (n < min) return min;
	return n;
}

int countNum(int arr, int num, int n)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == n)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	int number[100];
	for (int i = 0; i < 100; i++)
	{
		number[i] = randint(5, 10);
	}
	printf("%d", countNum(number, 100, 7));
	return 0;
}