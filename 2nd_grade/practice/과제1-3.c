#include <stdio.h>

int main(void)
{
	int height;
	float inch;
	int feet;

	printf("cm로 표현된 키 입력: ");
	scanf("%d", &height);
	inch = height / 2.54;
	feet = inch / 12;
	inch = inch - feet*12;
	printf("%dcm는 %d피트 %lf 인치이다.\n",height, feet, inch);
	return 0;
}