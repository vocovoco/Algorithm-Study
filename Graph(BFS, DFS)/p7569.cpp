#if 1
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int box[101][101][101];
	int width, height, floor;
	queue<vector<int>> q[2];
	scanf("%d %d %d", &width, &height, &floor);

	for (int i = 1; i <= floor; i++) {
		for (int j = 1; j <= height; j++) {
			for (int k = 1; k <= width; k++) {
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1) {
					vector<int> temp = { i, j, k };
					q[1].push(temp);
				}
			}
		}
	}

	int flag = 1;
	int count = 0;
	while (flag) {
		count++;
		flag = 0;
		while (!q[count % 2].empty()) {
			int i = q[count % 2].front()[0];
			int j = q[count % 2].front()[1];
			int k = q[count % 2].front()[2];
			if (i > 1 && box[i - 1][j][k] == 0) {
				vector<int> temp = { i - 1, j, k };
				box[i - 1][j][k] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			if (i < floor && box[i + 1][j][k] == 0) {
				vector<int> temp = { i + 1, j, k };
				box[i + 1][j][k] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			if (j > 1 && box[i][j - 1][k] == 0) {
				vector<int> temp = { i, j - 1, k };
				box[i][j - 1][k] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			if (j < height && box[i][j + 1][k] == 0) {
				vector<int> temp = { i, j + 1, k };
				box[i][j + 1][k] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			if (k > 1 && box[i][j][k - 1] == 0) {
				vector<int> temp = { i, j, k - 1 };
				box[i][j][k - 1] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			if (k < width && box[i][j][k + 1] == 0) {
				vector<int> temp = { i, j, k + 1 };
				box[i][j][k + 1] = 1;
				q[(count + 1) % 2].push(temp);
				flag = 1;
			}
			q[count % 2].pop();
		}
	}
	for (int i = 1; i <= floor; i++) {
		for (int j = 1; j <= height; j++) {
			for (int k = 1; k <= width; k++) {
				if (box[i][j][k] == 0) {
					count = 0;
					break;
				}
			}
		}
	}
	printf("%d", count - 1);
	return 0;
}
#endif