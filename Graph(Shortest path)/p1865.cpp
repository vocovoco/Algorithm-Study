#if 1
#include <stdio.h>

using namespace std;

#define INF 10e12
#define START_POINT 1

int main() {
	int edge[5201][3];
	long long dist[501];
	int num_of_case, num_of_pt, num_of_path, num_of_Npath;
	scanf("%d", &num_of_case);

	for (int i = 0; i < num_of_case; i++) {
		scanf("%d %d %d", &num_of_pt, &num_of_path, &num_of_Npath);
		for (int j = 1; j <= num_of_path * 2; j += 2) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge[j][0] = a;
			edge[j][1] = b;
			edge[j][2] = c;

			edge[j + 1][0] = b;
			edge[j + 1][1] = a;
			edge[j + 1][2] = c;
		}
		for (int j = num_of_path * 2 + 1; j <= num_of_path * 2 + num_of_Npath; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge[j][0] = a;
			edge[j][1] = b;
			edge[j][2] = c * -1;
		}
		
		for (int j = 1; j <= num_of_pt; j++) {
			dist[j] = INF;
		}
		dist[START_POINT] = 0;
		
		for (int j = 1; j <= num_of_pt - 1; j++) {
			for (int k = 1; k <= num_of_path * 2 + num_of_Npath; k++) {
				if (dist[edge[k][0]] != INF && dist[edge[k][1]] > dist[edge[k][0]] + edge[k][2]) {
					dist[edge[k][1]] = dist[edge[k][0]] + edge[k][2];
				}
			}
		}

		int possible = 0;
		for (int j = 1; j <= num_of_path * 2 + num_of_Npath; j++) {
			if (dist[edge[j][0]] != INF && dist[edge[j][1]] > dist[edge[j][0]] + edge[j][2]) {
				possible = 1;
			}
		}

		if (possible) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}
#endif