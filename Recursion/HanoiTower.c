#include <stdio.h>

int HanoiTower(int num, char from, char by, char to) {
	if (num == 1) // �̵��� ������ ���� 1����
	{
		printf("���� 1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		HanoiTower(num - 1, from, to, by);
		printf("����%d�� %c���� %c�� �̵�\n", num,from, to);
		HanoiTower(num-1, by, from, to);
	}
}
int main() {
	// ���� A, B, C�� �����Ѵٰ� �Ҷ�, ���� A�� n-1���� ������ B�� �����Ͽ�,
	// ���� C�� �ű��.
	HanoiTower(3, 'A', 'B', 'C');
	return 0;
}