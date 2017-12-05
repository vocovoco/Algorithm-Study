#if 1
#include <stdio.h>
#include <map>

using namespace std;

#define MAX(a, b) ((a > b) ? a : b)

int main() {
	int num_of_node;
	map<int, int> tree;
	long long count = 0;
	scanf("%d", &num_of_node);
	for (int i = 0; i < num_of_node; i++) {
		int a, b = -1, c = -1;
		scanf("%d", &a);
		if (i != 0) {
			b = (tree.upper_bound(a) != tree.begin()) ? (--tree.upper_bound(a))->second : 0;
			c = (tree.upper_bound(a) != tree.end()) ? tree.upper_bound(a)->second : 0;
		}
		tree.insert({ a, MAX(b, c) + 1});
		count += MAX(b, c) + 1;
		printf("%lld\n", count);
	}
	return 0;
}
#endif