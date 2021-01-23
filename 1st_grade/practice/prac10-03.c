#include <stdio.h>

int main(void)
{
	char word[100];
	char line[256];
	scanf("%s", word);
	FILE* f = fopen("temp.txt", "rt");
	if (f) {
		while (1) {
			char* p = fgets(line, 256, f);
			if (p != NULL) {
				if (strstr(line, word) != NULL) {
					printf(line);
				}				
			}
			else {
				break;
			}
		}
		fclose(f);
	}
	return 0;
}