#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 256
#define MAX 64

int day[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };  // 배열로 1~12월 까지 마지막날짜 넣기

typedef struct
{
    char year[MAX]; // 연도
    char month[MAX]; // 월
    char day[MAX]; // 일
}TOEIC;

typedef struct
{
    char enlgish[MAX]; // 영어 단어
    char korean1[MAX]; // 한글 뜻1
    char korean2[MAX]; // 한글 뜻 2
}Word;

int n; // word.txt의 전체 배열의 수
int m; // toeic.txt의 전체 배열의 수
Word* list;  // word.txt의 동적배열
TOEIC* T; // toeic.txt의 동적배열

void Aoption(Word* arr, int a, char* A[]); // a 옵션 함수, 영어단어 사전 데이터에 추가하는 함수
void Doption(Word* arr, char* A[]); // d 옵션 함수 , 영어단어 사전 데이터에서 삭제하는 함수
void Eloption(Word* arr, int n); // el 옵션 함수, 영어 사전 순으로 정렬하는 함수 
void Kloption(Word* arr, int n);  // kl 옵션 함수, 한국어 뜻 사전 순으로 정렬하는 함수
void Roption(Word* arr, int n); // r 옵션 함수, 영어 사전 순 반대로 정렬하는 함수
void Rtoption(Word* arr, int n); // rt 옵션 함수, 랜덤 테스트 함수
void Dtoption(Word* arr, int n); // dt 옵션 함수, 지정 테스트 함수
void Coption(FILE* fp); // c 옵션 함수, 오늘 날짜의 달에 토익 시험일정을 달력으로 출력하는 함수
void Findoption(Word* arr, char* A[]); // 찾고 싶은 영어단어 또는 한국어 뜻을 입력하면 영어단어 사전 데이터에서 찾는 함수
void Use(Word* arr); // 사용법을 설명하는 함수
void Swap(Word* p, Word* q); // p와 q를 바꾸는 함수
int count_line(FILE* fp); // 데이터의 줄 수를 세는 함수
void read_Word(FILE* fp); // word.txt파일의 데이터를 읽어서 list에 저장하는 함수
void read_Toeic(FILE* fp); // toeic.txt파일의 데이터를 읽어서 T에 저장하는 함수
void print_Word(); // 영어단어 사전 데이터를 출력하는 함수
void write_Word(FILE* fp); // 영어단어 사전 데이터를 word.txt에 쓰는 함수
void data_erase(char* filename); // filename의 데이터를 초기화하는 함수
int search(char s[], char t[]); // 문자열 s에 문자열 t가 있는지 확인하는 함수
int yoon(int year); // 해당 연도가 윤년인지 확인하는 함수
int Firstday(int year, int month); // 해당 달의 첫째 날 요일을 확인하는 함수 
void print(int year, int month, int first); // 해당 달의 달력을 출력하는 함수
int toeic_day(int year, int month, int day); // 해당 날짜가 토익시험인지 확인하는 함수
void printColorString(int color, int* i); // 색깔을 다르게 출력하는 함수
char* strsep(char** stringp, const char* delim);

int main(int argc, char* argv[])
{
    FILE* fp = fopen("word.txt", "r+"); // word.txt를 r+로 연다
    FILE* fp2 = fopen("toeic.txt", "r"); // toeic.txt를 r로 연다
    n = count_line(fp); // 데이터의 줄 수를 세서 n에 저장
    m = count_line(fp2); // 데이터의 줄 수를 세서 m에 저장
    list = (Word*)calloc(n, sizeof(Word)); // 영어사전 데이터를 저장하는 동적 배열
    T = (TOEIC*)calloc(m, sizeof(TOEIC)); // 토익시험 날짜를 저장하는 동적 배열
    read_Word(fp); // word.txt를 읽어서 list에 저장하는 함수
    read_Toeic(fp2); // toeic.txt를 읽어서 T에 저장하는 함수 
    if (argc > 1 && strcmp(argv[1], "-a") == 0) // -a가 입력되면
        Aoption(list, argc, argv);  // a 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-d") == 0) // -d가 입력되면
        Doption(list, argv); // d 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-el") == 0) // -el이 입력되면
        Eloption(list, n); // el 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-kl") == 0) // -kl이 입력되면
        Kloption(list, n); // kl 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-r") == 0) // -r이 입력되면
        Roption(list, n); // r 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-rt") == 0) // -rt이 입력되면
        Rtoption(list, n); // rt 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-dt") == 0) // -dt이 입력되면
        Dtoption(list, n); // dt 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-c") == 0) // -c이 입력되면
        Coption(fp2); // c 옵션 실행
    else if (argc > 1) // 찾고 싶은 값이 입력되면
        Findoption(list, argv); // find 옵션 실행
    else // 아무 값도 입력되지 않으면
        Use(list); // 사용법 출력
    data_erase("word.txt"); // word.txt를 초기화
    write_Word(fp); // word.txt에 list 값을 쓴다
    free(list);
    free(T);
    fclose(fp);
    fclose(fp2);
    return 0;
}

