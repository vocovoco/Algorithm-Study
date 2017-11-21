#if 1
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define MAX(a, b) (a > b) ? a : b;
using namespace std;

typedef struct _vertex {
	map<int, int> edge;
	int l1;
	int l2;
}Vertex;
int main() {
	int num_of_vertex;
	Vertex vertex[100001];
	queue<int> q;
	int max = 0;
	scanf("%d", &num_of_vertex);

	for (int i = 1; i <= num_of_vertex; i++) {
		int a = 0, b = 0;
		int index = 0;
		scanf("%d", &index);
		vertex[index].l1 = 0;
		vertex[index].l2 = 0;
		while (true) {
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			vertex[index].edge.insert(pair<int, int>(a, b));
		}
		if (vertex[index].edge.size() == 1) {
			q.push(index);
		}
	}

	while (q.size() > 1) {
		int temp = q.front();

		int parent = vertex[temp].edge.begin()->first;
		int length = vertex[temp].l1 + vertex[temp].edge.begin()->second;
		if (vertex[parent].l1 < length) {
			vertex[parent].l2 = vertex[parent].l1;
			vertex[parent].l1 = length;
		}
		else if (vertex[parent].l2 < length) {
			vertex[parent].l2 = length;
		}
		max = MAX(max, vertex[parent].l1 + vertex[parent].l2);
		vertex[parent].edge.erase(temp);
		if(vertex[parent].edge.size() == 1) {
			q.push(parent);
		}
		q.pop();
	}

	printf("%d", max);
	return 0;
}
#endif