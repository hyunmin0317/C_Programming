#include <stdio.h>
#include <string.h>
#define MAX 128

void WriteBackward(char* s, int size)
{
	while (size > 0)
	{
		printf("%c", s[size - 1]);
		size--;
	}
}

int main(void)
{
	char S[MAX];
	gets(S);
	WriteBackward(S, strlen(S));
	return 0;
}