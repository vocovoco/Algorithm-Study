#include <stdio.h>
#include <stdlib.h>

typedef struct _point {
	int height;
	int north_count;
	int south_count;
	int west_count;
	int east_count;
	int total_count;
	bool activate;
} point;

int main() {

	int row = 0, col = 0;
	point **ary;

	scanf("%d %d", &row, &col);

	ary = (point**)malloc(row * sizeof(point));
	for (int i = 0; i < row; i++) {
		ary[i] = (point*)malloc(col * sizeof(point));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &ary[i][j].height);
			ary[i][j].activate = false;
			ary[i][j].north_count = 0;
			ary[i][j].south_count = 0;
			ary[i][j].west_count = 0;
			ary[i][j].east_count = 0;
			ary[i][j].total_count = 0;
		}
	}

	ary[row - 1][col - 1].activate = true;
	ary[row - 1][col - 1].total_count = 1;
	int activate_cnt = 1;

	do {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (ary[i][j].activate) {
					if (((j + 1) < col) && (ary[i][j].height < ary[i][j + 1].height)) {
						ary[i][j + 1].west_count = ary[i][j].total_count;
						ary[i][j + 1].total_count = ary[i][j + 1].west_count + ary[i][j + 1].east_count + ary[i][j + 1].north_count + ary[i][j + 1].south_count;
						if (!(ary[i][j + 1].activate)) {
							activate_cnt++;
						}
						ary[i][j + 1].activate = true;
					}
					if (((i + 1) < row) && (ary[i][j].height < ary[i + 1][j].height)) {
						ary[i + 1][j].north_count = ary[i][j].total_count;
						ary[i + 1][j].total_count = ary[i + 1][j].north_count + ary[i + 1][j].south_count + ary[i + 1][j].west_count + ary[i + 1][j].east_count;
						if (!(ary[i + 1][j].activate)) {
							activate_cnt++;
						}
						ary[i + 1][j].activate = true;
					}
					if (((j - 1) >= 0) && (ary[i][j].height < ary[i][j - 1].height)) {
						ary[i][j - 1].east_count = ary[i][j].total_count;
						ary[i][j - 1].total_count = ary[i][j - 1].east_count + ary[i][j - 1].west_count + ary[i][j - 1].north_count + ary[i][j - 1].south_count;
						if (!(ary[i][j - 1].activate)) {
							activate_cnt++;
						}
						ary[i][j - 1].activate = true;
					}
					if (((i - 1) >= 0) && (ary[i][j].height < ary[i - 1][j].height)) {
						ary[i - 1][j].south_count = ary[i][j].total_count;
						ary[i - 1][j].total_count = ary[i - 1][j].south_count + ary[i - 1][j].north_count + ary[i - 1][j].west_count + ary[i - 1][j].east_count;
						if (!(ary[i - 1][j].activate)) {
							activate_cnt++;
						}
						ary[i - 1][j].activate = true;
					}
					ary[i][j].activate = false;
					activate_cnt--;
				}
			}
		}
	} while (activate_cnt != 0);

	printf("%d\n", ary[0][0].total_count);

	return 0;
}