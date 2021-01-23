#include <stdio.h>
#define alphabet 26

int main(void)
{
	char ch;
	char Alphabet[alphabet+1] = {0, };
	while ((ch = getchar()) != EOF)
	{
		if ('A' <= ch && ch <= 'Z')
			Alphabet[ch - 'A']++;
		else if ('a' <= ch && ch <= 'z')
			Alphabet[ch - 'a']++;
		else
			Alphabet[26]++;
	}
	for (int i = 0; i < alphabet; i++)
		if (Alphabet[i] != 0)
			printf("%c/%c count: %d\n", 'A' + i, 'a' + i, Alphabet[i]);
	printf("Others: %d\n", Alphabet[26]);
	return 0;
}