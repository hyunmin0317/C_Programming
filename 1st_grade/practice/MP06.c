#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

char* src = "memset(&i2, 0, sizeof(int));\n		memcpy(((char*)&i2) + 2, ((char*)&i1) + 2, sizeof(int) / 2);\n	memcpy(&d2, ((char*)&d1) + 4, sizeof(int))";	     
//char* src = "printf(\"i2 = %d, d2 = %lf\n\", i2, d2);\n	    return 0; ";
//char* src = " \ta";
//char* src = "));\n		m";

char* replaceWhiteSpaces(const char* src)
{
	int len = strlen(src);
	char* dest = (char*)malloc(sizeof(char)*(len+1));
	char* d = dest;
	char* s = src;
	while (*s != '\0')
	{
		if (*s == ' '||*s == '\t')
		{
			*d = ' ';
			d++;
			while (*s == ' ' || *s == '\t')
			{
				s++;
			}
		}
		else
		{
			*d = *s;
			s++;
			d++;
		}
		*d = '\0';
	}
	return dest;
}

int main(void)
{
	char dest[MAX];
	printf("%s\n", src);
	char* newStr = replaceWhiteSpaces(src);
	printf("%s\n", newStr);
	free(newStr);
	return 0;
}