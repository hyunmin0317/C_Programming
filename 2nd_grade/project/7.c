#include <stdio.h>
#include <time.h>
#define M 12

int Day[M] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // 1~12월까지 각 달의 총 일수을 담은 배열

int yoon(int year); // 해당 연도가 윤년인지 확인하는 함수
int days(int year, int month, int day); // 해당 연도의 1월 1일부터 해당 날까지의 일수를 반환하는 함수
int total(int year1, int month1, int day1, int year2, int month2, int day2); // 기준일로부터 계산일까지의 일수를 반환하는 함수

int main(void)
{
	int year1, month1, day1; // 기준일을 담을 정수형 변수 선언
	int year2, month2, day2; // 계산일을 담을 정수형 변수 선언

	// 기준일 입력
	printf("기준일을 입력하세요.\n"); 
	printf("yyyy mm dd: ");
	scanf("%d %d %d", &year1, &month1, &day1);
	printf("%d %d %d\n", year1, month1, day1);
	
	// 계산일 입력
	printf("계산일을 입력하세요.\n");
	printf("yyyy mm dd: ");
	scanf("%d %d %d", &year2, &month2, &day2);
	printf("%d %d %d\n", year2, month2, day2);

	// 계산일이 기준일보다 클 때 'total'함수를 통해 기준일로부터 계산일까지의 일수를 출력
	if (year2 > year1 || ((year2 == year1 && month2 > month1) || (year2 == year1 && month2 == month1 && day2 >= day1)))
		printf("%d일째 입니다.\n", total(year1, month1, day1, year2, month2, day2));
	else // 계산일이 기준일보다 작을 때 예외처리
		printf("기준일이 계산일보다 큼니다. 다시 입력하세요.\n");
	return 0;
}

int yoon(int year) // 해당 연도가 윤년인지 확인하는 함수
{
	if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
		return 1;  //윤년일때는 1을 반환
	else
		return 0;  //윤년이 아닐 때는 0을 반환
}

int days(int year, int month, int day) // 해당 연도의 1월 1일부터 해당 날까지의 일수를 반환하는 함수
{
	int i; // 반복문을 쓰기 위한 변수
	int days = 0; // 총 일수를 담을 변수를 선언 후 초기화
	for (i = 1; i < month; i++)
	{
		days += Day[i-1]; // 해당 달의 일수를 총 일수에 더함
		if (i == 2 && yoon(year)) // 해당 연도가 윤년이고 해당 달이 2월이면 총 일수에 1을 더함
			days++;
	}
	days += day; // 해당 일을 총 일수에 더함
	return days; // 총 일수를 반환
}

int total(int year1, int month1, int day1, int year2, int month2, int day2) // 기준일로부터 계산일까지의 일수를 반환하는 함수
{
	int i; // 반복문을 쓰기 위한 변수
	int total = 0; // 기준일로부터 계산일까지의 일수를 담을 변수를 선언 후 초기화
	if (year1 == year2) // 기준일과 계산일이 같은 연도일 때
		total = days(year2, month2, day2) - days(year1, month1, day1) + 1; // 계산일의 총 일수에 기준일의 총 일수를 뺀 뒤 1을 더함
	else // 기준일과 계산일이 다른 연도일 때
	{
		for (i = year1 + 1; i < year2; i++)
		{
			total += 365; // 기준일과 계산일사이 모든 연도의 일수를 더함
			if (yoon(i))
				total++; // 해당 연도가 윤년이면 기준일로부터 계산일까지의 일수에 1을 더함
		}
		total += 365 - days(year1, month1, day1) + 1; // days함수를 통해 구한 기준일부터 기준일의 연도 12월 31일까지의 일수(1년 - 총 일수)를 기준일로부터 계산일까지의 일수에 더함
		total += days(year2, month2, day2); // days함수를 통해 구한 계산일의 계산일 연도 총 일수를 기준일로부터 계산일까지의 일수에 더함
		if (yoon(year1)) // 기준일이 윤년이면 1을 더함
			total++; 
	}
	return total; // 기준일로부터 계산일까지의 일수를 반환
}