void Aoption(Word* arr, int a, char* A[]) // a 옵션 함수, 영어사전 데이터에 추가하는 함수
{
    char Y;
    int i;
    n++; // 영어사전 데이터의 수에 1을 더함
    realloc(list, sizeof(Word) * n); // list에 크기 n을 다시 할당
    for (i = 2; i < a; i++)
        printf("%s ", A[i]); // 입력한 값 출력
    printf("\nadd? [Y/N]: ");
    scanf("%c", &Y);
    if (Y == 'Y') // Y를 입력받으면
    {
        strcpy(list[n - 1].korean1, "\0"); // realloc으로 할당된 공간의 값을 초기화
        strcpy(list[n - 1].korean2, "\0"); // realloc으로 할당된 공간의 값을 초기화
        switch (a)
        {
        case 5:
            strcpy(list[n - 1].korean2, A[4]); // 새로 할당된 공간에 korean2를 입력
        case 4:
            strcpy(list[n - 1].korean1, A[3]); // 새로 할당된 공간에 korean1를 입력
        case 3:
            strcpy(list[n - 1].enlgish, A[2]); // 새로 할당된 공간에 english을 입력
        default:
            break;
        }
    }
    else // Y가 입력되지 않으면
    {
        n--; // 늘린 전화번호 데이터의 수를 원래대로 돌림
        realloc(list, sizeof(Word) * n); // list에 크기를 원래의 값으로 할당
    }
    print_Word(); // 영어사전 데이터를 출력
}

void Doption(Word* arr, char* A[]) // d 옵션 함수, 영어사전 데이터에서 삭제하는 함수
{
    int index[N]; // 검색된 값의 인덱스를 저장하는 배열
    int i, j;
    int a = 0;
    int b; // 지우고 싶은 번호를 입력받는 변수
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].enlgish, A[2]) || search(arr[i].korean1, A[2]) || search(arr[i].korean2, A[2])) // A[2]는 삭제할 값
        {
            printf("%d %s %s %s\n", a + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // 삭제할 값을 포함한 데이터 모두 출력
            index[a] = i; // 삭제할 값의 인덱스를 저장
            a++;
        }
    }
    if (a > 0) // 삭제할 값이 데이터에 있으면
    {
        printf("which one? ");
        scanf("%d", &b);
        if (a >= b) // a 범위 안의 값을 입력하면
        {
            for (j = index[b - 1]; j < n; j++) // 삭제할 값 뒤부터 하나 앞으로 덮어쓰기
                list[j] = list[j + 1];
            n--;
            realloc(arr, sizeof(Word) * n); // 뒤에 남는 공간 지우기
        }
        else // a 범위 밖의 값을 입력하면
            printf("out of range\n");
    }
    else // 삭제할 값이 데이터에 없으면
        printf("no match found.\n");
    print_Word(); // 영어사전 데이터를 출력
}

void Eloption(Word* arr, int n) // l 옵션 함수, 영어단어를 사전 순으로 정렬하는 함수 
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].enlgish, arr[j].enlgish) < 0)  //arr[i].num이 arr[j].num보다 작으면 0보다 작은수 반환
                Swap(&arr[i], &arr[j]); //Swap함수를 이용해 순서 바꾸기 
        }
    }
    print_Word(); // 영어사전 데이터를 출력
}

