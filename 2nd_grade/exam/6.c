#include <stdio.h>
#define alphabet 26

int main(void)
{
	char A = 'A';
	char a = 'a';
	for (int i = 0; i < alphabet; i++)
	{
		printf("%c%c ", A + i, a + i);
		if ((i + 1) % 6 == 0)
			printf("\n");
	}
	return 0;
}