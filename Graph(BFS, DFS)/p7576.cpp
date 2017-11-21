#if 1
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int box[1001][1001];
	int width, height;
	queue<pair<int, int>> q[2];
	scanf("%d %d", &width, &height);

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) q[1].push({ i, j });
		}
	}

	int flag = 1;
	int count = 0;
	while (flag) {
		count++;
		flag = 0;
		while (!q[count % 2].empty()) {
			int i = q[count % 2].front().first;
			int j = q[count % 2].front().second;
			if (i > 1 && box[i - 1][j] == 0) {
				box[i - 1][j] = 1;
				q[(count + 1) % 2].push({ i - 1, j });
				flag = 1;
			}
			if (i < height && box[i + 1][j] == 0) {
				box[i + 1][j] = 1;
				q[(count + 1) % 2].push({ i + 1, j });
				flag = 1;
			}
			if (j > 1 && box[i][j - 1] == 0) {
				box[i][j - 1] = 1;
				q[(count + 1) % 2].push({ i, j - 1 });
				flag = 1;
			}
			if (j < width && box[i][j + 1] == 0) {
				box[i][j + 1] = 1;
				q[(count + 1) % 2].push({ i, j + 1 });
				flag = 1;
			}
			q[count % 2].pop();
		}
	}
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (box[i][j] == 0) {
				count = 0;
				break;
			}
		}
	}
	printf("%d", count - 1);
	return 0;
}
#endif