#include <stdio.h>
#define MAX 128
#define SIZE 3

typedef struct
{
	char number[MAX];
	char name[MAX];
	char memo[MAX];
}Phonenumber;

void Read(Phonenumber arr)
{
	Phonenumber str = arr;
	printf("전화번호 정보를 입력하시오.\n");
	printf("번호: ");
	scanf("%s", str.number);
	printf("이름: ");
	scanf("%s", str.name);
	printf("메모: ");
	scanf("%s", str.memo);
}

int main(void)
{
	Phonenumber arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		Read(arr[i]);
		for (int j = 0; j <= i; j++)
		{
			printf("%d %s %s %s \n", j + 1, arr[j].number, arr[j].name, arr[j].memo);
		}
	}
	return 0;
}

/*
int main(void)
{
	Phonenumber arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		printf("전화번호 정보를 입력하시오.\n");
		printf("번호: ");
		scanf("%s", arr[i].number);
		printf("이름: ");
		scanf("%s", arr[i].name);
		printf("메모: ");
		scanf("%s", arr[i].memo);
		for (int j = 0; j <= i; j++)
		{
			printf("%d %s %s %s \n", j+1, arr[j].number, arr[j].name, arr[j].memo);
		}
	}
	return 0;
}
*/
