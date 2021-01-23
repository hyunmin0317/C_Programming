#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";
	int count[5];
	char c[5];
	char c1;
	char c2;
	char c3;
	char c4;
	char c5;
	char a;
	int count = 0;

	int len = strlen(str);

	for (int i = 0; i < 5; i++)
	{
		counts[i] = 0;
	}

	printf("영단어 5개를 c1,c2,c3,c4,c5꼴로 입력하시오.", );
	scanf("%d,%d,%d,%d,%d", &c1, &c2, &c3, &c4, &c5);
	c[0] = c1;
	c[1] = c2;
	c[2] = c3;
	c[3] = c4;
	c[4] = c5;

	for (int i = 0; i < 5; i++)
	{
		count = 0;
		a = c[i];
		for (int i = 0; i < len; i++)
		{
			if (a==str[i])
			{
				count++;
			}
			counts[i] = count;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%c: %d\n", c[i], counts[i]);
	}
	
	return 0;
}