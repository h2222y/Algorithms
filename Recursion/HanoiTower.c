#include <stdio.h>

int HanoiTower(int num, char from, char by, char to) {
	if (num == 1) // 이동할 원반의 수가 1개면
	{
		printf("원반 1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		HanoiTower(num - 1, from, to, by);
		printf("원반%d를 %c에서 %c로 이동\n", num,from, to);
		HanoiTower(num-1, by, from, to);
	}
}
int main() {
	// 막대 A, B, C가 존재한다고 할때, 막대 A의 n-1개의 원반을 B를 경유하여,
	// 막대 C로 옮기기.
	HanoiTower(3, 'A', 'B', 'C');
	return 0;
}