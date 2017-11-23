#if 1
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX(a, b) (a > b) ? a : b;

pair<int, vector<int>> node[10001];
int visit[10001] = { 0, };

int dfs(int index, int parent) {
	int count = 1;
	visit[index] = 1;
	for (int i = 0; i < node[index].second.size(); i++) {
		if (visit[node[index].second[i]] == 1) continue;
		count += dfs(node[index].second[i], index);
	}
	return count;
}

int main() {
	int num_of_node, num_of_edge, max_num = 0;
	vector<int> max_nodes;
	scanf("%d %d", &num_of_node, &num_of_edge);

	for (int i = 1; i <= num_of_edge; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[b].second.push_back(a);
		node[b].first = 1;
	}
	
	for (int i = 1; i <= num_of_node; i++) {
		if (node[i].first == 1) {
			int temp = dfs(i, i);
			for (int j = 1; j <= num_of_node; j++) {
				visit[j] = 0;
			}
			if (max_num < temp) {
				max_num = temp;
				max_nodes.clear();
				max_nodes.push_back(i);
			}
			else if (max_num == temp) {
				max_nodes.push_back(i);
			}
		}
	}

	sort(max_nodes.begin(), max_nodes.end());
	for (int i = 0; i < max_nodes.size(); i++) {
		printf("%d ", max_nodes[i]);
	}
	return 0;
}
#endif