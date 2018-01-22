#if 0
#include<stdio.h>

#define pi 3.141592653589793

int main() {
	double u_circle = 0;
	double h_circle = 0;

	int radius;
	scanf("%d", &radius);

	u_circle = radius * radius * pi;
	h_circle = radius * radius * 2;

	printf("%0.6f\n", u_circle);
	printf("%0.6f", h_circle);
	return 0;
}
#endif