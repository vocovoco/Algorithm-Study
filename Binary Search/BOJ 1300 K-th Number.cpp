#if 1
#include <stdio.h>
#include <map>

using namespace std;

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

int main() {
	int ary_size, target;
	scanf("%d %d", &ary_size, &target);
	long long min = 0, max = target, value = max;

	while (min <= max) {
		long long current = (min + max) / 2;
		long long result = 0;
		for (int i = 1; i <= ary_size; i++) {
			result += MIN(current / i, ary_size);
		}
		if (result >= target) {
			max = current - 1;
			value = current;
		}
		else if (result < target) {
			min = current + 1;
		}
	}
	
	printf("%lld", value);
	return 0;
}
#endif