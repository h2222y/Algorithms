#include <iostream>
using namespace std;

int MAP[10][10];
int n;
int dy[4] = { 0,+1,0,-1 }; // y ����迭 (�ð����)
int dx[4] = { +1,0,-1,0 }; // x ����迭 (�ð����)

int isTurn(int ny, int nx) {
	if (ny < 0 || nx < 0 || ny >= n || nx >= n) return 1; // ���ƾ��ϴ� ��� 1
	if (MAP[ny][nx] != 0) return 1; //���ƾ� �ϴ� ��� 2
	return 0;
}

int main() {
	int tc, T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int y = 0; y < 10; y++) {
			fill(MAP[y], MAP[y] + 10, 0);
		}

		int dir = 0;// 0 1 2 3 0 1 2 3 ... �ݺ� ����迭�� index

		int y = 0;
		int x = -1; //�ʱⰪ �� ó�� ���� �̵��̹Ƿ� x�� -1�־�� �� 

		for (int i = 1; i <= n * n; i++) { // ���� ä�� ��
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isTurn(ny, nx)) { //���ƾ� �Ѵٸ�?
				dir = (dir + 1) % 4; // ���� �迭�� �ε����� �ٲ��ָ� �ȴ�!
			}
			// ���� �ʾƵ� �Ǹ�?

			y += dy[dir]; // y�� �̵�
			x += dx[dir]; // x�� �̵�

			MAP[y][x] = i; //���� ä��
		}
		cout << "#" << tc << endl;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cout << MAP[y][x] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}