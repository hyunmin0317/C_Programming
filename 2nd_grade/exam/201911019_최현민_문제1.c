#include <stdio.h>

void swap(int* a, int* b);                                                    //두 수의 값을 바꿔주는 함수

int main(void)
{
    int Ax1 = 50, Ay1 = 50, Ax2 = 100, Ay2 = 100;                             //직사각형 A 두 점의 x좌표, y좌표
    int Bx1, By1, Bx2, By2;                                                   //직사각형 B 두 점의 x좌표, y좌표
    for (int i = 0; i < 3; i++)                                               //3번 반복
    {
        printf(" 직사각형 A와 B의 관계 확인 프로그램 %d번째\n", i + 1);
        printf(" 직사각형 B 점1의 x좌표: ");                                  //직사각형 B 두 점의 좌표 입력
        scanf("%d", &Bx1);
        printf(" 직사각형 B 점1의 y좌표: ");
        scanf("%d", &By1);
        printf(" 직사각형 B 점2의 x좌표: ");
        scanf("%d", &Bx2);
        printf(" 직사각형 B 점2의 y좌표: ");
        scanf("%d", &By2);

        if (Bx1 == Bx2 || By1 == By2)
            printf(" 직사각형 B는 존재하지 않는다.\n");                       //직사각형 B는 두 점의 x좌표나 y좌표가 같으면 존재하지 않음
        else
        {
            if (Bx1 > Bx2)                                                    //직사각형 B의 두점을 직사각형 B의 좌하점과 우상점으로 변환
                swap(&Bx1, &Bx2);
            if (By1 > By2)
                swap(&By1, &By2);
            //직사각형 B 두 점 모두 직사각형 A 안에 있으면 직사각형 A는 직사각형 B를 포함함
            if (((Bx1 >= Ax1 && Bx1 <= Ax2) && (By1 >= Ay1 && By1 <= Ay2)) && ((Bx2 >= Ax1 && Bx2 <= Ax2) && (By2 >= Ay1 && By2 <= Ay2)))
                printf(" 직사각형 A는 직사각형 B를 포함한다.\n");
            //직사각형 B 좌하점이 직사각형 A 좌하점보다 x, y 좌표가 작고 직사각형 B 우상점이 직사각형 A 우상점보다 x, y 좌표가 크면 직사각형 B는 직사각형 A를 포함함 
            else if ((Bx1 <= Ax1 && By1 <= Ay1) && (Bx2 >= Ax2 && By2 >= Ay2))
                printf(" 직사각형 B는 직사각형 A를 포함한다.\n");
            //직사각형 B 좌하점이 직사각형 A 우상점보다 x좌표가 크거나 y좌표가 작거나 직사각형 B 우상점이 직사각형 A 좌하점보다 x좌표가 작거나 y좌표가 크면 직사각형 A와 직사각형 B는 겹치지 않음 
            else if (Bx1 >= Ax2 || By1 >= Ay2 || Bx2 <= Ax1 || By2 <= Ay1)
                printf(" 직사각형 A와 직사각형 B는 겹치지 않는다.\n");
            //위 3가지 경우에 해당하지 않으면 직사각형 A와 직사각형 B는 부분적으로 겹침
            else
                printf(" 직사각형 A와 직사각형 B는 부분적으로 겹친다.\n");
        }
        printf("\n");
    }
    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}