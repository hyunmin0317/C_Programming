#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

char* strDup(const char* src)
{
	int len = strlen(src);
	char* str = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++)
	{
		str[i] = src[i];
	}
	str[len] = '\0';
	return str;
}

char* loweString(char* src)
{
	int len = strlen(src);
	for (int i = 0; i < len; i+=2)
	{
		if (65 <= src[i] && src[i] <= 90)
		{
			src[i] = src[i] + 32;
		}
	}
	return src;
}

int main(void)
{
	char A[MAX];
	gets(A, MAX);
	printf("%s\n", A);
	printf("%s\n", loweString(strDup(A)));
	return 0;
}
