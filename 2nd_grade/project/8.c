#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 256

typedef struct 
{
	char name[N]; // 이름
	int score1; // 점수1
	int score2; // 점수2
	int score3; // 점수3
	int sum; // 합
	double average; // 평균
}Score;

int count(FILE* fp);  //fp로 시작하는 파일의 줄 수를 세는 함수
void read(FILE* fp, Score* list); // 'data.txt'를 읽어서 list에 저장하는 함수
int compare(const void* p, const void* q);
void print_txt(int n, Score* list);
void print_result(int n, Score* list);

int main(void)
{
    FILE* fp = fopen("data.txt", "rt"); // 'data.txt'를 'rt'로 연다
    Score* list = (Score*)calloc(N, sizeof(Score));
    int n = count(fp); // 현재 배열 수
    read(fp, list); // 'data.txt'를 읽어서 list에 저장
    print_txt(n, list); // 'print_txt' 함수를 이용해 txt파일을 출력
    print_result(n, list); // 'print_result' 함수를 이용해 결과를 출력
    return 0;
}

int count(FILE* fp)  //fp로 시작하는 파일의 줄 수를 세는 함수
{
    char str[N]; // N 크기의 배열 생성
    int i = 0; // 반복문을 쓰기 위한 변수
    while (fgets(str, N, fp) != NULL) // fp를 읽어서 NULL이 아닐때 까지
        i++;
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
    return i;
}

void read(FILE* fp, Score* list) // 'data.txt'를 읽어서 list에 저장하는 함수
{
    int i = 0; // 반복문을 쓰기 위한 변수
    int j = 0;
    char str[N]; // N 크기의 배열 생성
    if (fp != NULL) // fp가 NULL이 아니면
    {
        while (fgets(str, N, fp) != NULL) // fp를 읽어서 NULL이 아닐때 까지
        {
            char* parts = strtok(str, ":");
            i = 0;
            while (parts != NULL) // parts가 NULL이 아닐때 까지
            {
                switch (i)
                {
                case 0:
                    strcpy(list[j].name, parts); // i가 0이면 parts를 name에 복사
                    break;
                case 1:
                    list[j].score1 = atoi(parts); // i가 1이면 atoi 함수를 통해 parts를 정수로 변환하여 score1에 넣음
                    break;
                case 2:
                    list[j].score2 = atoi(parts); // i가 2이면 atoi 함수를 통해 parts를 정수로 변환하여 score2에 넣음
                    break;
                case 3:
                    list[j].score3 = atoi(parts); // i가 3이면 atoi 함수를 통해 parts를 정수로 변환하여 score3에 넣음
                    break;
                }
                parts = strtok(NULL, ":\n"); // buffer의 문자열을 :과 \n 으로 구분하여 parts로 받음
                i++;
                list[j].sum = list[j].score1 + list[j].score2 + list[j].score3; // score1, score2, score3을 모두 더해서 총합 sum을 구함 
                list[j].average = list[j].sum / 3.0; // 총합 sum을 3으로 나눠서 평균 average를 구함 
            }
            j++;
        }
    }
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
}

int compare(const void* p, const void* q) // p와 q를 비교하는 함수
{
    int i = ((Score*)p)->sum; // p의 sum을 i에 넣음
    int j = ((Score*)q)->sum; // q의 sum을 j에 넣음
    return (j - i); // qsort를 내림차순으로 하기 위해 j-i를 반환 
}

void print_txt(int n, Score* list) // 'print_txt' 함수를 이용해 txt파일을 출력
{
    int i; // 반복문을 쓰기 위한 변수
    printf("data.txt의 내용\n");
    for (i = 0; i < n; i++) // list'에 입력된 값 중 'data.txt'이 저장된 값을 모두 출력
        printf("\t%4s\t%2d\t%2d\t%2d\n", list[i].name, list[i].score1, list[i].score2, list[i].score3);
    printf("\n");
}

void print_result(int n, Score* list) // 'print_result' 함수를 이용해 결과를 출력
{
    int i; // 반복문을 쓰기 위한 변수
    printf("합 내림차순 정렬 후\n");
    printf("\t이름   점수1   점수2   점수3\t합\t평균\n");
    qsort(list, n, sizeof(Score), compare); // qsort를 이용해 내림차순으로 정렬
    for (i = 0; i < n; i++) // 'list'에 입력된 결과 값을 모두 출력
        printf("\t%4s\t%2d\t%2d\t%2d\t%2d\t%2.2f\n", list[i].name, list[i].score1, list[i].score2, list[i].score3, list[i].sum, list[i].average);
    printf("\n");
}