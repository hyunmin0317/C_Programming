#include <stdio.h>

int main(void)
{
	int time;
	int hour;
	int minute;
	int second;

	printf("시간을 초단위로 입력: ");
	scanf("%d", &time);
	hour = time / 3600;
	minute = (time % 3600) / 60;
	second = (time % 3600) % 60;

	printf("%d초는 %d시간 %d분 %d초이다.\n", time, hour, minute, second);
	return 0;
}