#include <stdio.h>
//n 参与环的总人数 m最大报数值
int josephus(int n, int m) {
	if(n == 1) {
		return 0;
	}
	else {
		return (josephus(n-1, m) + m) % n;
	}
}

int main() {
	int n, m;
	while (scanf("%d", &n) == 1) {
		if (!n) {
			break;
		}
		scanf("%d", &m);
		int result = josephus(n, m);
		printf("%d\n", result+1);
	}
	return 0;
}
