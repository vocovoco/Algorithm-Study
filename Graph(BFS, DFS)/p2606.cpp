#if 1
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> node[101];
int visit[101] = { 0, };

int dfs(int index, int parent) {
	int count = 1;
	for (int i = 0; i < node[index].size(); i++) {
		if (node[index][i] == parent || visit[node[index][i]] == 1) continue;
		visit[node[index][i]] = 1;
		count += dfs(node[index][i], index);
	}
	return count;
}
int main() {
	int num_of_node, num_of_edge;
	scanf("%d", &num_of_node);
	scanf("%d", &num_of_edge);

	for (int i = 1; i <= num_of_edge; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	visit[1] = 1;
	printf("%d", dfs(1, 0) - 1);
	return 0;
}
#endif