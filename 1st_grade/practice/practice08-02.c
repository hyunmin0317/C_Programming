#include <stdio.h>
#include <string.h>
#define Alphabets 26
#define MAX 256

void countAlphabets(const char* str, int* counts)
{
	char C = 'A';
	int len = strlen(str);
	for (int i = 0; i < Alphabets; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str[j]==C+i || str[j]==(C+32)+i)
			{
				counts[i]++;
			}
		}
	}
}

int main(void)
{
	char S[MAX];
	char c = 'a';
	int Alphabet[Alphabets];
	for (int i = 0; i < Alphabets; i++)
	{
		Alphabet[i] = 0;
	}
	gets(S, MAX);
	countAlphabets(S, Alphabet);
	for (int i = 0; i < Alphabets; i++)
	{
		printf("%c´Â %d°³\n", c + i, Alphabet[i]);
	}
	return 0;
}