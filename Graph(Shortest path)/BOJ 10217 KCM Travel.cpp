#if 1
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

#define INF 10e8
#define START_POINT 1

typedef struct _vertex {
	int destination;
	int cost;
	int time;
}Vertex;

int main() {
	int num_of_case;
	scanf("%d", &num_of_case);

	for (int i = 0; i < num_of_case; i++) {
		vector<Vertex> vertex[101];
		queue<Vertex> q_for_v;
		int dp[101][10001];
		int num_of_pt, max_cost, num_of_ticket;
		scanf("%d %d %d", &num_of_pt, &max_cost, &num_of_ticket);

		for (int j = 1; j <= num_of_pt; j++) {
			vertex[j].clear();
		}
		memset(dp, -1, sizeof(dp));
		dp[START_POINT][0] = 0;
		
		for (int j = 1; j <= num_of_ticket; j++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			vertex[a].push_back({ b, c, d });
		}

		q_for_v.push({ START_POINT, 0, 0 });
		while (!q_for_v.empty()) {
			Vertex index = q_for_v.front(); q_for_v.pop();
			int ind_d = index.destination;
			int ind_c = index.cost;
			int ind_t = index.time;
			if (ind_t > dp[ind_d][ind_c] || ind_c > max_cost) continue;

			for (int j = 0; j < vertex[ind_d].size(); j++) {
				Vertex temp = vertex[ind_d][j];
				int temp_d = temp.destination;
				int temp_c = temp.cost;
				int temp_t = temp.time;
				if (temp_c + ind_c <= max_cost && (dp[temp_d][temp_c + ind_c] > temp_t + ind_t || dp[temp_d][temp_c + ind_c] == -1)) {
					dp[temp_d][temp_c + ind_c] = temp_t + ind_t;
					q_for_v.push({ temp_d, temp_c + ind_c, temp_t + ind_t });
				}
			}
		}

		int result = INF;
		for (int j = 0; j <= max_cost; j++) {
			if (dp[num_of_pt][j] != -1 && result > dp[num_of_pt][j]) {
				result = dp[num_of_pt][j];
			}
		}
		if (result == INF) {
			printf("Poor KCM\n");
		}
		else {
			printf("%d\n", result);
		}
	}
	return 0;
}
#endif