#if 0
#include <stdio.h>
#include <queue>

using namespace std;

char map[100][100];
int dp[100][100] = { 0, };
int row, col;
int dx, dy;
queue<pair<int, int>> water;
queue<pair<int, int>> position;

void flood() {
	queue<pair<int, int>> temp;

	while (!water.empty()){
		int i = water.front().first;
		int j = water.front().second;
		water.pop();

		if (i > 0 && map[i - 1][j] == '.') {
			map[i - 1][j] = '*';
			temp.push({ i - 1, j });
		}
		if (j > 0 && map[i][j - 1] == '.') {
			map[i][j - 1] = '*';
			temp.push({ i, j - 1 });
		}
		if (i < row - 1 && map[i + 1][j] == '.') {
			map[i + 1][j] = '*';
			temp.push({ i + 1, j });
		}
		if (j < col - 1 && map[i][j + 1] == '.') {
			map[i][j + 1] = '*';
			temp.push({ i, j + 1 });
		}
	}
	swap(water ,temp);
}
int move() {
	queue<pair<int, int>> temp;

	while (!position.empty()) {
		int i = position.front().first;
		int j = position.front().second;
		position.pop();

		if (i > 0 && (map[i - 1][j] == '.' || map[i - 1][j] == 'D') && dp[i - 1][j] == 0) {
			dp[i - 1][j] = dp[i][j] + 1;
			temp.push({ i - 1, j });
			if (map[i - 1][j] == 'D') return 1;
		}
		if (j > 0 && (map[i][j - 1] == '.' || map[i][j - 1] == 'D') && dp[i][j - 1] == 0) {
			dp[i][j - 1] = dp[i][j] + 1;
			temp.push({ i, j - 1 });
			if (map[i][j - 1] == 'D') return 1;
		}
		if (i < row - 1 && (map[i + 1][j] == '.' || map[i + 1][j] == 'D') && dp[i + 1][j] == 0) {
			dp[i + 1][j] = dp[i][j] + 1;
			temp.push({ i + 1, j });
			if (map[i + 1][j] == 'D') return 1;
		}
		if (j < col - 1 && (map[i][j + 1] == '.' || map[i][j + 1] == 'D') && dp[i][j + 1] == 0) {
			dp[i][j + 1] = dp[i][j] + 1;
			temp.push({ i, j + 1 });
			if (map[i][j + 1] == 'D') return 1;
		}
	}
	swap(position, temp);
	if (position.empty()) return -1;
	return 0;
}

int main() {
	scanf("%d %d", &row, &col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				position.push({ i, j });
			}
			if (map[i][j] == 'D') {
				dx = i;
				dy = j;
			}
			if (map[i][j] == '*') {
				water.push({ i, j });
			}
		}
	}
	
	while (1) {
		flood();
		int flag = move();
		if (flag == 1) {
			printf("%d", dp[dx][dy]);
			return 0;
		}
		else if (flag == -1) {
			printf("KAKTUS");
			return 0;
		}
	}
	
	return 0;
}
#endif