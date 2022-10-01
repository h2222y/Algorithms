#include <iostream>
using namespace std;

int MAP[10][10];
int n;
int dy[4] = { 0,+1,0,-1 }; // y 방향배열 (시계방향)
int dx[4] = { +1,0,-1,0 }; // x 방향배열 (시계방향)

int isTurn(int ny, int nx) {
	if (ny < 0 || nx < 0 || ny >= n || nx >= n) return 1; // 돌아야하는 경우 1
	if (MAP[ny][nx] != 0) return 1; //돌아야 하는 경우 2
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

		int dir = 0;// 0 1 2 3 0 1 2 3 ... 반복 방향배열의 index

		int y = 0;
		int x = -1; //초기값 맨 처음 우측 이동이므로 x는 -1주어야 함 

		for (int i = 1; i <= n * n; i++) { // 숫자 채울 것
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isTurn(ny, nx)) { //돌아야 한다면?
				dir = (dir + 1) % 4; // 방향 배열의 인덱스를 바꿔주면 된다!
			}
			// 돌지 않아도 되면?

			y += dy[dir]; // y값 이동
			x += dx[dir]; // x값 이동

			MAP[y][x] = i; //숫자 채움
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