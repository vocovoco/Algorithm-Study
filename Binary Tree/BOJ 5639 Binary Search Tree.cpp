#if 1
#include <stdio.h>
#include <vector>

using namespace std;

pair<int, int> node[1000001];

void post_order(int index) {
	if (node[index].first != -1) {
		post_order(node[index].first);
	}
	if (node[index].second != -1) {
		post_order(node[index].second);
	}
	printf("%d\n", index);
}

int main() {
	int root, data;
	scanf("%d", &root);
	node[root].first = node[root].second = -1;

	while (scanf("%d", &data) != EOF) {
		int index = root;
		while (true) {
			if (index > data) {
				if (node[index].first == -1) {
					node[data].first = node[data].second = -1;
					node[index].first = data;
					break;
				}
				else {
					index = node[index].first;
				}
			}
			else {
				if (node[index].second == -1) {
					node[data].first = node[data].second = -1;
					node[index].second = data;
					break;
				}
				else {
					index = node[index].second;
				}
			}
		}
	}

	post_order(root);

	return 0;
}
#endif