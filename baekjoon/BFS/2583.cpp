#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

int board[103][103]; // 그림 그릴 곳
int dist[103][103]; // 방문 여부 판정
vector <int> ans; // 넓이를 오름차순으로 출력하기 위한 벡터
int cnt = 0; // 그림이 없는 영역의 개수를 센다

int dx[4] = { 0,0,-1,1 }; //방향 배열
int dy[4] = { -1,1,0,0 };

int main() {
	int m, n, k; //mxn 도화지, k개의 직사각형
	cin >> m >> n >> k;
	// 직사각형을 제외한 부분의 분리된 영역의 개수
	// 제외한 부분의 넓이를 출력

	for (int i = 0; i < k; i++) { // k개의 입력받기
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;
		for (int x = m-1-starty; x > m-1-endy; x--) {
			for (int y = startx; y < endx; y++) {
				board[x][y] = 1; // 그림 그리기
			}
		}
	}

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == 1 || dist[x][y] == 1) continue; //그림이 그려진 곳이거나
			// 이미 방문한 곳이면 제외
			queue<pair<int, int>> Q;
			dist[x][y] = 1; // 방문표시
			Q.push({ x,y }); //큐에 담기
			int width = 1; //넓이 세기
			cnt++; // 그림이 없는 영역의 개수세기 
			while (!Q.empty()) { //bfs
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; //범위 벗어나는지 체크
					if (board[nx][ny] != 0) continue; // 그림이 있는 곳이면 무시
					if (dist[nx][ny] == 1) continue; // 이미 방문한곳이면 무시
					Q.push({ nx,ny });
					dist[nx][ny] = 1;
					width++; // 넓이 세기 
				}
			}
			ans.push_back(width); // 벡터에 넓이 넣기
		}
	}
	sort(ans.begin(), ans.end()); //벡터 오름차순 정렬 
	cout << cnt << "\n"; //개수 출력
	for (int i : ans)
		cout << i << " "; // 넓이 출력


	return 0;
}