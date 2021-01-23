#include <stdio.h>

int main(void)
{
	int c1, c2, c3;								//컴퓨터의 숫자
	int n1, n2, n3;								//이용자의 숫자
	int strike = 0;								//스트라이크
	int ball = 0;								//볼
	int sum = 0;								//같은 숫자의 개수
	int i = 0;									//시행횟수
	while (sum != 3)							//사용자가 숫자 3개를 다 맞출때까지 반복
	{
		strike = 0;								//스트라이크 초기화
		ball = 0;								//볼 초기화
		i++;									//시행횟수 추가
		printf(" 숫자야구게임 %d번째\n", i);
		
		printf(" 숫자 3개 입력(컴퓨터)\n");		//컴퓨터의 숫자 입력
		printf(" c1: ");
		scanf("%d", &c1);
		printf(" c2: ");
		scanf("%d", &c2);
		while (c2 == c1)						//숫자 중복시 다시 입력
		{
			printf("숫자 중복 불가\n");
			printf(" c2: ");
			scanf("%d", &c2);
		}
		printf(" c3: ");
		scanf("%d", &c3);
		while (c3 == c1 || c3 == c2)			//숫자 중복시 다시 입력
		{
			printf("숫자 중복 불가\n");
			printf(" c3: ");
			scanf("%d", &c3);
		}
		
		printf(" 숫자 3개 입력(사용자)\n");		//사용자의 숫자 입력
		printf(" n1: ");
		scanf("%d", &n1);
		printf(" n2: ");
		scanf("%d", &n2);
		while (n2 == n1)						//숫자 중복시 다시 입력
		{
			printf("숫자 중복 불가\n");
			printf(" n2: ");
			scanf("%d", &n2);
		}
		printf(" n3: ");
		scanf("%d", &n3);
		while (n3 == n1 || n3 == n2)			//숫자 중복시 다시 입력
		{
			printf("숫자 중복 불가\n");
			printf(" n3: ");
			scanf("%d", &n3);
		}

		if (c1 == n1)							//각 자리수와 숫자가 일치(스트라이크)
			strike++;
		if (c1 == n2)							//숫자만 일치(볼)
			ball++;
		if (c1 == n3)							//숫자만 일치(볼)
			ball++;
		if (c2 == n1)							//숫자만 일치(볼)
			ball++;
		if (c2 == n2)							//각 자리수와 숫자가 일치(스트라이크)
			strike++;
		if (c2 == n3)							//숫자만 일치(볼)
			ball++;
		if (c3 == n1)							//숫자만 일치(볼)
			ball++;
		if (c3 == n2)							//숫자만 일치(볼)
			ball++;
		if (c3 == n3)							//각 자리수와 숫자가 일치(스트라이크)
			strike++;
		
		sum = strike + ball;					//같은 숫자의 개수
		printf(" %d, %d, %d vs %d, %d, %d\n", c1, c2, c3, n1, n2, n3);
		printf(" %d스트라이크 %d볼\n", strike, ball);	//결과 출력
		printf("\n");
	}
	printf(" 총 %d번 시행했다.\n", i);
	return 0;
}