void Kloption(Word* arr, int n) // kl 옵션 함수, 한국어 뜻을 사전 순으로 정렬하는 함수
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].korean1, arr[j].korean1) < 0)  //arr[i].num이 arr[j].num보다 작으면 0보다 작은수 반환
                Swap(&arr[i], &arr[j]); //Swap함수를 이용해 순서 바꾸기 
        }
    }
    print_Word(); // 영어사전 데이터를 출력
}

void Roption(Word* arr, int n) // r 옵션 함수, 영어단어를 사전 순 반대로 정렬하는 함수
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].enlgish, arr[j].enlgish) > 0)  //arr[i].num이 arr[j].num보다 작으면 0보다 작은수 반환
                Swap(&arr[i], &arr[j]); //Swap함수를 이용해 순서 바꾸기 
        }
    }
    print_Word(); // 영어사전 데이터를 출력
}

void Rtoption(Word* arr, int n) // rt 옵션 함수, 랜덤 테스트 함수
{
    int num, number, i;
    int correct = 0; // 맞은 횟수(0으로 초기화)
    char korean[MAX]; // 답(한국어 뜻)을 받을 배열
    srand(time(NULL));
    printf("랜덤 영어 테스트 모드\n");
    printf("풀고 싶은 문제개수: "); // 풀고 싶은 문제개수 입력
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        num = rand() % n; // 0부터 n-1까지 난수생성
        printf("%s : ", arr[num].enlgish);
        scanf("%s", korean); // 답(한국어 뜻)을 배열에 받음
        if (!strcmp(arr[num].korean1, korean) || !strcmp(arr[num].korean2, korean)) // 답이 맞을 때 '정답입니다'를 출력하고 맞은 횟수에 더함
        {
            printf("정답입니다.\n");
            correct++;
        }
        else // 답이 틀릴 때 '오답입니다'와 정답을 출력함
        {
            printf("오답입니다.\t");
            printf("%s : %s\n", arr[num].enlgish, arr[num].korean1);
        }
    }
    printf("맞은 개수:%d, 틀린 개수:%d\n", correct, number - correct); // 맞은 횟수와 틀린 횟수를 출력함
}

void Dtoption(Word* arr, int n) // dt 옵션 함수, 지정 테스트 함수
{
    int number, i, j;
    int correct = 0; // 맞은 횟수(0으로 초기화)
    int incorrect = 0; // 틀린 횟수(0으로 초기화)
    int index; // 검색할 단어의 인덱스
    char english[MAX]; // 문제의 영어단어
    char korean[MAX]; // 문제의 한국어 뜻
    printf("지정 영어 테스트 모드\n");
    printf("풀고 싶은 문제개수: "); // 풀고 싶은 문제개수 입력 
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        index = -1;
        int num = n;
        printf("영어: ");
        scanf("%s", english); // 풀고 싶은 문제의 영어단어 입력
        printf("뜻: ");
        scanf("%s", korean); // 문제의 한국어 뜻 입력
        for (j = 0; j < n; j++)
            if (!strcmp(english, arr[j].enlgish)) // 풀고 싶은 문제의 영어단어가 영어사전 데이터에 존재하는지 확인
                index = j;
        if (index == -1) // 영어사전 데이터에 존재하지 않을때 '영어사전에 없습니다.' 를 출력
            printf("%s는 영어사전에 없습니다.\n", english);
        else // 영어사전 데이터에 존재할때
        {
            if (!strcmp(arr[index].korean1, korean) || !strcmp(arr[index].korean2, korean)) // 답이 맞을 때 '정답입니다'를 출력하고 맞은 횟수에 더함
            {
                printf("정답입니다.\n");
                correct++;
            }
            else // 답이 틀릴 때 '오답입니다'와 정답을 출력하고 틀린 횟수에 더함
            {
                printf("오답입니다.\t");
                printf("%s : %s\n", arr[index].enlgish, arr[index].korean1);
                incorrect++;
            }
        }
    }
    printf("맞은 개수:%d, 틀린 개수:%d\n", correct, incorrect); // 맞은 횟수와 틀린 횟수를 출력함
}

void Coption(FILE* fp) // c 옵션 함수, 오늘 날짜의 달에 토익 시험일정을 달력으로 출력하는 함수
{
    int year, month;
    printf("년도를 입력하세요: ");
    scanf("%d", &year);
    printf("월을 입력하세요: ");
    scanf("%d", &month);
    print(year, month, Firstday(year, month)); // 해당 연도와 달의 달력을 출력 
}

