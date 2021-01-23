#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

typedef struct
{
    char name[30];
    char phone1[20];
    char phone2[20];
    char memo[40];
}Phone;

int n; // 전체 배열의 수
Phone* slist;  //동적배열

void Aoption(Phone* arr, int a, char* A[]); // a 옵션 함수, 전화번호 데이터에 추가하는 함수
void Doption(Phone* arr, char* A[]); // d 옵션 함수 , 전화번호 데이터에서 삭제하는 함수
void Loption(Phone* arr, int n); // l 옵션 함수, 사전적 정렬하는 함수 
void Findoption(Phone* arr, char* A[]); // 찾고 싶은 문자열을 입력하면 전화번호 데이터에서 찾는 함수 
void Use(Phone* arr); // 사용법을 설명하는 함수
void Swap(Phone* p, Phone* q); // p와 q를 바꾸는 함수
int count_Phone(FILE* fp); // 데이터의 줄 수를 세는 함수
void read_Phone(FILE* fp); // data.txt를 읽어서 slist에 저장하는 함수
void print_Phone(); // 전화번호 데이터를 출력하는 함수
void write_Phone(FILE* fp); // slist 값을 data.txt에 쓰는 함수
void data_erase(char* filename); // filename의 데이터를 초기화하는 함수
int search(char s[], char t[]); // 문자열 s에 문자열 t가 있는지 확인하는 함수
char* strsep(char** stringp, const char* delim);

int main(int argc, char* argv[])
{
    FILE* fp = fopen("data.txt", "r+"); // data.txt를 r+로 연다
    n = count_Phone(fp); // 데이터의 줄 수를 세서 n에 저장
    slist = (Phone*)calloc(n, sizeof(Phone));  // 전화번호 데이터를 저장하는 동적 배열
    read_Phone(fp);  //data.txt를 읽어서 slist에 저장하는 함수
    if (argc > 1 && strcmp(argv[1], "-a") == 0) // -a가 입력되면
        Aoption(slist, argc, argv);  // a 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-d") == 0) // -d가 입력되면
        Doption(slist, argv); // d 옵션 실행
    else if (argc > 1 && strcmp(argv[1], "-l") == 0) // -l이 입력되면
        Loption(slist, n); // l 옵션 실행
    else if (argc > 1) // 찾고 싶은 값이 입력되면
        Findoption(slist, argv); // find 옵션 실행
    else // 아무 값도 입력되지 않으면
        Use(slist); // 사용법 출력
    data_erase("data.txt"); // data.txt를 초기화
    write_Phone(fp); //fp에 slist 값을 쓴다
    free(slist);
    fclose(fp);
    return 0;
}

void Swap(Phone* p, Phone* q) // p와 q를 바꾸는 함수
{
    Phone tmp = *p;
    *p = *q;
    *q = tmp;
}

void Aoption(Phone* arr, int a, char* A[]) // a 옵션 함수, 전화번호 데이터에 추가하는 함수
{
    char Y;
    int i;
    n++; // 전화번호 데이터의 수에 1을 더함
    realloc(slist, sizeof(Phone) * n); // slist에 크기 n을 다시 할당
    for (i = 2; i < a; i++)
        printf("%s ", A[i]); // 입력한 값 출력
    printf("\nadd? [Y/N]: ");
    scanf("%c", &Y);
    if (Y == 'Y') // Y를 입력받으면
    {
        strcpy(slist[n - 1].phone1, "\0"); // realloc으로 할당된 공간의 값을 초기화
        strcpy(slist[n - 1].phone2, "\0"); // realloc으로 할당된 공간의 값을 초기화
        strcpy(slist[n - 1].memo, "\0"); // realloc으로 할당된 공간의 값을 초기화
        switch (a)
        {
        case 6:
            strcpy(slist[n - 1].memo, A[5]); // 새로 할당된 공간에 memo를 입력
        case 5:
            strcpy(slist[n - 1].phone2, A[4]); // 새로 할당된 공간에 phone2를 입력
        case 4:
            strcpy(slist[n - 1].phone1, A[3]); // 새로 할당된 공간에 phone1를 입력
        case 3:
            strcpy(slist[n - 1].name, A[2]); // 새로 할당된 공간에 name을 입력
        default:
            break;
        }
    }
    else // Y가 입력되지 않으면
    {
        n--; // 늘린 전화번호 데이터의 수를 원래대로 돌림
        realloc(slist, sizeof(Phone) * n); // slist에 크기를 원래의 값으로 할당
    }
    print_Phone(); // 전화번호 데이터를 출력
}

