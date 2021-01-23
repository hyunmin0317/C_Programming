#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE* fp1 = fopen("eq.txt","rt");
	FILE* fp2 = fopen("eq.soln.txt", "wt");
	int a;
	int b;
	int c;
	double x1;
	double x2;
	while (feof(fp1) == 0)
	{
		fscanf(fp1, "%d, %d, %d", &a, &b, &c);
		if (x_true(a,b,c))
		{
			x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
			fprintf(fp2, "%d, %d, %d, %lf, %lf\n", a, b, c,x1,x2);
		}
		else
		{
			fprintf(fp2, "%d, %d, %d, %s\n", a, b, c,"해를 구할 수 없습니다.");
		}
	}
	return 0;
}

int x_true(a, b, c)
{
	if (b*b-4*a*c<0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}