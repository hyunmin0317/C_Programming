#include <stdio.h>
#define MAX 64
#define N 256

typedef struct {
    char number[MAX];
    char year[MAX];
    char month[MAX];
    char day[MAX];
}TOEIC;

int Day[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };  //배열로 1~12월 까지 마지막날짜 넣기
int m;
TOEIC* T;

int yoon(int year) {  // 윤년구하는 함수 
    if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
        return 2;  //윤년일때는 2
    else
        return 1;  //윤년이 아닐 때는 1
}
int Firstday(int year, int month)  // 1일이 무슨 요일인지 구하기 
{
    int total = 0;
    for (int i = 2001; i < year; i++)  // 2001년도 부터 전년도까지 총 몇일인지 구하기 
        if (yoon(i) == 2)  // 입력한 년도가 윤년일 경우 2월일 때 366일 더하기 
            total += 366;
        else
            total += 365;
    for (int i = 1; i <= month - 1; i++) {  // 입력한 년도 1월부터 입력한년도의 전 달까지 몇일인지 구하기 
        if (yoon(year) == 2 && i == 2)  //입력한 년도가 윤년일 경우 2월은 29일 더하기 
            total += 29;
        else
            total += Day[i - 1];
    }
    return (total % 7);
}
void Coption(FILE* fp)  //first는 MOD한 값 월요일은 0, 일요일은 6
{
    int year, month, day;
    int first;
    int cnt = 0;

    printf("년도를 입력하세요: ");
    scanf("%d", &year);
    printf("월을 입력하세요: ");
    scanf("%d", &month);
    printf("날짜를 입력하세요: ");
    scanf("%d", &day);
    first = Firstday(year, month);
    printf("      %d월 %d   \n", month, year);
    printf("일 월 화 수 목 금 토\n");
    if (first == 6)  //first가 6인경우에는 6번이 공백이 생기나 일요일부터 시작이므로
        printf("");
    else
    {
        for (int i = 0; i < first + 1; i++) { // 첫 번째 요일 전까지 공백 출력하기 
            printf("   ");
            cnt++;
        }
    }

    if (yoon(year) == 2 && month == 2) { // 윤년일 경우 2월은 29일까지 출력하기 
        for (int i = 1; i <= Day[1] + 1; ++i) {
            printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
    else // 2월이 아니고 윤년이 아닐경우 출력하기 
    {
        for (int i = 1; i <= day[month - 1]; ++i) {
            printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
}

void read_Toeic(FILE* fp) // data.txt를 읽어서 slist에 저장하는 함수
{
    int i = 0;
    char buffer[N];
    int j = 0;
    if (fp != NULL) // fp가 NULL이 아니면
    {
        while (fgets(buffer, N, fp) != NULL) // fp를 읽어서 NULL이 아닐때 까지
        {
            char* parts;
            char* str = buffer;
            parts = strsep(&str, ":"); // buffer의 문자열을 :로 구분하여 parts로 받음
            int i = 0;
            while (parts != NULL) // parts가 NULL이 아닐때 까지
            {
                switch (i)
                {
                case 0:
                    strcpy(T[j].number, parts); // i가 0이면 parts를 name에 복사
                    break;
                case 1:
                    strcpy(T[j].year, parts); // i가 1이면 parts를 phone1에 복사
                    break;
                case 2:
                    strcpy(T[j].month, parts); // i가 2면 parts를 phone2에 복사
                    break;
                case 3:
                    strcpy(T[j].day, parts); // i가 3면 parts를 memo에 복사
                    break;
                }
                parts = strsep(&str, ":\n"); // buffer의 문자열을 :과 \n 으로 구분하여 parts로 받음
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
}

int count_Phone(FILE* fp)  //fp로 시작하는 파일의 줄 수를 세는 함수
{
    char str[N]; // N 크기의 배열 생성
    int i = 0;
    while (fgets(str, N, fp) != NULL) // fp를 읽어서 NULL이 아닐때 까지
        i++;
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
    return i;
}

int main(void)
{
    int year, month;
    FILE* fp2 = fopen("toeic.txt", "r"); // data.txt를 r+로 연다
    m = count_Toeic(fp2); // 데이터의 줄 수를 세서 n에 저장
    T = (TOEIC*)calloc(m, sizeof(TOEIC));  // 전화번호 데이터를 저장하는 동적 배열
    Coption(fp2); // print 함수에 입력받은 year와 month 그리고
    return 0;
}