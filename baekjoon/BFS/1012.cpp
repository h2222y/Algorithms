#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
//유기농 배추

// 지렁이는 배추근처에서 서식하며 해충을 잡아먹어 보호
// 흰 지렁이 한마리라도 살면 인접한 다른 배추로 이동 가능 상 하 좌 우

// 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다
// 배추 심어져있는땅 1, 배추 없는 땅 0 

int dx[4] = { 0,0,-1,1 }; // 방향배열
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> Q; // 시작 위치 담을 큐

int map[51][51];// 배추 그릴 map
int vis[51][51]; // 방문 여부 체크

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // 테케 수 입력
	for (int tc = 1; tc <= T; tc++) {
		int m, n;
		cin >> m >> n; // 행, 열 <=50
		int k;
		cin >> k; // 배추가 심어져 있는 위치의 개수 <=2500
		

		for (int i = 0; i < k; i++) {
			int x, y; // 배추의 위치
			cin >> x >> y; //위치 입력받기
			map[x][y] = 1; //해당 위치에 1 표시
		}

		int cnt = 0; // 연속하지 않은 위치의 개수를 셀 것 

		for (int x = 0; x < m; x++) { // 행, 열을 돌면서
			for (int y = 0; y < n; y++) {
				if (map[x][y] == 1 && vis[x][y] != 1) { // 배추가 심어져있고, 방문하지 않은 곳이면 
					vis[x][y] = 1;// 방문 체크
					Q.push({ x,y }); // 큐에 해당 x,y값 담기
					while (!Q.empty()) { // bfs
						pair<int, int> cur = Q.front();
						Q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = cur.X + dx[i];
							int ny = cur.Y + dy[i];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] == 1 || map[nx][ny] == 0) continue;
							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
					cnt++;
				}
			}
		}

		cout << cnt << endl;
		for (int i = 0; i < m; i++) {
			fill(map[i], map[i] + n, 0);
			fill(vis[i], vis[i] + n, 0);
		} // 다음 테케를 위한 초기화
	}

	return 0;
}