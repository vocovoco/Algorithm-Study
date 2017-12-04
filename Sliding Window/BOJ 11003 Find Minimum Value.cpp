// https://pgr21.com/pb/pb.php?id=freedom&no=43185 ÂüÁ¶
#if 1
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_NUM 1000000000
#define MIN(a, b) (a < b) ? a : b

int main() {
	int ary_size, window_size;
	int ary[5000000];
	scanf("%d %d", &ary_size, &window_size);
	for (int i = 0; i < ary_size; i++) {
		scanf("%d", &ary[i]);
	}

	for (int i = 0; i < ary_size; i += window_size) {
		vector<int> temp(window_size * 2 - 1);
		temp[window_size - 1] = ary[i];
		for (int j = 1; j < window_size; j++) {
			if (i + j < ary_size)
				temp[window_size - 1 + j] = MIN(temp[window_size - 1 + j - 1], ary[i + j]);
			else
				temp[window_size - 1 + j] = MAX_NUM + 1;
			if (i - j >= 0)
				temp[window_size - 1 - j] = MIN(temp[window_size - 1 - j + 1], ary[i - j]);
			else
				temp[window_size - 1 - j] = MAX_NUM;
		}
		for (int j = 0; j < window_size; j++) {
			if (temp[window_size - 1 + j] > MAX_NUM) break;
			printf("%d ", MIN(temp[j], temp[window_size - 1 + j]));
		}
	}
	return 0;
}
#endif