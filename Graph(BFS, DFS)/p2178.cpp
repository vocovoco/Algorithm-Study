#if 1
#include <stdio.h>
#include <queue>

#define MIN(a, b) (a < b) ? a : b;
#define INF 1000000000
using namespace std;

int main() {
	int maze[101][101];
	int dist[101][101];
	int width, height;
	queue<pair<int, int>> q;
	scanf("%d %d", &height, &width);

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			char a;
			scanf(" %c", &a);
			maze[i][j] = a - 48;
			dist[i][j] = INF;
		}
	}
	
	q.push({ height, width });
	dist[height][width] = 1;
	maze[height][width] = 0;

	int max = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		if (i > 1 && maze[i - 1][j] == 1) {
			dist[i - 1][j] = MIN(dist[i - 1][j], dist[i][j] + 1);
			maze[i - 1][j] = 0;
			q.push({ i - 1, j });
		}
		if (i < height && maze[i + 1][j] == 1) {
			dist[i + 1][j] = MIN(dist[i + 1][j], dist[i][j] + 1);
			maze[i + 1][j] = 0;
			q.push({ i + 1, j });
		}
		if (j > 1 && maze[i][j - 1] == 1) {
			dist[i][j - 1] = MIN(dist[i][j - 1], dist[i][j] + 1);
			maze[i][j - 1] = 0;
			q.push({ i, j - 1 });
		}
		if (j < width && maze[i][j + 1] == 1) {
			dist[i][j + 1] = MIN(dist[i][j + 1], dist[i][j] + 1);
			maze[i][j + 1] = 0;
			q.push({ i, j + 1 });
		}
		q.pop();
	}
	
	printf("%d", dist[1][1]);
	return 0;
}
#endif