#include <stdio.h>
#include <string.h>

#define W 1000000
#define A 26

int Alphabet[A] = { 0, };
char Word[W];

int Max_Alphabet()
{
	int i, w;
	int max = 0;
	int m = 0;
	for (i = 0; i < strlen(Word); i++)
	{
		if (Word[i] >= 97 && Word[i] <= 122)
			Alphabet[Word[i] - 97]++;
		else if (Word[i] >= 65 && Word[i] <= 90)
			Alphabet[Word[i] - 65]++;
	}
	for (i = 1; i < A; i++)
	{
		if (Alphabet[i] > Alphabet[max])
		{
			max = i;
			m = 0;
		}
		else if (Alphabet[i] == Alphabet[max])
			m = 1;
	}
	if (m)
		return -2;
	else
		return max;
}

int main(void)
{
	scanf("%s", Word);
	printf("%c", Max_Alphabet() + 65);
	return 0;
}