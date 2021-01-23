#include <stdio.h>
#define MAX 10

int main(void)
{
	int Num[MAX];								//정수 10개를 입력받을 배열
	int freq_num, freq;							//최빈값과 빈도수
	int count = 1;								//현재 가장 많은 빈도수
	int i, j;
	printf(" 최빈값 출력 프로그램\n");
	printf(" 정수 10개를 입력하세요.\n");
	for (i = 0; i < MAX; i++)					//배열에 정수 10개를 입력
	{
		printf(" n%d: ", i + 1);
		scanf("%d", &Num[i]);
	}
	for (i = 0; i < MAX; i++)					//배열의 최빈값 확인
	{
		freq = 1;
		for (j = i + 1; j < MAX; j++)
			if (Num[i] == Num[j])				//해당 값과 같은 값일 때
				freq++;							//빈도수 추가
		if (freq>=count)						//해당 값의 빈도수가 현재 가장 많은 빈도수 보다 클 때
		{
			freq_num = Num[i];					//최빈값 변경
			count = freq;						//현재 가장 많은 빈도수 변경
		}
	}
	printf(" 배열에 저장된 값 중 최빈값은 %d이다.\n", freq_num);
	return 0;
}