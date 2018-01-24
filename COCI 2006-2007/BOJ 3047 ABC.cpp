#if 0
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int num[3];
	char seq[4];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	scanf("%s", seq);
	
	sort(num, num + 3);

	printf("%d %d %d", num[seq[0] - 65], num[seq[1] - 65], num[seq[2] - 65]);
	return 0;
}
#endif