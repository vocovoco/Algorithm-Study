#if 1
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF 10e8

int main() {
	vector<pair<int, int>> vertex[20001];
	queue<int> q_for_v;
	int dist[20001];
	int num_of_vertex, num_of_edge, start_pt;
	scanf("%d %d %d", &num_of_vertex, &num_of_edge, &start_pt);

	for (int i = 1; i <= num_of_edge; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vertex[a].push_back({ b, c });
	}
	for (int i = 1; i <= num_of_vertex; i++) {
		dist[i] = INF;
	}

	dist[start_pt] = 0;
	q_for_v.push(start_pt);
	while (!q_for_v.empty()) {
		int index = q_for_v.front();
		for (int i = 0; i < vertex[index].size(); i++) {
			if (dist[vertex[index][i].first] > vertex[index][i].second + dist[index]) {
				dist[vertex[index][i].first] = vertex[index][i].second + dist[index];
				q_for_v.push(vertex[index][i].first);
			}
		}
		q_for_v.pop();
	}
	for (int i = 1; i <= num_of_vertex; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
		
	}
	return 0;
}
#endif