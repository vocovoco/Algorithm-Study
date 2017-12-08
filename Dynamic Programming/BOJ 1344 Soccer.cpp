#if 1
#include <stdio.h>
#include <math.h>

int main() {
	int prob_a, prob_b; 
	double result_a = 0.0;
	double result_b = 0.0;
	int combination[19][19];
	scanf("%d %d", &prob_a, &prob_b);

	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) combination[i][j] = 1;
			else combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
		}
	}

	for (int i = 0; i <= 18; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13 || i == 17) continue;
		result_a += (double)combination[18][i] * pow(((double)prob_a / 100.0), (double)i) * pow((1.0 - (double)prob_a / 100.0), (double)(18 - i));
		result_b += (double)combination[18][i] * pow(((double)prob_b / 100.0), (double)i) * pow((1.0 - (double)prob_b / 100.0), (double)(18 - i));
	}
	printf("%0.16f", (1.0 - result_a * result_b));
	return 0;
}
#endif