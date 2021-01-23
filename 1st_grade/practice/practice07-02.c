#include <stdio.h>
#include <string.h>
#define MAX 128

void WriteBackward(char* s, int size)
{
	if (size == 1)
	{
		printf("%c", s[size - 1]);
	}
	else
	{
		printf("%c", s[size - 1]);
		WriteBackward(s, size - 1);
	}
}

int main(void)
{
	char S[MAX];
	gets(S);
	WriteBackward(S, strlen(S));
	return 0;
}