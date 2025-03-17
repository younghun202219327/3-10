#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void) {

	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {
		int num[10];

		for (int i = 0; i < 10; i++) {
			scanf("%d", &num[i]);
			//printf("%d", num[i]);
		}
		int s = 0;
		for (int i = 0; i < 10; i++) {
			if (num[i] % 2 == 1) {
				s = s + num[i];
			}
		}
		printf("#%d %d\n", test_case, s);
	}
	return 0;
}