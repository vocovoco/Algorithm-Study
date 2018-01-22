#if 0
#include<stdio.h>

int main() {
	int count_ary[42] = { 0, };
	int count = 0;

	for (int i = 0; i < 10; i++) {
		int a;
		scanf("%d", &a);

		if (count_ary[a % 42] == 0) {
			count++;
			count_ary[a % 42]++;
		}
	}

	printf("%d", count);
	return 0;
}
#endif