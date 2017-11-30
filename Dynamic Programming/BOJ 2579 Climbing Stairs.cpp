#if 0
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
	int answer = 0;
	int num_of_height = 0;
	int ary[300];
	int dp[300][2];

	scanf("%d", &num_of_height);

	for (int i = 0; i < num_of_height; i++) {
		scanf("%d", &ary[i]);
	}

	dp[0][0] = ary[0];
	dp[0][1] = 0;
	dp[1][0] = ary[1] + dp[0][0];
	dp[1][1] = ary[1] + dp[0][1];

	for (int i = 2; i < num_of_height; i++) {
		dp[i][0] = ary[i] + dp[i - 1][1];
		dp[i][1] = ary[i] + ((dp[i - 2][0] > dp[i - 2][1]) ? dp[i - 2][0] : dp[i - 2][1]);
	}

	printf("%d", ((dp[num_of_height - 1][0] > dp[num_of_height - 1][1]) ? dp[num_of_height - 1][0] : dp[num_of_height - 1][1]));
	return 0;
}
#endif