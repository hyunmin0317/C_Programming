#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WORD 5													// 단어의 개수
#define MAX 20													// 단어의 최대길이

void swap(int* a, int* b);										// 두 변수 a와 b의 값을 바꿔주는 함수(swap)
int test(char w[MAX], int n);									// 단어를 받아 빈칸 문제를 내고 맞으면 1 틀리면 0을 반환하는 영어 단어 시험 함수(test)

int main(void)
{
	int i = 0;													// 반복 변수									
	char word[WORD][MAX];										// 문자열(단어)를 저장할 이차원 배열(word)
	int count = 0;												// 맞은 횟수
	FILE* fp = fopen("word.txt", "rt");							// "word.txt" 파일을 "rt"(읽기)모드로 엶
	if (fp == NULL)												// 파일 오픈 실패 시 예외처리
	{
		printf("파일 열기 실패\n");
		return -1;
	}	
	while (fgets(word[i], MAX, fp) != NULL)						// fp부터 '\n'을 만날 때까지의 문자열을 이차원 배열의 i행(word[i])에 저장  
	{
		if (word[i][strlen(word[i]) - 1] == '\n')				// fgets로 받은 문자열(word[i]) 끝에 '\n'이 포함된 경우 '\0'로 변환하여 삭제
			word[i][strlen(word[i]) - 1] = '\0';					
		i++;													// i++로 행 변환
	}
	printf(" 영어 단어 시험 프로그램\n");
	printf(" 지금부터 영어 단어 시험을 실시하겠습니다.\n");
	for (i = 0; i < WORD; i++)
		if (test(word[i], i))									// test 함수의 문제를 맞추면 맞은 횟수(count)에 1을 더함
			count++;
	printf(" 문제 %d개 중 %d개를 맞추셨습니다. 100점 만점에 %d점입니다.\n", WORD, count, count * 100 / WORD);	// 문제 개수, 맞춘 개수, 점수(백분율) 문제 개수/ 맞춘 개수 * 100 출력
	fclose(fp);													// 파일을 닫음
	return 0;
}

void swap(int* a, int* b)										// 두 변수 a와 b의 값을 바꿔주는 함수(swap)
{
	int temp = *a;												// 변수 a의 주소값을(*a) 변수(temp)에 저장
	*a = *b;													// 변수 b의 주소값을(*b) 변수 a의 주소값에(*a) 저장
	*b = temp;													// 변수 a의 주소값을(temp) 변수 b의 주소값에(*b) 저장
}

int test(char w[MAX], int n)									// 단어를 받아 빈칸 문제를 내고 맞으면 1 틀리면 0을 반환하는 영어 단어 시험 함수(test)
{		
	srand(time(NULL));											// 1초 단위로 변하는 time(NULL)값을 srand 함수를 통해 시드 값에 넣음
	int len = strlen(w);										// 문자열의 길이
	int r1 = rand() % len;										// 첫번째 빈칸의 인덱스, 0부터 n-1까지의 난수(r1)
	int r2 = rand() % len;										// 두번째 빈칸의 인덱스, 0부터 n-1까지의 난수(r2)
	char c1, c2;												// 답을 받을 문자 변수(c1, c2)
	int i;														// 반복 변수
	while (r1 == r2)											// r1과 r2가 같을 때 두 수가 다를때까지 r2를 다시 받음
	{
		r2 = rand() % len;
		if (r1 != r2)
			break;
	}
	if (r1 > r2)												// r1이 r2보다 클 때 두 수의 값을 바꿈
		swap(&r1, &r2);
	printf(" 문제%d: ", n + 1);
	for (i = 0; i < len; i++)
	{
		if (i == r1 || i == r2)									// 문자열의 인덱스(i)가 r1 또는 r2일때 문자 대신 빈칸(-) 출력
			printf("_");
		else													// 문자열의 인덱스(i)가 r1 또는 r2가 아닐 때 해당 인덱스의 문자 출력
			printf("%c", w[i]);
	}
	printf("\n 첫 번째 문자 입력: ");
	scanf("%c", &c1);
	getchar();													// 입력 버퍼 비우기
	printf(" 두 번째 문자 입력: ");
	scanf("%c", &c2);
	getchar();													// 입력 버퍼 비우기
	if (w[r1] == c1 && w[r2] == c2)								// 두 문자를 맞게 입력했을때 "정답입니다"를 출력하고 1을 반환
	{
		printf(" 정답입니다. 축하합니다.\n\n");
		return 1;
	}
	else														// 두 문자 중 하나라도 틀렸을때 "틀렸습니다"와 정답을 출력하고 0을 반환
	{
		printf(" 틀렸습니다. 정답은 %s입니다.\n\n", w);
		return 0;
	}
}