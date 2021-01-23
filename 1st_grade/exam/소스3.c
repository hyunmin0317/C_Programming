#include <stdio.h>

int main(void)
{
	FILE* filepoint = fopen("hello.txt", "w");
	fprintf(filepoint,"%s,%d\n", "HELLO", 100);
	fclose(filepoint);
	return 0;
}