#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[101][101]; // 미로
int n, m;//행,열
int dx[4] = { 1,-1,0,0 }; // 행 방향배열
int dy[4] = { 0,0,-1,1 }; // 열 방향배열
int vis[101][101] = { 0 }; // 방문 체크

int main(void) {
	cin >> n >> m; //행 열 입력받기
	for (int i = 0; i < n; i++) {
		string str; //문자열로 입력받아서
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0'; //숫자로 변환해서 배열에 넣어줌
		}
	}
	queue<pair<int, int>> Q;
	vis[0][0] = 1; //맨 첫 칸을 1로 두고
	Q.push({ 0,0 }); // Q에 첫 칸을 넣어준다
	while (!Q.empty()) { // 큐가 안비어있을 동안만 반복
		pair<int, int> cur = Q.front(); //큐에서 빼서 처리해줄 위치 저장해놓고
		Q.pop(); //큐에서 front 값을 뺌
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; //위치에서 상하좌우 체크
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위 벗어날시 무시
			if (vis[nx][ny] != 0 || board[nx][ny]!=1 ) continue; // 방문한 적이 있거나 board의 값이 1이 아니면 갈 수 없음
			vis[nx][ny] = vis[cur.X][cur.Y]+1; //vis의 다음 값을 현재값에서 1더한값으로 업데이트 해준다.
			Q.push({ nx,ny }); //큐에는 다음 좌표를 넣어줌
		}
	}
	cout << vis[n-1][m-1]; //n,m은 크기니까 n-1, m-1번째 요소의 값을 출력하면 된다.
	return 0;
}