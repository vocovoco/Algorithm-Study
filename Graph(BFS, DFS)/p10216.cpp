#if 1
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int	camp[3001][3] = { 0, };
vector<int> camp_graph[3001];
int visit[3001] = { 0, };

void dfs(int index, int parent) {
	visit[index] = 1;
	for (int i = 0; i < camp_graph[index].size(); i++) {
		if (visit[camp_graph[index][i]] == 1 || camp_graph[index][i] == parent) continue;
		dfs(camp_graph[index][i], index);
	}
}

int main() {
	int num_of_case, num_of_camp, scc;
	scanf("%d", &num_of_case);

	for (int i = 1; i <= num_of_case; i++) {
		scc = 0;
		scanf("%d", &num_of_camp);
		for (int j = 1; j <= num_of_camp; j++) {
			scanf("%d %d %d", &camp[j][0], &camp[j][1], &camp[j][2]);
			camp_graph[j].clear();
			visit[j] = 0;
		}

		for (int j = 1; j < num_of_camp; j++) {
			for (int k = j + 1; k <= num_of_camp; k++) {
				if (double(camp[j][2] + camp[k][2]) < sqrt(pow((double)(camp[j][0] - camp[k][0]), 2.0) + pow((double)(camp[j][1] - camp[k][1]), 2.0))) continue;
				camp_graph[k].push_back(j);
				camp_graph[j].push_back(k);
			}
		}

		for (int j = 1; j <= num_of_camp; j++) {
			if (visit[j] == 1) continue;
			dfs(j, 0);
			scc++;
		}

		printf("%d\n", scc);
	}
	return 0;
}
#endif