#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

string map[1001];
int vis1[1001][1001]; // 불의 전파 시간
int vis2[1001][1001]; // 지훈이의 이동 시간 

int dx[4] = { 0,0,-1,1 }; // 방향 배열
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c; // 배열의 행,열 입력받음
	for (int i = 0; i < r; i++) {
		fill(vis1[i], vis1[i] + c, -1); // 불의 전파 시간 배열 -1로 초기화
		fill(vis2[i], vis2[i] + c, -1); // 지훈이의 이동 시간 배열 -1로 초기화 
	}
	for (int x = 0; x < r; x++) {
		cin >> map[x]; //string으로 입력 받은 값 넣기
	}
	queue<pair<int, int>> Q1; // 불 bfs queue
	queue<pair<int, int>> Q2; // 지훈이 bfs queue
	// # 벽, . 지나갈 수 있는 공간, J 지훈이의 미로에서의 초기위치(지나갈 수 있는 공간)
	// F 불이 난 공간
	// 지훈이와 불은 매 분마다 한 칸씩 수평 또는 수직으로 이동한다
	// 지훈이는 벽과 불이 있는 공간을 통과하지 못한다.
	// 시작점이 두개(지훈이의 이동, 불의 이동)
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (map[x][y] == 'F') { // 불의 시작점 넣기
				Q1.push({ x,y });
				vis1[x][y] = 0;
			}
			if (map[x][y] == 'J') {
				Q2.push({ x,y }); // 지훈이의 시작점 넣기
				vis2[x][y] = 0;
			}
		}
	}
	// 불 bfs
	while (!Q1.empty()) {
		pair<int, int> cur = Q1.front();
		Q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (vis1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	// 지훈이 bfs
	while (!Q2.empty()) {
		pair<int, int> cur = Q2.front();
		Q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i]; 
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // 처음 범위를 벗어났다는 것은 탈출에 성공했다는 의미이다
				cout << vis2[cur.X][cur.Y] + 1; //현재 위치에서 +1을 해준다
				return 0; //탈출 성공시 바로 종료  
			}
			if (vis2[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1) continue; // 불의 방문한 곳이나 불이 방문한 시간이 지훈이가 방문할 시간보다 앞서거나 같으면 안된다 
			vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}