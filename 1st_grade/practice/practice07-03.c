#include <stdio.h>
#define MAX 128

int counts(char* s, char c)
{
	int count = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			count++;
		}
		s++;
	}
	return count;
}


int main(void) 
{
	char S[MAX];
	char C;
	gets(S);
	scanf("%c", &C);
	int count = counts(S, C);
	puts(S);
	printf("%s에 %c는 %d개 있다.", S, C, count);
	return 0;
}
