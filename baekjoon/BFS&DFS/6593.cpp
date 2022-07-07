#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;


char board[33][33][33]; // 건물의 구조 입력받기
int vis[33][33][33]; // 최단 거리 구하기
int dx[6] = { -1,1,0,0,0,0 }; // 방향배열 상,하,좌,우,위,아래
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		bool escape = false; // 탈출 성공, 실패를 결정
		int l, r, c;
		cin >> l >> r >> c; // 층수, 행, 열 입력받기
		queue<tuple<int, int, int>> Q; // bfs
		if (l == 0 && r == 0 && c == 0) return 0; // 0,0,0 입력시 종료 
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') { // 시작점일 경우
						Q.push({ i,j,k }); // 큐에 담고
						vis[i][j][k] = 0; // vis 0으로 
					} 
					else if (board[i][j][k] == '.') { // 갈 수 있는 곳일경우 
						vis[i][j][k] = -1; // -1으로 
					}
				}
			}
		}
		while (!Q.empty() && !escape) {
			tuple<int, int, int> cur = Q.front();
			Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int i = 0; i < 6; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				int nz = curZ + dz[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)continue; // 범위 체크
				if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0) continue; // 벽이면 갈 수 없고 0, -1만 갈 수 있는 길 
				vis[nz][nx][ny] = vis[curZ][curX][curY] + 1; // 경로 표시
				if (board[nz][nx][ny] == 'E') { // 탈출구 발견하면 탈출 성공 
					cout << "Escaped in " << vis[nz][nx][ny] << " minute(s).\n"; // 해당 vis값 출력
					escape = true; // 탈출 성공시 반복 종료 
					break;
				}
				Q.push({ nz,nx,ny });

			}
		}

		if (!escape) cout << "Trapped!\n"; // 탈출 실패시 Trapped! 출력

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) { // 다음 입력을 위해 vis 배열 초기화
				fill(vis[i][j], vis[i][j] + c, 0);
			}
		}

	}

	return 0;
}