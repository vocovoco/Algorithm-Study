#if 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MIN(a, b) (a < b) ? a : b

int compare(const void *first, const void *second) {
	if (abs(*(int*)first) > abs(*(int*)second))
		return 1;
	else if (abs(*(int*)first) < abs(*(int*)second))
		return -1;
	else
		return 0;
}

int main() {
	int num_of_solution, solution[100001], answer[2];
	long long min = 10e9;
	scanf("%d", &num_of_solution);
	for (int i = 0; i < num_of_solution; i++) {
		scanf("%d", &solution[i]);
	}
	qsort(solution, num_of_solution, sizeof(int), compare);
	for (int i = 0; i < num_of_solution - 1; i++) {
		long long mixture = solution[i] + solution[i + 1];
		if (min > abs(mixture)) {
			min = abs(mixture);
			answer[0] = solution[i];
			answer[1] = solution[i + 1];
		}
	}
	if (answer[0] > answer[1]) {
		printf("%d %d", answer[1], answer[0]);
	}
	else {
		printf("%d %d", answer[0], answer[1]);
	}
	return 0;
}
#endif