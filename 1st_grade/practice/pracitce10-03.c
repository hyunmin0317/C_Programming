#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void)
{
	FILE* fp = fopen("data.txt", "rt");
	char A[MAX];
	char B[MAX];
	char* p = fgets(A, MAX, fp);
	while (p != NULL)
	{
		p = fgets(A, MAX, fp);
	}
	if (true)
	{

	}



	return 0;
}

