#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[103][103]; //건물의 높이 표시하기
int vis[103][103]; // 잠기는 여부 표시하기 
int dx[4] = { 0,0,-1,1 }; //방향 배열
int dy[4] = { -1,1,0,0 };
int main() {
	int n;
	cin >> n; // 배열 크기 입력
	int maxheight = 0; // 건물의 최대값 구하기 
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y]; // 건물의 높이 입력받기
			if (board[x][y] > maxheight) {
				maxheight = board[x][y]; // 최대값 구하기
			}
		}
	}
	int mx = 0; // 범위의 최대 개수
	for (int i = 0; i <= maxheight; i++) { //0부터 최대 높이까지 하나씩 영역을 다 구해본다
		int cnt = 0; // 영역을 셀 것
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] <= i) vis[x][y] = -1; //건물이 잠겨있으면 -1 표시하기(i=0일때부터 i=최대높이까지) 
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (vis[x][y]!=0) continue; // 0이 아니라면 queue에 담지 않을 것임
				queue<pair<int, int>> Q;
				Q.push({ x,y });
				vis[x][y] = 1; //queue에 담아서 방문함을 체크
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue; //범위 벗어나는지 체크
						if (board[nx][ny] <= i || vis[nx][ny] == 1)continue; // 이미 잠겨있거나 방문했으면 제외
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
				cnt++; //영역의 개수 세기
			}
		}
		mx = max(mx, cnt); //영역의 개수 최대값 찾기
		for (int x = 0; x < n; x++) {
			fill(vis[x], vis[x] + n, 0); // 다음 i값을 위해 vis배열 초기화 
		}
	}

	cout << mx;


	return 0;
}