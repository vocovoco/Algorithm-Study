#if 1
#include <stdio.h>

int main() {
	int target;
	double dp[1000001] = { 0.0, 1.0, };
	scanf("%d", &target);

	for (int i = 2; i <= target; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] += (dp[i - j] + 1.0) * (1.0 / 6.0);
			}
			else {
				dp[i] += 1.0 / 6.0;
			}
		}
	}

	printf("%.16f", dp[target]);
	return 0;
}
#endif