#include <iostream>
using namespace std;
int n;
char board[2300][2300];

void recur(int n, int x, int y) {
	if (n == 1) {
		board[x][y] = '*'; // n=1이면 좌표에 별 넣고 돌아가기
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)	continue; // 가운데는 공백
			recur(n / 3, x + n / 3 * i, y + n / 3 * j); // n/3으로 나누면서 0,1,2 좌표 보내기
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' '); // 공백으로 값 채워놓기
	recur(n, 0, 0);
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n'; // 출력
	return 0;
}