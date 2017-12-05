#if 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) (a < b) ? a : b

int compare(const void *first, const void *second) {
	if (*(long long*)first > *(long long*)second)
		return 1;
	else if (*(long long*)first < *(long long*)second)
		return -1;
	else
		return 0;
}

int main() {
	int num_of_solution;
	long long min = 10e10, solution[5001], answer[3];
	scanf("%d", &num_of_solution);
	for (int i = 0; i < num_of_solution; i++) {
		scanf("%lld", &solution[i]);
	}
	
	qsort(solution, num_of_solution, sizeof(long long), compare);

	for (int i = 0; i < num_of_solution - 2; i++) {
		int left = i + 1, right = num_of_solution - 1, end_flag = 0;
		while (left < right) {
			long long sum = solution[left] + solution[right] + solution[i];
			if (min > abs(sum)) {
				min = abs(sum);
				answer[0] = solution[i];
				answer[1] = solution[left];
				answer[2] = solution[right];
			}

			if (sum > 0) {
				right--;
			}
			else if(sum < 0){
				left++;
			}
			else {
				end_flag = 1;
				break;
			}
		}
		if (end_flag) break;
	}
	printf("%lld %lld %lld", answer[0], answer[1], answer[2]);
	return 0;
}
#endif