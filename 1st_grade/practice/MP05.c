#include <stdio.h>
#include <string.h>
#define SIZE 128
#define NUMS 10

char* StrCpy(char* destination, const char* source)
{
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

/*
char* StrCpy(char* destination, const char* source)
{
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}
*/

/*
char* StrCpy(char* destination, const char* source)
{
	int i;
	for (i = 0; i< strlen(source) ; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}
*/

void* MemCpy(void* destination, const void* source, int size)
{
	char* dest = destination;
	char* sour = source;
	for (int i = 0; i < size; i++)
	{
		dest[i] = sour[i];
	}
	return destination;
}

void* MemSet(void* destination, int num, unsigned size)
{
	char* dest = destination;
	for (int i = 0; i < size; i++) 
	{
		dest[i] = num;
	}
	return destination;
}



int main(void)
{
	char s1[SIZE] = "Hello World";
	char s2[SIZE] = "adkfadslkfasfjksdjfl";
	StrCpy(s2,s1);
	printf("%s\n", s1);
	printf("%s\n", s2);

	int numbers[NUMS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int numbers2[NUMS];
	MemCpy(numbers2, numbers, NUMS * sizeof(int));
	printf("%d\n", numbers2[9]);
	MemSet(numbers2, 0, NUMS * sizeof(int));
	printf("%d\n", numbers2[9]);
	return 0;
}