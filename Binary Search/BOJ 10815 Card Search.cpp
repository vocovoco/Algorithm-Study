#if 1
#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second) {
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int binary_search(int* ary, int ary_size, int target) {
	int start = 0;
	int end = ary_size;
	while (1) {
		int mid = (start + end) / 2;
		if (target > ary[mid]) {
			start = mid + 1;
		}
		else if (target < ary[mid]) {
			end = mid;
		}
		else {
			return 1;
		}
		if (start >= end) return 0;
	}
}

int main() {
	int total_pool, pool[500000], total_num;
	scanf("%d", &total_pool);
	for (int i = 0; i < total_pool; i++) {
		scanf("%d", &pool[i]);
	}
	qsort(pool, total_pool, sizeof(int), compare);
	scanf("%d", &total_num);
	for (int i = 0; i < total_num; i++) {
		int a;
		scanf("%d", &a);
		printf("%d ", binary_search(pool, total_pool, a));
	}

	return 0;
}
#endif