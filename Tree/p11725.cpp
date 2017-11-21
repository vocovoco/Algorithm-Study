#if 1
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map<int, vector<int>> tree;

void set_parent(int *node, int index) {
	if (index != 1&&tree[index].size() == 1) return;

	for (int i = 0; i < tree[index].size(); i++) {
		if (tree[index][i] != node[index]) {
			node[tree[index][i]] = index;
			set_parent(node, tree[index][i]);
		}
	}
}
int main() {
	int num_of_node;
	int node[100001] = { 0, };
	scanf("%d", &num_of_node);
	for (int i = 0; i < num_of_node - 1; i++) {
		int p1, p2;

		scanf("%d %d", &p1, &p2);

		if (tree.count(p1)) {
			tree[p1].push_back(p2);
		}
		else {
			tree.insert(pair<int, vector<int>>(p1, { p2 }));
		}

		if (tree.count(p2)) {
			tree[p2].push_back(p1);
		}
		else {
			tree.insert(pair<int, vector<int>>(p2, { p1 }));
		}
	}

	set_parent(node, 1);

	for (int i = 2; i <= num_of_node; i++) {
		printf("%d\n", node[i]);
	}

	return 0;
}
#endif