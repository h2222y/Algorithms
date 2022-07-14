#include <iostream>
using namespace std;
int n;
char board[2300][2300];

void recur(int n, int x, int y) {
	if (n == 1) {
		board[x][y] = '*'; // n=1�̸� ��ǥ�� �� �ְ� ���ư���
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)	continue; // ����� ����
			recur(n / 3, x + n / 3 * i, y + n / 3 * j); // n/3���� �����鼭 0,1,2 ��ǥ ������
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' '); // �������� �� ä������
	recur(n, 0, 0);
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n'; // ���
	return 0;
}