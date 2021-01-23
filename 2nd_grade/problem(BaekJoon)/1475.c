#include <stdio.h>

int main(void)
{
	int num;
	int N[7];
	int set[9] = { 0, };
	int i = 0, j;
	int max = 0;
	scanf("%d", &num);
	if (!num)
		set[num]++;
	while (num)
	{
		N[i++] = num % 10;
		num /= 10;
	}
	for (j = 0; j < i; j++)
	{
		if (N[j] == 9)
			set[6]++;
		else
			set[N[j]]++;
	}
	if (set[6] % 2)
		set[6]++;
	set[6] /= 2;
	for (i = 1; i < 9; i++)
		if (set[i] > set[max])
			max = i;
	printf("%d", set[max]);
	return 0;
}