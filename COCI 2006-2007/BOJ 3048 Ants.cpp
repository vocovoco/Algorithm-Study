#if 0
#include <stdio.h>

int ants1_num, ants2_num, time;
char ants1[51], ants2[51];

int main() {
	scanf("%d %d", &ants1_num, &ants2_num);
	scanf("%s", ants1);
	scanf("%s", ants2);
	scanf("%d", &time);

	for (int i = 50; i--;) {
		if (ants1[i]) putchar(ants1[i]);
		if (time >= i && ants2[time - i]) putchar(ants2[time - i]);
	}
	while (++time < ants2_num) putchar(ants2[time]);
	
	return 0;
}
#endif