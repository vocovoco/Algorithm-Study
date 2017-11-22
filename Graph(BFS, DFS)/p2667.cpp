#if 1
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int map[26][26] = { 0, };
int visit[26][26] = { 0, };
vector<int> groups;

void dfs(int i, int j, int width, int group) {
	visit[i][j] = 1;
	if (i > 1 && map[i - 1][j] == 1 && visit[i - 1][j] == 0) {
		groups[group]++;
		dfs(i - 1, j, width, group);
	}
	if (i < width && map[i + 1][j] == 1 && visit[i + 1][j] == 0) {
		groups[group]++;
		dfs(i + 1, j, width, group);
	}
	if (j > 1 && map[i][j - 1] == 1 && visit[i][j - 1] == 0) {
		groups[group]++;
		dfs(i, j - 1, width, group);
	}
	if (j < width && map[i][j + 1] == 1 && visit[i][j + 1] == 0) {
		groups[group]++;
		dfs(i, j + 1, width, group);
	}
}
int main() {
	int num_of_group = 0;
	int width;
	queue<pair<int, int>> q;
	scanf("%d", &width);

	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= width; j++) {
			char a;
			scanf(" %c", &a);
			map[i][j] = a - 48;
			if (map[i][j] == 1) q.push({ i, j });
		}
	}

	while (!q.empty()) {
		if (visit[q.front().first][q.front().second] == 1) { q.pop(); continue; }
		num_of_group++;
		groups.push_back(1);
		dfs(q.front().first, q.front().second, width, num_of_group - 1);
	}

	printf("%d\n", num_of_group);
	sort(groups.begin(), groups.end());
	for (int i = 0; i < num_of_group; i++) {
		printf("%d\n", groups[i]);
	}
	return 0;
}
#endif