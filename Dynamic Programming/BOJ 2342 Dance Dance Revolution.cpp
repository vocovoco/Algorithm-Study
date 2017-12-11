#if 1
#include <stdio.h>
#include <math.h>

#define INF 10e7
#define MIN(a, b) (a < b) ? a : b

int moving(int current, int target) {
	if (current == 0) return 2;
	if (current == target) return 1;
	if (abs(current - target) % 2 == 1) return 3;
	else return 4;
}

int main() {
	int dp[2][5][5];
	int power = INF, count = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dp[0][i][j] = dp[1][i][j] = INF;
		}
	}
	dp[0][0][0] = 0;

	while (true) {
		int a;
		scanf("%d", &a);
		if (a == 0) break;
		
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j != a) {
					int left = moving(i, a);
					dp[(count + 1) % 2][a][j] = MIN(dp[(count + 1) % 2][a][j], dp[count % 2][i][j] + left);
				}
				if (i != a) {
					int right = moving(j, a);
					dp[(count + 1) % 2][i][a] = MIN(dp[(count + 1) % 2][i][a], dp[count % 2][i][j] + right);
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dp[count % 2][i][j] = INF;
			}
		}
		count++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			power = MIN(power, dp[count % 2][i][j]);
		}
	}
	printf("%d", power);
	return 0;
}
#endif