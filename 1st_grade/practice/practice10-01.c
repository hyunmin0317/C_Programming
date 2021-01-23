#include <stdio.h>
#include <string.h>
#define MAX 256

int main(void)
{
	char A[MAX];
	FILE* fp = fopen("data.txt", "wt");
	gets(A, MAX);
	while (strcmp(A, "quit") != 0)
	{
		fprintf(fp, "%s\n", A);
		gets(A, MAX);
	}
	fclose(fp);
	return 0;
}