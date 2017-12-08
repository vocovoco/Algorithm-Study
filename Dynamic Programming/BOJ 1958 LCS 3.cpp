#if 1
#include <stdio.h>
#include <string.h>

#define MAX2(a, b) (a > b) ? a : b
#define MAX3(a, b, c) ((MAX2(a,b)) > c) ? (MAX2(a,b)) : c
char* lcs(char* s1, char* s2) {
	char result[101];
	int dp[101][101] = { 0, };

	for (int i = 0; i < strlen(s1); i++) {
		for (int j = 0; j < strlen(s2); j++) {

		}
	}
	return result;
}
int main() {
	char s1[101], s2[101], s3[101];
	int dp[101][101][101] = { 0, };
	char* temp_s;
	scanf("%s %s %s", s1, s2, s3);

	for (int i = 0; i < strlen(s1); i++) {
		for (int j = 0; j < strlen(s2); j++) {
			for (int k = 0; k < strlen(s3); k++) {
				if (s1[i] == s2[j] && s2[j] == s3[k]) {
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				}
				else {
					dp[i + 1][j + 1][k + 1] = MAX3(dp[i][j + 1][k + 1], dp[i + 1][j][k + 1], dp[i + 1][j + 1][k]);
				}
			}
		}
	}

	printf("%d", dp[strlen(s1)][strlen(s2)][strlen(s3)]);
	return 0;
}
#endif