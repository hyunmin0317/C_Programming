#include <stdio.h>
#include <string.h>
#define N 32										// 이름, 주소, 전화번호를 담을 배열의 크기
#define MAX 256										// 전화번호를 담을 전화번호부 구조체 P의 크기

typedef struct 
{
	char name[N];
	char address[N];
	char phone[N];
}PHONE;												// 이름, 주소, 전화번호로 구성된 전화번호부 구조체 PHONE

int Index(PHONE* A, char* find, int n);				// 전화번호부(PHONE)에 검색하는 이름이 저장된 곳의 인덱스를 반환해주는 함수

int main(void)
{
	int n = 3;										// 전화번호부(PHONE)에 저장된 전화번호의 개수를 나타내는 변수 (초기 전화번호의 개수가 3개이므로 3으로 초기화) 
	int num;										// 옵션번호 변수(0부터 4까지)
	int index;										// 검색하는 이름이 저장된 곳의 인덱스를 나타내는 변수
	int i;											// 반복변수 i
	PHONE P[MAX] = { 0, };							// 전화번호를 저장할 전화번호부(PHONE) 생성 후 0으로 초기화
	char find[N];									// 검색할 이름의 문자열을 담을 배열 생성

	// 전화번호부(PHONE)에 3개의 전화번호를 저장(초기값 저장), 문자열 복사 함수를 통해 저장
	strcpy(P[0].name, "최현민");
	strcpy(P[0].address, "서울");
	strcpy(P[0].phone, "010-7938-3017");
	strcpy(P[1].name, "홍길동");
	strcpy(P[1].address, "종로");
	strcpy(P[1].phone, "010-222-2222");
	strcpy(P[2].name, "성춘향");
	strcpy(P[2].address, "남원");
	strcpy(P[2].phone, "010-333-3333");

	printf("-------------------------------------\n");
	printf(" 전화번호 관리 프로그램을 시작합니다.\n");
	printf("-------------------------------------\n");
	while (1)
	{
		printf(" 삽입:0, 삭제:1, 찾기:2, 전체보기:3, 종료:4 >> ");
		scanf("%d", &num);													// 옵션번호 변수를 받음 (0부터 4까지)
		if (num == 0)														// 옵션 0
		{
			// 현재 전화번호가 저장된 배열 마지막칸의 다음칸에 전화번호를 받고 저장
			printf(" 이름>> ");
			scanf("%s", P[n].name);
			printf(" 주소>> ");
			scanf("%s", P[n].address);
			printf(" 전화번호>> ");
			scanf("%s", P[n].phone);
			n++;															// 전화번호가 하나 추가되었으므로 전화번호부(PHONE)에 저장된 전화번호의 개수에 1을 더함
		}
		else if (num == 1)													// 옵션 1
		{
			printf(" 이름>> ");
			scanf("%s", find);												// 검색할 이름을 받음
			index = Index(P, find, n);										// Index함수를 통해 검색하는 이름의 저장된 인덱스를 변수 index에 받음
			if (index == -1)												// 검색하는 이름이 존재하지 않을 때 예외처리 
				printf(" %s는 등록되지 않은 사람입니다.\n", find);
			else															// 검색하는 이름이 존재할 때
			{
				for (i = index; i < n; i++)									// 검색된 이름의 인덱스부터 마지막 전화번호까지 뒤에서부터 앞으로 덮어쓰며 검색된 이름 삭제
					P[i] = P[i + 1];
				printf(" %s는 삭제되었습니다.\n", find);
				n--;														// 전화번호가 하나 삭제되었으므로 전화번호부(PHONE)에 저장된 전화번호의 개수에 1을 뺌
			}
		}
		else if (num == 2)													// 옵션 2
		{
			printf(" 이름>> ");
			scanf("%s", find);												// 검색할 이름을 받음
			index = Index(P, find, n);										// Index함수를 통해 검색하는 이름의 저장된 인덱스를 변수 index에 받음
			if (index == -1)												// 검색하는 이름이 존재하지 않을 때 예외처리
				printf(" %s는 등록되지 않은 사람입니다.\n", find);
			else															// 검색하는 이름이 존재할 때 검색된 전화번호 출력
				printf(" %s %s %s\n", P[index].name, P[index].address, P[index].phone);
		}
		else if (num == 3)													// 옵션 3
		{
			for (i = 0; i < n; i++)											// 전화번호부(PHONE)에 저장된 전화번호 모두 출력
				printf(" %s %s %s\n", P[i].name, P[i].address, P[i].phone);
		}
		else if (num == 4)													// 옵션 4
		{
			printf(" 프로그램을 종료합니다.\n");							// 전화번호 관리 프로그램 종료
			break;
		}
		else																// 옵션이 0부터 4까지의 값이 아닐때
			printf(" 0~4 범위내에서 다시 입력하세요.\n");
		printf("\n");
	}
	return 0;
}

int Index(PHONE* A, char* find, int n)										// 전화번호부(PHONE)에 검색하는 이름이 저장된 곳의 인덱스를 반환해주는 함수
{
	int i;
	int index = -1;															// 전화번호부(PHONE)에 검색하는 이름이 없을 때 index는 -1
	for (i = 0; i < n; i++)
		if (strcmp(A[i].name, find) == 0)									// 검색하는 이름과 전화번호부(PHONE)에 전화번호 이름이 같을 때 그 전화번호의 인덱스를 index에 저장
			index = i;
	return index;															// index를 반환
}