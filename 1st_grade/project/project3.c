#include <stdio.h>

int InputYear()
{
	int year;
	do
	{
		printf("년도를 입력하세요: ");
		scanf("%d", &year);
	} while (year < 2001);
	return year;
}

int InputMonth()
{
	int month;
	do
	{
		printf("월를 입력하세요: ");
		scanf("%d", &month);
	} while (month < 1 & 12 < month);
	return month;
}

int LeapYear(year)
{
	int leapyear;
	if (year % 4 == 0)
	{
		leapyear = 1;
	}
	if (year % 100 == 0)
	{
		leapyear = 0;
	}
	if (year % 400 == 0)
	{
		leapyear = 1;
	}
	return leapyear;
}

int Day(year, month)
{
	int day = 0;
	int days = 0;
	for (int i = 2001; i <= year; i++)
	{
		days += 365;
	}
	switch (month)
	{
	case 1:
		days -= 31;
	case 2:
		days -= 28;
	case 3:
		days -= 31;
	case 4:
		days -= 30;
	case 5:
		days -= 31;
	case 6:
		days -= 30;
	case 7:
		days -= 31;
	case 8:
		days -= 31;
	case 9:
		days -= 30;
	case 10:
		days -= 31;
	case 11:
		days -= 30;
	case 12:
		days -= 31;
	default:
		break;
	}
	day = days % 7;
	return day;
}

int main(void)
{
	int year = InputYear();
	int month = InputMonth();
	int day = Day(year, month);
	printf("%d", day);
	return 0;
}