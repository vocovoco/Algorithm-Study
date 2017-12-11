#if 1
#include <stdio.h>

#define MIN(a, b) (a < b) ? a : b

int main() {
	int num_of_bulb, num_of_color;
	int bulb[201] = { 0, }, dp[201][201] = { 0, };;
	scanf("%d %d", &num_of_bulb, &num_of_color);
	for (int i = 1; i <= num_of_bulb; i++) {
		scanf("%d", &bulb[i]);
		for (int j = i; j--;) {
			dp[j][i] = 10e8;
			for (int k = j; k < i; k++)
				dp[j][i] = MIN(dp[j][i], dp[j][k] + dp[k + 1][i] + (bulb[j] != bulb[k + 1]));
		}
	}

	printf("%d", dp[1][num_of_bulb]);
	return 0;
}
#endif