#if 1
#include <stdio.h>

using namespace std;

#define INF 10e12
#define START_POINT 1

int main() {
	int edge[6001][3];
	long long dist[501];
	int num_of_pt, num_of_path;
	scanf("%d %d", &num_of_pt, &num_of_path);

	for (int i = 1; i <= num_of_path; i++) {
		scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
	}
	for (int i = 1; i <= num_of_pt; i++) {
		dist[i] = INF;
	}
	dist[START_POINT] = 0;

	for (int i = 1; i <= num_of_pt - 1; i++) {
		for (int j = 1; j <= num_of_path; j++) {
			if (dist[edge[j][0]] != INF && dist[edge[j][1]] > dist[edge[j][0]] + edge[j][2]) {
				dist[edge[j][1]] = dist[edge[j][0]] + edge[j][2];
			}
		}
	}

	int possible = 0;
	for (int i = 1; i <= num_of_path; i++) {
		if (dist[edge[i][0]] != INF && dist[edge[i][1]] > dist[edge[i][0]] + edge[i][2]) {
			possible = 1;
		}
	}

	if (possible) {
		puts("-1");
	}
	else {
		for (int i = 2; i <= num_of_pt; i++) {
			if (dist[i] == INF) {
				puts("-1");
			}
			else {
				printf("%d\n", dist[i]);
			}
		}
	}
	return 0;
}
#endif