void Findoption(Word* arr, char* A[]) // 찾고 싶은 영어단어 또는 한국어 뜻을 입력하면 영어단어 사전 데이터에서 찾는 함수
{
    int i;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].enlgish, A[1]) || search(arr[i].korean1, A[1]) || search(arr[i].korean2, A[1])) // A[1]은 검색할 값
        {
            printf("%d %s %s %s\n", a + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // 검색한 값을 포함한 데이터 모두 출력
            a++;
        }
    }
    if (a > 0) // 검색한 값이 영어사전 데이터에 있으면
        printf("match found.\n");
    else // 검색한 값이 영어사전 데이터에 없으면
        printf("no match found.\n");
}

void Use(Word* arr) // 사용법을 설명하는 함수
{
    printf("NAME \t\tEnglish dictionary - a program that manages English words.\n");
    printf("SYNOPSIS \tdic[-option] words.\n");
    printf("DESCRIPTION \tPrograms that search, add, delete, list, test, calender etc. english words.\n");
    printf("  -a\t\tAdd or exit program if the right number range is in which one ?\n");
    printf("  -d\t\tIf the correct number range is in which one ? , delete the entry or exit the program\n");
    printf("  -el\t\tArrange english dictionaries in order of alphabetic.\n");
    printf("  -kl\t\tArrange english dictionaries in order of korean.\n");
    printf("  -r\t\tArrange english dictionaries in order of reverse alphabetic\n");
    printf("  -rt\t\tWhen a given English word comes out, the Korean language is matched.\n");
    printf("  -dt\t\tEnter English and Korean meaning to solve the problem.\n");
    printf("  -c\t\tEntering the year and month shows the TOEIC date and calendar of the month.\n");
    printf("  words\t\tFind the line to which the word belongs and if there is no output, no match found output\n");
}

void Swap(Word* p, Word* q) // p와 q를 바꾸는 함수
{
    Word tmp = *p;
    *p = *q;
    *q = tmp;
}

int count_line(FILE* fp)  //fp로 시작하는 파일의 줄 수를 세는 함수
{
    char str[N]; // N 크기의 배열 생성
    int i = 0;
    while (fgets(str, N, fp) != NULL) // fp를 읽어서 NULL이 아닐때 까지
        i++;
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
    return i;
}

void read_Word(FILE* fp) // word.txt를 읽어서 list에 저장하는 함수
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
            parts = strsep(&str, "."); // buffer의 문자열을 :로 구분하여 parts로 받음
            int i = 0;
            while (parts != NULL) // parts가 NULL이 아닐때 까지
            {
                switch (i)
                {
                case 0:
                    strcpy(list[j].enlgish, parts); // i가 0이면 parts를 english에 복사
                    break;
                case 1:
                    strcpy(list[j].korean1, parts); // i가 1이면 parts를 korean1에 복사
                    break;
                case 2:
                    strcpy(list[j].korean2, parts); // i가 2면 parts를 korean2에 복사
                    break;
                }
                parts = strsep(&str, ".\n"); // buffer의 문자열을 :과 \n 으로 구분하여 parts로 받음
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
}

void read_Toeic(FILE* fp) // toeic.txt를 읽어서 T에 저장하는 함수
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
            parts = strsep(&str, "."); // buffer의 문자열을 :로 구분하여 parts로 받음
            int i = 0;
            while (parts != NULL) // parts가 NULL이 아닐때 까지
            {
                switch (i)
                {
                case 0:
                    strcpy(T[j].year, parts); // i가 1이면 parts를 year에 복사
                    break;
                case 1:
                    strcpy(T[j].month, parts); // i가 2면 parts를 month에 복사
                    break;
                case 2:
                    strcpy(T[j].day, parts); // i가 3면 parts를 day에 복사
                    break;
                }
                parts = strsep(&str, ".\n"); // buffer의 문자열을 :과 \n 으로 구분하여 parts로 받음
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp의 파일 포인터를 파일 시작으로 이동
}

