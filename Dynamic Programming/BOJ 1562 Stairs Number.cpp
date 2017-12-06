#if 1
#include <stdio.h>

#define mod 1000000000

int main() {
	int num_of_digit;
	int dp[101][10][1 << 10] = { 0, };
	int sum = 0;
	scanf("%d", &num_of_digit);

	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= num_of_digit; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[num_of_digit][i][(1 << 10) - 1]) % mod;
	printf("%d", sum % mod);
	
	return 0;
}
#endif