#include <stdio.h>

int main() {
	unsigned i;
	int a[3] = {1, 2, 3};
//	int count = 0;
//	i = sizeof(a) / sizeof(int) - 1;
//	while (count < 4) {
//		printf("%u\n", i);
//		i--;
//		count++;
//	}
	for (i = sizeof(a)/sizeof(int) - 1; i >= 0; i--)
		printf("%d\n", a[i]);
	return 0;
}
