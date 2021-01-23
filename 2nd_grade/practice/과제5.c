#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void print_matrix(int n, int(*A)[MAX]);								// 행렬을 출력하는 함수
int confirm_all(int n, int(*A)[MAX]);								// 행렬의 모든 행과 열을 지났는지 확인하는 함수

int main(void)
{
	int tile[MAX][MAX] = { 0, };									// 타일에 딱정벌레가 지나간 횟수를 저장하는 이차원배열 
	srand(time(NULL));
	int number;
	int count = 0;													// 딱정벌레의 이동횟수
	int y = 5;														// 딱정벌레의 위치 y좌표, 5로 초기화
	int x = 5;														// 딱정벌레의 위치 x좌표, 5로 초기화
	while (!confirm_all(10, tile))
	{
		number = rand() % 8;
		switch (number)
		{
		case 0:														// number가 0일 때 (x, y-1)
			if (y != 0)												// 이동할 수 있는 경우만 이동
				y--;
			break;
		case 1:														// number가 1일 때 (x+1, y-1)
			if (y != 0 && x != 9)									// 이동할 수 있는 경우만 이동
			{
				x++;
				y--;
			}
			break;
		case 2:														// number가 2일 때 (x+1, y)
			if (x != 9)												// 이동할 수 있는 경우만 이동
				x++;
			break;
		case 3:														// number가 3일 때 (x+1, y+1)
			if (y != 9 && x != 9)									// 이동할 수 있는 경우만 이동
			{
				x++;
				y++;
			}
			break;
		case 4:														// number가 4일 때 (x, y+1)
			if (y != 9)												// 이동할 수 있는 경우만 이동
				y++;
			break;
		case 5:														// number가 5일 때 (x-1, y+1)
			if (y != 9 && x != 0)									// 이동할 수 있는 경우만 이동
			{
				x--;
				y++;
			}
			break;
		case 6:														// number가 6일 때 (x-1, y)
			if (x != 0)												// 이동할 수 있는 경우만 이동
				x--;
			break;
		default:													// number가 7일 때 (x, y-1)
			if (y != 0 && x != 0)									// 이동할 수 있는 경우만 이동
			{
				x--;
				y--;
			}
		}
		tile[y][x] = 1;												// 딱정벌레의 현재 위치를 1로 바꿈
		count++;
		if (count == 10)
		{
			printf("\n 10번째 random walk 행렬\n");
			print_matrix(MAX, tile);
		}
		else if (count == 100)
		{
			printf("\n 100번째 random walk 행렬\n");
			print_matrix(MAX, tile);
		}
	}
	printf("\n random walk 행렬\n");
	print_matrix(MAX, tile);
	printf("\n 총 %d번 움직였다.\n", count);					   // 총 이동 횟수를 출력
	return 0;
}

void print_matrix(int n, int(*A)[MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %4d ", A[i][j]);								// 행렬의 모든 행과 열 출력
		printf("\n");
	}
}

int confirm_all(int n, int(*A)[MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)										
			if (A[i][j] == 0)
				return 0;											// 행렬의 어떤 행과 열이 0일 때 0을 반환
	return 1;														// 행렬의 모든 행과 열이 0이 아닐 때 1을 반환
}