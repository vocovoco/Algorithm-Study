#if 1
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

int search(long long* ary, int ary_size, long long min, long long max, int target) {
	int local_max = 0;
	long long temp = 0, current = 0;
	while (min <= max) {
		current = (min + max) / 2;
		temp = 0;
		for (int i = 0; i < ary_size; i++) {
			temp += ary[i] / current;
		}
		if (temp >= target) {
			min = current + 1;
			local_max = MAX(local_max, current);
		}
		else if (temp < target) max = current - 1;
	}

	return local_max;
}

int main() {
	int num_of_wire, target_num;
	long long wire[10000], max = 2147483647, min = 0;
	scanf("%d %d", &num_of_wire, &target_num);
	for (int i = 0; i < num_of_wire; i++) {
		scanf("%lld", &wire[i]);
	}
	printf("%d", search(wire, num_of_wire, min, max, target_num));

	return 0;
}
#endif