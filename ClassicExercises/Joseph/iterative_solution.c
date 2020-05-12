#include <stdio.h>
int main() {
	int n, m, i, result;
	while (scanf("%d", &n) == 1) {
		if (!n) {
			break;
		}
		scanf("%d", &m);
		result = 0;
		for (i = 2; i <= n; i++) {
			result = (result + m) % i;
		}
		printf("%d\n", result + 1);
	}
	return 0;
}
