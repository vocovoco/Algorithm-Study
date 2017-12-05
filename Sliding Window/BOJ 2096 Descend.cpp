#if 1
#include <stdio.h>

#define MAX2(a, b) (a > b) ? a : b
#define MAX3(a, b, c) ((MAX2(a, b)) > c) ? (MAX2(a,b)) : c
#define MIN2(a, b) (a < b) ? a : b
#define MIN3(a, b, c) ((MIN2(a, b)) < c) ? (MIN2(a,b)) : c

int main() {
	int i, num_of_line, min_v[2][3], max_v[2][3];
	scanf("%d", &num_of_line);
	for (i = 0; i < num_of_line; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		min_v[i % 2][0] = max_v[i % 2][0] = a;
		min_v[i % 2][1] = max_v[i % 2][1] = b;
		min_v[i % 2][2] = max_v[i % 2][2] = c;

		if(i > 0) {
			min_v[i % 2][0] += MIN2(min_v[(i - 1) % 2][0], min_v[(i - 1) % 2][1]);
			min_v[i % 2][1] += MIN3(min_v[(i - 1) % 2][0], min_v[(i - 1) % 2][1], min_v[(i - 1) % 2][2]);
			min_v[i % 2][2] += MIN2(min_v[(i - 1) % 2][1], min_v[(i - 1) % 2][2]);

			max_v[i % 2][0] += MAX2(max_v[(i - 1) % 2][0], max_v[(i - 1) % 2][1]);
			max_v[i % 2][1] += MAX3(max_v[(i - 1) % 2][0], max_v[(i - 1) % 2][1], max_v[(i - 1) % 2][2]);
			max_v[i % 2][2] += MAX2(max_v[(i - 1) % 2][1], max_v[(i - 1) % 2][2]);
		}
	}
	printf("%d %d", MAX3(max_v[(i - 1) % 2][0], max_v[(i - 1) % 2][1], max_v[(i - 1) % 2][2]), MIN3(min_v[(i - 1) % 2][0], min_v[(i - 1) % 2][1], min_v[(i - 1) % 2][2]));
	return 0;
}
#endif