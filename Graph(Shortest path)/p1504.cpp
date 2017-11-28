#if 1
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MIN(a, b) (a < b) ? a : b
#define INF 10e12

int main() {
	vector<pair<int, int>> vertex[801];
	queue<int> q_for_v;
	long long dist[801][3];
	int num_of_vertex, num_of_edge;
	scanf("%d %d", &num_of_vertex, &num_of_edge);

	for (int i = 1; i <= num_of_edge; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vertex[a].push_back({ b, c });
		vertex[b].push_back({ a, c });
	}
	int pass_pt[3];
	pass_pt[0] = 1;
	scanf("%d %d", &pass_pt[1], &pass_pt[2]);

	for (int i = 1; i <= num_of_vertex; i++) {
		dist[i][0] = INF;
		dist[i][1] = INF;
		dist[i][2] = INF;
	}

	for (int i = 0; i < 3; i++) {
		int start_pt = pass_pt[i];
		dist[start_pt][i] = 0;
		q_for_v.push(start_pt);
		while (!q_for_v.empty()) {
			int index = q_for_v.front();
			for (int j = 0; j < vertex[index].size(); j++) {
				if (dist[vertex[index][j].first][i] > vertex[index][j].second + dist[index][i]) {
					dist[vertex[index][j].first][i] = vertex[index][j].second + dist[index][i];
					q_for_v.push(vertex[index][j].first);
				}
			}
			q_for_v.pop();
		}
	}
	
	long long result = MIN(dist[pass_pt[1]][0] + dist[pass_pt[2]][1] + dist[num_of_vertex][2], dist[pass_pt[2]][0] + dist[pass_pt[1]][2] + dist[num_of_vertex][1]);
	if (result >= INF) {
		printf("%d", -1);
	}
	else {
		printf("%lld", result);
	}
	return 0;
}
#endif