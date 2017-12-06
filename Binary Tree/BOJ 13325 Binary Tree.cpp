#if 1
#include <stdio.h>
#include <math.h>

#define MAX(a, b) (a > b) ? a : b

int main() {
	int level, count = 0, node[2097152] = { 0, };
	scanf("%d", &level);
	for (int i = 2; i < pow(2.0, level + 1); i++) {
		scanf("%d", &node[i]);
	}

	for (int i = pow(2.0, level); i < pow(2.0, level + 1); i += 2) {
		node[i] = node[i + 1] = MAX(node[i], node[i + 1]);
		count += node[i] + node[i + 1];
	}

	while (--level != 0) {
		for (int i = pow(2.0, level); i < pow(2.0, level + 1); i += 2) {
			int left = node[i] + node[i * 2];
			int right = node[i + 1] + node[(i + 1) * 2];
			if (left > right) {
				node[i + 1] += left - right;
			}
			else {
				node[i] += right - left;
			}
			count += node[i] + node[i + 1];
			node[i] += node[i * 2];
			node[i + 1] += node[(i + 1) * 2];
		}
	}
	printf("%d", count);
	return 0;
}
#endif