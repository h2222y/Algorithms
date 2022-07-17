#include <iostream>
#include <queue>
using namespace std;

int board[1000003];
int vis[1000003];
const int NOT_VISITED = 0; // 방문한 학생
const int CYCLE_IN = -1; //싸이클에 포함된 학생

void check(int x) {
	int cur = x;
	while (1) {
		vis[cur] = x;
		cur = board[cur];
		// 이번 방문에서 이미 팀이 꾸려진 학생에 도달했을경우
		if (vis[cur] == x) {
			while (vis[cur] != CYCLE_IN) {
				vis[cur] = CYCLE_IN;
				cur = board[cur];
			}
			return;
		}
		// 이전 방문에서 이미 팀이 꾸려진 학생에 도달했을 경우
		else if (vis[cur] != 0) return;
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		fill(vis, vis + 1000000, 0);
		for (int x = 1; x <= n; x++) {
			cin >> board[x];
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == NOT_VISITED) check(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != CYCLE_IN) cnt++;
		}
		cout << cnt << "\n";
	}
}