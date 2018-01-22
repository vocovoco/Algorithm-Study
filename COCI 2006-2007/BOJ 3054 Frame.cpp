#if 0
#include <stdio.h>
#include <string.h>

void first_line(int len) {
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			printf(".");
		}
		if (i % 3 == 2) {
			printf(".*..");
		}
		else {
			printf(".#..");
		}
	}
	printf("\n");
}

void second_line(int len) {
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			printf(".");
		}
		if (i % 3 == 2) {
			printf("*.*.");
		}
		else {
			printf("#.#.");
		}
	}
	printf("\n");
}

int main() {
	char voca[20];

	scanf("%s", &voca);

	first_line(strlen(voca));
	second_line(strlen(voca));

	for (int i = 0; i < strlen(voca); i++) {
		if (i == 0) {
			printf("#");
		}
		if (i % 3 == 0 || (i % 3 == 1 && i + 1 == strlen(voca))) {
			printf(".%c.#", voca[i]);
		}
		else {
			printf(".%c.*", voca[i]);
		}
	}
	printf("\n");

	second_line(strlen(voca));
	first_line(strlen(voca));
	
	return 0;
}
#endif