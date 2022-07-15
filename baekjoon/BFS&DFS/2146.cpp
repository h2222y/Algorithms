#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MX =102;
int board[MX][MX]; 
int dist[MX][MX];
int vis[MX][MX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>> Q;
int subin;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin;
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			cin >> board[x][y]; //board에 값 입력받기, 0이면 바다, 1이면 섬
		}
	}
	int cnt = 0; //카운트 변수
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			if (board[x][y] == 0 || vis[x][y]) continue; // 섬이 아니거나 이미 방문한곳이면 무시
			cnt++; //카운트 변수로 몇번 섬인지 board에 표시한다.
			Q.push({ x,y }); //bfs로 섬에 같은 번호를 부여
			vis[x][y] = 1;
			board[x][y] = cnt;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= subin) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					Q.push({ nx,ny });
					board[nx][ny] = cnt;
					vis[nx][ny] = 1;
				}
			} 
		}
	}
	for (int i = 0; i < subin; i++)
		fill(dist[i], dist[i] + subin, -1); //dist배열을 -1로 초기화 
	int ans = 999999; // 가장 짧은 다리를 구할 것

	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			if (board[x][y] == 0) continue; // 바다면 무시
			Q.push({ x,y });
			dist[x][y] = 0;
			bool escape = false; // 다리를 모두 놓았을 때 반복문 탈출을 위한 변수 
			while (!Q.empty() && !escape) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= subin)continue; // 범위를 벗어날 경우 
					if (dist[nx][ny] >= 0 || board[nx][ny] == board[x][y]) continue; // 이미 방문했거나, 같은 섬일 경우
					if (board[nx][ny] != 0 && board[nx][ny] != board[x][y]) { // 바다가 아니고, 같은 섬이 아닐 경우
						ans = min(ans, dist[cur.first][cur.second]); // 다리의 최소값을 저장하고
						while (!Q.empty())Q.pop(); // 큐에 남은 값을 모두 제거해준다. 
						escape = true; // 탈출 변수를 true로 만들어서 while문과 for문 탈출
						break;
					}
					dist[nx][ny] = dist[cur.first][cur.second] + 1; 
					Q.push({ nx,ny });
				}
			}
			for (int i = 0; i < subin; i++)
				fill(dist[i], dist[i] + subin, -1); // 하나의 섬을 모두 구했으면 dist 배열을 다시 초기화 
		}
	} 
	cout << ans; // 정답 출력
}