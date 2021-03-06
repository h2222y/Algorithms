#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second
// 적록색약 빨강과, 초록의 차이를 거의 느끼지 못한다
// // 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하자
// NxN에 R,G,B 중 하나를 색칠한 그림
// 그림은 몇 개의 구역으로 나누어져 구역은 같은 색으로 이루어져 있다
// 같은 색상이 상하좌우로 인정해 있는 경우에 두 글자는 같은 구역에 속한다

string paper[102];
int vis[102][102];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;
string str;

void bfs(int x,int y) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || paper[x][y] != paper[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}

}

int area() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; //n<=100
	for (int i = 0; i < n;i++) {
		cin >> str;
		paper[i] = str;
	}

	int not_p = area();

	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, 0);
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (paper[x][y] == 'R') {
				paper[x][y] = 'G';
			}
		}
	}

	int p = area();
	cout << not_p << " " << p;
	return 0;
	
}