#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int dx[8] = { -2,-1,-2,-1,2,1,2,1 };
int dy[8] = { -1,-2,1,2,-1,-2,1,2 };
int map[302][302];
int dist[302][302];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // 테스트 케이스의 개수 입력
	for (int tc = 0; tc < T; tc++) {
		int l; 
		cin >> l; //lxl의 체스판
		for (int x = 0; x < l; x++) { //각 테스트케이스마다 dist와 map값을 초기화
			fill(dist[x], dist[x] + l, 0);
			fill(map[x], map[x] + l, 0);
		}
		int nowx, nowy; // 현재 나이트의 좌표
		cin >> nowx >> nowy;
		int movx, movy; // 나이트의 목적지
		cin >> movx >> movy;
		map[movx][movy] = 2; // 목적지를 2로 표시
		queue<pair<int, int>> Q; // bfs를 위한 queue
		Q.push({ nowx,nowy }); // 현재 좌표를 bfs에 넣기
		dist[nowx][nowy] = 1; // 현재 좌표에 방문했음을 표시 나머지는 0
		int mx = 0;
		while (!Q.empty()) { //bfs
			auto cur = Q.front(); 
			Q.pop();
			for (int i = 0; i < 8; i++) { // 나이트가 한 번에 이동할 수 있는 거리들
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l)continue; // 범위를 벗어나는지 체크
				if (dist[nx][ny] > 0) continue; // 이미 확인한 곳은 무시
				dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 현재좌표에서 다음 좌표로 이동할 때 +1을 해준다.
				Q.push({ nx,ny }); // 큐에 넣기
				if (map[nx][ny] == 2) { //도착지점에 도착하면
					mx = max(mx, dist[nx][ny]-1); // 최소 몇 번은 가야하는지 계산해준다
				} //첫 칸 제외를 위한 -1
			}
		}
		cout << mx << "\n"; // 값 출력
	}
	return 0; 
}