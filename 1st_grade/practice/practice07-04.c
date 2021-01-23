#include <stdio.h> 
#include <ctype.h> 
#define MAX 256 

char* Toupper(char* c,char a)
{
	char* copyc = c;
	while (*copyc != '\0')
	{
		if (*copyc == a)
		{
			*copyc = toupper(*copyc);
		}
		copyc++;
	}
	return c;
}

int main(void)
{
	char A[MAX] = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";
	char a;
	scanf("%c", &a);
	Toupper(A,a);
	printf("%s", A);
	return 0;
}