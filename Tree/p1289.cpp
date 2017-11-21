#if 1
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vertex[100001];
int path_weight = 0;

int dfs(int index, int parent) {
	int temp = 0, sum = 1;
	for (int i = 0; i < vertex[index].size(); i++) {
		if (vertex[index][i].first == parent) continue;
		temp = (long long)dfs(vertex[index][i].first, index) * vertex[index][i].second % 1000000007;
		path_weight = (path_weight + (long long)temp * sum) % 1000000007;
		sum = (sum + temp) % 1000000007;
	}
	return sum;
}
int main() {
	int num_of_vertex;
	
	scanf("%d", &num_of_vertex);

	for (int i = 0; i < num_of_vertex - 1; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		vertex[a].push_back(pair<int, int>(b, w));
		vertex[b].push_back(pair<int, int>(a, w));
	}
	
	dfs(1, 0);
	printf("%d", path_weight);
	return 0;
}
#endif