#include <stdio.h>

int main(void)
{
	int money;
	int price;
	int change;
	int tax;

	printf("¹ÞÀºµ· : ");
	scanf("%d", &money);
	printf("»óÇ°ÀÇ ÃÑ¾× : ");
	scanf("%d", &price);
	tax = price / 10;
	change = money - price;

	printf("ºÎ°¡¼¼ : %d\n", tax);
	printf("ÀÜµ· : %d\n", change);
	return 0;
}