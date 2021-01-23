#include <stdio.h>
#include <string.h>

typedef struct
{
	char num[10];
	char name[20];
	int mid;
	int final;
	int practice;
	int homework;
} Score;

void Swap(char* p, char* q)
{
	char* tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void Upnum(Score* arr) {
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(arr->num[j] > arr->num[j + 1])) 
			{
				char tmp;
				tmp = arr->num[j];
				arr->num[j] = arr->num[j + 1];
				arr->num[j + 1] = tmp;

			}
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%s %s %d %d %d %d\n", arr[i].num, arr[i].name, arr[i].mid,
			arr[i].final, arr[i].practice, arr[i].homework);
}


void Read(Score* arr)
{
	FILE* fp = fopen("data.txt", "r");
	/*if (fp == NULL){
	   puts("파일 오픈 실패!");
	   return -1;
	}*/
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%s %s %d %d %d %d ", arr[i].num, arr[i].name, &arr[i].mid,
			&arr[i].final, &arr[i].practice, &arr[i].homework);
	}
}

int main(void)
{
	Score arr[10] = { {"201811111",  "Cho", 60,  60,   48,  23}, {"201811112",  "Lee", 70,  60,  50,  25},
	 {"201811113", "Kim" ,50,  60,  48,  23}, {"201811114",  "Kwon",  80,  80,  64,  32},
	 {"201811115", "Park", 70,  70,  56,  28}, {"201711111", "Choi" ,90,  80,  70,  30},
	 {"201711112", "Won" ,90,  90,  72,  36}, {"201611111","Baek",  100, 100, 80,  40},
	 {"201611113", "Yoo", 70,  75,  56,  28}, {"201511112", "Song" ,80 , 85 , 64 , 32} };

	FILE* fp = fopen("data.txt", "w");
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%s %s %d %d %d %d ", arr[i].num, arr[i].name, arr[i].mid,
			arr[i].final, arr[i].practice, arr[i].homework);
	}

	Read(arr);
	Upnum(arr);




	fclose(fp);
	return 0;
}