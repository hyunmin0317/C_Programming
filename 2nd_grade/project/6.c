#include <stdio.h>
#define N 256

void binary(int num); // 10진수인 정수 'num'을 2진수로 변환한 값을 배열 'n'에 저장한 뒤 출력하는 함수

int main(void)
{
	int num; // 정수형 변수 선언							
	printf("10진수를 입력하세요: ");	
	scanf("%d", &num); // 10진수를 scanf를 통해 변수 num에 받음		
	binary(num); // 함수 'binary'를 통해 10진수를 2진수로 출력
	return 0;
}

void binary(int num) // 10진수인 정수 'num'을 2진수로 변환한 값을 배열 'n'에 저장한 뒤 출력하는 함수
{
	int i = 0; // 반복문을 쓰기 위한 변수
	int j;
	int n[N] = { 0, }; // 'num'을 2진수로 변환한 값을 저장할 배열
	printf("이진수: ");
	if (num == 0) // 'num'이 0일 때
		printf("%d", num);
	while (num != 0) // 'num'이 0이 아닐 때
	{
		n[i] = num % 2; // 'num'을 2로 나눈 나머지를 배열 'n'에 저장
		num /= 2; // 'num'을 2로 나눔
		i++;
	}
	for (j = i-1; j >= 0; j--) // 'num'을 2진수로 변환한 값을 저장한 배열 'n'을 뒤에서 부터 출력
		printf("%d", n[j]);
	printf("\n");
}