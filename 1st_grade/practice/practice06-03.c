#include <stdio.h>

int main(void)
{
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2len = sizeof(arr2) / sizeof(int);
	printf("%d", arr2len);
	return 0;
}