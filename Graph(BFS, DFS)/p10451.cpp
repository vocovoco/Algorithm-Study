#if 0
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int>	node[1001];
vector<int>	node_r[1001];
map<int, int> priority;
int visit[1001] = { 0, };
int gCount = 0;

void dfs(int index) {
	priority.insert({ ++gCount , index});
	visit[index] = 1;
	for (int i = 0; i < node[index].size(); i++) {
		if (visit[node[index][i]] == 1) continue;
		dfs(node[index][i]);
	}
	priority.insert({ ++gCount , index });
}

void dfs_r(int index) {
	visit[index] = 0;
	for (int i = 0; i < node_r[index].size(); i++) {
		if (visit[node_r[index][i]] == 0) continue;
		dfs_r(node_r[index][i]);
	}
}

int main() {
	int num_of_case, num_of_edge, scc;
	scanf("%d", &num_of_case);

	for (int i = 1; i <= num_of_case; i++) {
		gCount = 0;
		scc = 0;
		scanf("%d", &num_of_edge);
		for (int j = 1; j <= num_of_edge; j++) {
			int a;
			scanf("%d", &a);
			node[j].push_back(a);
			node_r[a].push_back(j);
		}

		for (int j = 1; j <= num_of_edge; j++) {
			if (visit[j] == 1) continue;
			dfs(j);
		}

		for (int j = 2 * num_of_edge; j > 0; j--) {
			if (visit[priority[j]] == 0) continue;
			dfs_r(priority[j]);
			scc++;
		}

		printf("%d\n", scc);

		for (int j = 1; j <= num_of_edge; j++) {
			node[j].clear();
			node_r[j].clear();
		}
		priority.clear();
	}
	return 0;
}
#endif
#if 1
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int	node[1001] = { 0, };
int visit[1001] = { 0, };

int dfs(int index, int target) {
	visit[index] = 1;
	if (node[index] == target) return 1;
	if (dfs(node[index], target)) return 1;
}

int main() {
	int num_of_case, num_of_edge, scc;
	scanf("%d", &num_of_case);

	for (int i = 1; i <= num_of_case; i++) {
		scc = 0;
		scanf("%d", &num_of_edge);
		for (int j = 1; j <= num_of_edge; j++) {
			int a;
			scanf("%d", &a);
			node[j] = a;
		}

		for (int j = 1; j <= num_of_edge; j++) {
			if (visit[j] == 1) continue;
			dfs(j, j);
			scc++;
		}

		printf("%d\n", scc);

		for (int j = 1; j <= num_of_edge; j++) {
			visit[j] = 0;
		}
	}
	return 0;
}
#endif