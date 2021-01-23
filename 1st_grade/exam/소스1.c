#include <stdio.h>
#include <math.h>

struct point
{
	int x;
	int y;
};

int main(void)
{
	double distance;
	struct point dot1;
	struct point dot2;
	printf("x1: ");
	scanf("%d", &dot1.x);
	printf("y1: ");
	scanf("%d", &dot1.y);
	printf("x2: ");
	scanf("%d", &dot2.x);
	printf("y2: ");
	scanf("%d", &dot2.y);
	distance = sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y));
	printf("두 점의 길이는 %lf이다.\n", distance);
	return 0;
}