#include <iostream>
#include <queue>
#include <utility>
using namespace std;
//그림
 
#define X first // pair의 first 값 대신 사용
#define Y second //pair의 second 값 대신 사용 
int n, m; // n 세로크기(행)<=500, m 가로크기(열)<=500
int board[501][501]; // 도화지
bool vis[501][501] = { 0 }; // 방문 여부를 체크
int dx[4] = { 1,-1,0,0 }; //x 방향배열 -행 
int dy[4] = { 0,0,-1,1 }; // y 방향배열 -열

int main(void) {
	cin >> n >> m; //행, 열 입력받음
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> board[x][y]; // board에 그림 그리기
		}
	}
	int mx = 0; //그림의 최대 크기 값
	int num = 0; //그림의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue; //board가 0이거나 이미 방문한 곳이면 무시
			num++; // 그림의 개수 카운트
			queue<pair<int, int>> Q; // 큐에는 방문한 노드를 넣을 예정
			vis[i][j] = 1; //i,j를 만족하는 값에 방문 표시
			int area = 0;
			Q.push({ i,j }); // 방문한 노드를 큐에 삽입
			while (!Q.empty()) {
				area++; // 각 떨어진 노드별 그림의 크기를 구하기 위해 area++
				// area의 최대값을 구하면 가장 큰 그림의 크기를 알 수 있다.
				pair<int, int>cur = Q.front(); // cur에 큐의 front값 저장
				Q.pop(); // Q에서 값 빼내기
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir]; //해당 위치부터 상하좌우 값 확인
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 벗어나는지 확인
					if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // 방문했거나 0이면 무시
					vis[nx][ny] = 1; //나머지 경우 방문 표시를 해주고
					Q.push({ nx,ny }); //큐에 해당 값을 넣어준다. 
				}
			}
			mx = max(mx, area); //area는 각 각의 그림의 크기이므로 가장 큰 그림을 구해준다. 
		}
	}
	cout << num << '\n' << mx; //그림의 수와 크기 출력

	return 0;
}