#if 0
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

#define MIN(a, b) (a < b) ? a : b;
using namespace std;

typedef struct _vertex {
	int left_child;
	int right_child;
	int num_of_left;
	int num_of_right;
}Vertex;

map<int, Vertex> tree;
int breadth[10001] = { 0, };
int root[10001] = { 0, };
int max_breadth[2] = { 0, };

int dfs(int index, int left_of_parent, int depth) {
	int temp = 0;
	tree[index].num_of_left = left_of_parent;

	if (tree[index].left_child != -1) {
		temp = dfs(tree[index].left_child, tree[index].num_of_left, depth + 1);
		tree[index].num_of_left = temp + 1;
	}
	if (tree[index].right_child != -1) {
		temp = dfs(tree[index].right_child, tree[index].num_of_left + 1, depth + 1);
		tree[index].num_of_right = temp - tree[index].num_of_left;
	}

	if (breadth[depth] == 0) {
		breadth[depth] = index;
	}
	temp = tree[index].num_of_left - tree[breadth[depth]].num_of_left + 1;
	if (max_breadth[0] < temp) {
		max_breadth[0] = temp;
		max_breadth[1] = depth;
	}
	else if (max_breadth[0] == temp) {
		max_breadth[1] = MIN(max_breadth[1], depth);
	}

	return tree[index].num_of_left + tree[index].num_of_right;
}
int main() {
	int num_of_vertex;
	int start_node;
	scanf("%d", &num_of_vertex);

	for (int i = 1; i <= num_of_vertex; i++) {
		int index = 0;
		Vertex temp;
		scanf("%d %d %d", &index, &temp.left_child, &temp.right_child);
		temp.num_of_left = 0;
		temp.num_of_right = 0;
		if (root[temp.left_child] == 0) {
			root[temp.left_child] = 1;
		}
		if (root[temp.right_child] == 0) {
			root[temp.right_child] = 1;
		}
		tree.insert(pair<int, Vertex>(index, temp));
	}

	for (start_node = 1; start_node <= num_of_vertex; start_node++) {
		if (root[start_node] == 0) break;
	}
	dfs(start_node, 0, 1);

	printf("%d %d", max_breadth[1], max_breadth[0]);
	return 0;
}
#endif