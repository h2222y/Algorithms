#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
int dist[1000][1000][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int n, m;

int bfs() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dist[i][j][0] = dist[i][j][1] = -1; // 벽을 부수지 않는 경우와 부수는 경우의 dist배열에 모두 -1 대입
	dist[0][0][0] = dist[0][0][1] = 1; // 각 시작 좌표에는 1 대입
	queue<tuple<int, int, int>> q; // 시작점을 담을 queue
	q.push({ 0,0,0 }); // 0,0,0을 큐에 담음(벽을 부수지 않는 경우의 0,0 좌표)
	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == n - 1 && y == m - 1) return dist[x][y][broken]; // 최종 좌표의 값 return 
		q.pop(); 
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나는 경우
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) { // 이동할 수 있고 아직 방문하지 않았을 때(broken==1)
				dist[nx][ny][broken] = dist[x][y][broken] + 1; // 거리 +1
				q.push({ nx, ny, broken }); // 시작점 큐에 다시 넣기
			}
			// (nx, ny)를 부수는 경우
			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { // broken이 0일때만 접근가능, 즉 부서진 적이 없을때만 접근 가능
				// 부서진 적이 없을 때 board[nx][ny]는 1이고, broken 배열에서 이동한 적이 없을 때 
				dist[nx][ny][1] = dist[x][y][broken] + 1; // dist[x][y][0]에 1 추가
				q.push({ nx, ny, 1 }); // 큐에 값 넣기 broken을 1로 변경시켜주면서 이 조건에 다시 들어올 일 없다
			}
		}
	}
	return -1; // 전부 해당되지 않으면 -1을 return 한다. 
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	cout << bfs();
	return 0;
}