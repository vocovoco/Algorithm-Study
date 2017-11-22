#if 1
#include <stdio.h>

int main() {
	int map[101][101] = { 0, };
	long long dp[101][101] = { 0, };
	int width;
	scanf("%d", &width);

	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= width; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = (width * 2 - 1); i > 1; i--) {
		int a, b;
		if (i > width) {
			a = width;
			b = i - width;
		}
		else {
			b = 1;
			a = i - b;
		}
		while (a > 0 && b < width + 1) {
			if (a + map[a][b] <= width) {
				if (a + map[a][b] == width && b == width) {
					dp[a][b]++;
				}
				else {
					dp[a][b] += dp[a + map[a][b]][b];
				}
			}
			if (b + map[a][b] <= width) {
				if (b + map[a][b] == width && a == width) {
					dp[a][b]++;
				}
				else {
					dp[a][b] += dp[a][b + map[a][b]];
				}
			}
			a--;
			b++;
		}
	}

	printf("%lld", dp[1][1]);
	return 0;
}
#endif