#if 0
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX(a, b) (a > b) ? a : b;
#define ROOT 1

using namespace std;

typedef struct _vertex {
	vector<pair<int, int>> edge;
	int l1;
	int l2;
	int leaf;
}Vertex;
Vertex vertex[10001];
int max_length = 0;

int dfs(int index) {
	for (int i = 0; i < vertex[index].edge.size(); i++) {
		int child = vertex[index].edge[i].first;
		int length = 0;
		if (vertex[child].edge.empty()) {
			length = vertex[index].edge[i].second;
		}
		else {
			length = dfs(vertex[index].edge[i].first) + vertex[index].edge[i].second;
		}
		
		if (vertex[index].l1 < length) {
			vertex[index].l2 = vertex[index].l1;
			vertex[index].l1 = length;
		}
		else if (vertex[index].l2 < length) {
			vertex[index].l2 = length;
		}

		max_length = MAX(max_length, vertex[index].l1 + vertex[index].l2);
	}
	return vertex[index].l1;
}
int main() {
	int num_of_vertex;
	scanf("%d", &num_of_vertex);

	for (int i = 0; i < num_of_vertex - 1; i++) {
		int parent, child, dist;
		scanf("%d %d %d", &parent, &child, &dist);
		vertex[parent].edge.push_back(pair<int, int>(child, dist));
		vertex[parent].l1 = 0;
		vertex[parent].l2 = 0;
		vertex[parent].leaf = -1;
	}

	dfs(ROOT);

	printf("%d", max_length);
	return 0;
}
#endif