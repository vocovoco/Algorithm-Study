#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b) ? a : b

int dfs(int index, int (*rule)[1001], int num_of_building, int *time, int *dp) {
	if (rule[index][index] == 1) {
		return dp[index];
	}

	for (int i = 1; i <= num_of_building; i++) {
		if (rule[i][index] == 1) {
			dp[index] = MAX(dfs(i, rule, num_of_building, time, dp) + time[index], dp[index]);
		}
	}
	rule[index][index] = 1;
	return dp[index];
}
int main() {
	int num_of_case = 0;

	scanf("%d", &num_of_case);

	for (int i = 0; i < num_of_case; i++) {
		int num_of_building = 0;
		int num_of_rule = 0;
		int time[1001] = { 0, };
		int rule[1001][1001] = { 0, };
		int last_building = 0;
		int dp[1001] = { 0, };

		scanf("%d %d", &num_of_building, &num_of_rule);
		for (int j = 1; j <= num_of_building; j++) {
			scanf("%d", &time[j]);
			dp[j] = time[j];
		}
		for (int j = 0; j < num_of_rule; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			rule[x][y] = 1;
		}
		scanf("%d", &last_building);

		printf("%d\n", dfs(last_building, rule, num_of_building, time, dp));
	}

	return 0;
}
#endif