void Doption(Phone* arr, char* A[]) // d 옵션 함수, 전화번호 데이터에서 삭제하는 함수
{
    int index[N]; // 검색된 값의 인덱스를 저장하는 배열
    int i, j;
    int a = 0;
    int b; // 지우고 싶은 번호를 입력받는 변수
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].name, A[2]) || search(arr[i].phone1, A[2]) || search(arr[i].phone2, A[2]) || search(arr[i].memo, A[2])) // A[2]는 삭제할 값
        {
            printf("%d %s %s %s %s\n", a + 1, slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // 삭제할 값을 포함한 데이터 모두 출력
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
                slist[j] = slist[j + 1];
            n--;
            realloc(arr, sizeof(Phone) * n); // 뒤에 남는 공간 지우기
        }
        else // a 범위 밖의 값을 입력하면
            printf("out of range\n");
    }
    else // 삭제할 값이 데이터에 없으면
        printf("no match found.\n");
    print_Phone(); // 전화번호 데이터를 출력
}

void Loption(Phone* arr, int n) // l 옵션 함수, 사전적 정렬하는 함수 
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].name, arr[j].name) < 0)  //arr[i].num이 arr[j].num보다 작으면 0보다 작은수 반환
                Swap(&arr[i], &arr[j]); //Swap함수를 이용해 순서 바꾸기 
        }
    }
    print_Phone(); // 전화번호 데이터를 출력
}

void Findoption(Phone* arr, char* A[]) // 찾고 싶은 문자열을 입력하면 전화번호 데이터에서 찾는 함수 
{
    int i;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].name, A[1]) || search(arr[i].phone1, A[1]) || search(arr[i].phone2, A[1]) || search(arr[i].memo, A[1])) // A[1]은 검색할 값
        {
            printf("%d %s %s %s %s\n", a + 1, slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // 검색한 값을 포함한 데이터 모두 출력
            a++;
        }
    }
    if (a > 0) // 검색한 값이 전화번호 데이터에 있으면
        printf("match found.\n");
    else // 검색한 값이 전화번호 데이터에 없으면
        printf("no match found.\n");
}

void Use(Phone* arr) // 사용법을 설명하는 함수
{
    printf("NAME \t\ttel - telephone number management program\n");
    printf("SYNOPSIS \ttel[-option] words\n");
    printf("DESCRIPTION \tPrograms that search, add, delete, list, etc. phone numbers\n");
    printf("  words\t\tFind the line to which the word belongs and if there is no output, no match found output\n");
    printf("  -a\t\tAdd or exit program if the right number range is in which one ?\n");
    printf("  -d\t\tIf the correct number range is in which one ? , delete the entry or exit the program\n");
    printf("  -l\t\tutput a complete list with an Alphabetical order of the name\n");
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

void read_Phone(FILE* fp) // data.txt를 읽어서 slist에 저장하는 함수
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
                    strcpy(slist[j].name, parts); // i가 0이면 parts를 name에 복사
                    break;
                case 1:
                    strcpy(slist[j].phone1, parts); // i가 1이면 parts를 phone1에 복사
                    break;
                case 2:
                    strcpy(slist[j].phone2, parts); // i가 2면 parts를 phone2에 복사
                    break;
                case 3:
                    strcpy(slist[j].memo, parts); // i가 3면 parts를 memo에 복사
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

void print_Phone()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s %s %s\n", slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // 모든 전화번호 데이터를 출력
}

void write_Phone(FILE* fp)
{
    int i;
    for (i = 0; i < n; i++)
        fprintf(fp, "%s:%s:%s:%s\n", slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // 모든 전화번호 데이터를 fp에 저장
}

void data_erase(char* filename)
{
    FILE* fp1 = fopen(filename, "w"); // filename에 해당하는 txt파일을 w모드로 열어 txt파일내용을 초기화
    fclose(fp1);
}

int search(char s[], char t[])
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