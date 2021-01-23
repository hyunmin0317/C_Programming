#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Alphabets 26
#define MAX 256

int* countAlphabets2(const char* str)
{
	char C = 'A';
	int len = strlen(str);
	int* counts = (int*)malloc(sizeof(int)*Alphabets);
	for (int i = 0; i < Alphabets; i++)
	{
		counts[i] = 0;
	}
	for (int i = 0; i < Alphabets; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str[j] == C + i || str[j] == (C + 32) + i)
			{
				counts[i]++;
			}
		}
	}
	return counts;
}

int main(void)
{
	char S[MAX];
	char c = 'a';
	int* alphabet;
	gets(S, MAX);
	alphabet = countAlphabets2(S);
	for (int i = 0; i < Alphabets; i++)
	{
		printf("%c´Â %d°³\n", c + i, *(alphabet+i));
	}
	free(alphabet);
	return 0;
}