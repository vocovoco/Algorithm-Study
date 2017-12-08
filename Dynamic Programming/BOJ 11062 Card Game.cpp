#if 1
#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

int main() {
	int num_of_case;
	scanf("%d", &num_of_case);
	while (num_of_case--) {
		int num_of_card;
		int dp[1001][1001] = { 0, };
		int card[1001] = { 0, };
		scanf("%d", &num_of_card);
		for (int i = 1; i <= num_of_card; i++) {
			scanf("%d", &card[i]);
			dp[i][i] = card[i];
			if (i > 1)
				dp[i - 1][i] = MAX(card[i - 1], card[i]);
		}
		for (int i = 2; i <= num_of_card - 1; i++) {
			for (int j = 1; j <= num_of_card - i; j++) {
				int left = card[j] + MIN(dp[j + 1][j + i - 1], dp[j + 2][j + i]);
				int right = card[j + i] + MIN(dp[j][j + i - 2], dp[j + 1][j + i - 1]);
				dp[j][j + i] = MAX(left, right);
			}
		}

		printf("%d\n", dp[1][num_of_card]);
	}
	return 0;
}
#endif