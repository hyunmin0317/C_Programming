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


int main(void)
{
	srand(time(NULL));
	double dice[6];
	double num;
	int n;
	scanf("%lf", &num);
	for (int i = 0; i < 6; i++)
	{
		dice[i] = 0;
	}
	for (int i = 0; i < num; i++)
	{
		n = randint(1, 6);
		dice[n - 1]++;
	}
	for (int i = 1; i <= 6; i++)
	{
		printf("%d는 %lf%% 나왔다\n", i, dice[i - 1]/num*100);
	}
	return 0;
}