void print_Word() // 영어단어 사전 데이터를 출력하는 함수
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %3d %s %s %s\n", i + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // 모든 영어사전 데이터를 출력
}

void write_Word(FILE* fp) // 영어단어 사전 데이터를 word.txt에 쓰는 함수
{
    int i;
    for (i = 0; i < n; i++)
        fprintf(fp, "%s.%s.%s\n", list[i].enlgish, list[i].korean1, list[i].korean2); // 모든 영어사전 데이터를 fp에 저장
}

void data_erase(char* filename) // filename의 데이터를 초기화하는 함수
{
    FILE* fp1 = fopen(filename, "w"); // filename에 해당하는 txt파일을 w모드로 열어 txt파일내용을 초기화
    fclose(fp1);
}

int search(char s[], char t[]) // 문자열 s에 문자열 t가 있는지 확인하는 함수
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) // s[i]가 NULL이 아닐 때까지
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // t[k]가 NULL이 아니고 s[j]와 t[k]가 같으면 j++ k++ 
            ;
        if (k > 0 && t[k] == '\0') // 문자열 s에 문자열 t가 포함되는 경우 (k=0에서 k++을 반복하여 t[k]가 NULL일 경우)
            return 1;
    }
    return 0; // 문자열 s에 문자열 t가 포함되지 않는 경우
}

int yoon(int year) // 해당 연도가 윤년인지 확인하는 함수
{ 
    if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
        return 2;  //윤년일때는 2
    else
        return 1;  //윤년이 아닐 때는 1
}

int Firstday(int year, int month) // 해당 달의 첫째 날 요일을 확인하는 함수 
{
    int total = 0;
    for (int i = 2001; i < year; i++)  // 2001년도 부터 전년도까지 총 몇일인지 구하기 
        if (yoon(i) == 2)  // 입력한 년도가 윤년일 경우 2월일 때 366일 더하기 
            total += 366;
        else
            total += 365;
    for (int i = 1; i <= month - 1; i++) {  // 입력한 년도 1월부터 입력한년도의 전 달까지 몇일인지 구하기 
        if (yoon(year) == 2 && i == 2)  // 입력한 년도가 윤년일 경우 2월은 29일 더하기 
            total += 29;
        else
            total += day[i - 1];
    }
    return (total % 7);
}

void print(int year, int month, int first) // 해당 달의 달력을 출력하는 함수
{
    int cnt = 0;
    printf("      %d월 %d   \n", month, year);
    printf("일 월 화 수 목 금 토\n");
    if (first == 6)  // first가 6인경우에는 6번이 공백이 생기나 일요일부터 시작이므로
        printf("");
    else
    {
        for (int i = 0; i < first + 1; i++) { // 첫 번째 요일 전까지 공백 출력하기 
            printf("   ");
            cnt++;
        }
    }
    if (yoon(year) == 2 && month == 2) { // 윤년일 경우 2월은 29일까지 출력하기 
        for (int i = 1; i <= day[1] + 1; ++i) {
            if (toeic_day(year, month, i))
                printColorString(43, i);
            else
                printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
    else // 2월이 아니고 윤년이 아닐경우 출력하기 
    {
        for (int i = 1; i <= day[month - 1]; ++i) {
            if (toeic_day(year, month, i)) // 해당 날짜에 토익시험이 있으면 색을 바꿔서 출력
                printColorString(43, i);
            else
                printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
}

int toeic_day(int year, int month, int day) // 해당 날짜가 토익시험인지 확인하는 함수
{
    for (int i = 0; i < m; i++)
        if (atoi(T[i].year) == year && atoi(T[i].month) == month && atoi(T[i].day) == day) // 해당 날짜가 토익시험이면 1을 아니면 0을 반환
            return 1;
    return 0;
}

void printColorString(int color, int* i) // 색깔을 다르게 출력하는 함수
{
    printf("\033[%dm%2d \033[0m", color, i);
}

char* strsep(char** stringp, const char* delim)
{
    char* ptr = *stringp;
    if (ptr == NULL)
    {
        return NULL;
    }
    while (**stringp)
    {
        if (strchr(delim, **stringp) != NULL)
        {
            **stringp = 0x00; (*stringp)++; return ptr;
        }
        (*stringp)++;
    }
    *stringp = NULL;
    return ptr;
}