#if 0
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MIN(a, b) (a < b) ? a : b;
#define INF 1000000000
using namespace std;

int dp[100001][18] = { 0, };
vector<int> vertex[100001];

int dfs(int index, int parent, int cost_of_parent) {
	int min = INF;
	for (int i = 1; i < 18; i++) {
		if (i == cost_of_parent) continue;
		int sum = i;
		for (int j = 0; j < vertex[index].size(); j++) {
			if (vertex[index][j] == parent) continue;
			if (dp[vertex[index][j]][i] == 0) {
				dp[vertex[index][j]][i] = dfs(vertex[index][j], index, i);
			}
			sum += dp[vertex[index][j]][i];
		}
		min = MIN(sum, min);
	}
	return min;
}
int main() {
	int num_of_vertex;	
	scanf("%d", &num_of_vertex);

	for (int i = 0; i < num_of_vertex - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}

	printf("%d", dfs(1, 0, 0));
	return 0;
}
#endif