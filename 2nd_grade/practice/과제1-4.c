#include <stdio.h>
#define PI 3.141592

int main(void)
{
	int radius;
	float circle_area;
	float circumference;
	int cylinder_height;
	float cylinder_area;
	float cylider_volume;
	float sphere_volume;

	printf("원\n");
	printf("원의 반지름: ");
	scanf("%d", &radius);
	circle_area = radius * radius * PI;
	circumference = 2 * radius * PI;
	printf("원의 면적: %lf\n", circle_area);
	printf("원의 둘레: %lf\n\n", circumference);

	printf("원기둥\n");
	printf("원기둥 밑면의 반지름: %d\n", radius);
	printf("원기둥의 높이: ");
	scanf("%d", &cylinder_height);
	cylinder_area = circle_area * 2 + circumference * cylinder_height;
	cylider_volume = circle_area * cylinder_height;
	printf("원기둥의 겉넓이: %lf\n", cylinder_area);
	printf("원기둥의 부피: %lf\n\n", cylider_volume);

	printf("구\n");
	printf("구의 반지름: %d\n", radius);
	sphere_volume = 4 / 3 * PI * radius * radius * radius;
	printf("구의 부피: %lf\n", sphere_volume);
	return 0;
}