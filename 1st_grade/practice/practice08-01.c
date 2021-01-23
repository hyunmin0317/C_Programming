#include <stdio.h>
#define MAX 512

void enter(char* s)
{
	while (*s != '\0')
	{
		if (*s==' ' || *s == '\t' || *s == '\n')
		{
			if (*(s - 1) != ' ' && *(s - 1) != '\t' && *(s - 1) != '\n')
			{
				printf("\n");
			}
		}
		else
		{
			printf("%c", *s);
		}
		s++;
	}
}

int main(void)
{
	char S[MAX];
	gets(S, MAX);
	enter(S);
	return 0;
}