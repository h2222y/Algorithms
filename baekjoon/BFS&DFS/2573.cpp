#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int ice[302][302];
int vis[302][302];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int subin, m;

int status() {
	int x = -1, y = -1;
	int cnt = 0; // 빙산 한 덩이의 개수 
	for (int i = 0; i < subin; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0)continue; //바다면 무시 
			x = i; // 빙산이 존재하면 x,y 값에 대입
			y = j;
			cnt++; // 빙산 한 덩이의 조각 개수
		}
	}
	if (cnt == 0) return 0; // 빙산이 존재하지 않는다면 0 반환
	int cnt2 = 0; // 빙산이 한 덩이인지 두 덩이인지 확인하기 위한 cnt변수
	queue<pair<int, int>> Q;
	vis[x][y] = 1;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		cnt2++; // 이어진 빙산의 조각 개수를 셈
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= subin || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || ice[nx][ny] <= 0) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	if (cnt == cnt2) return 1; //이어진 조각 개수와 전체 조각 개수가 같다면, 빙산이 아직 한 덩이라는 의미
	return 2; // 위의 두 경우가 아니라면 빙산이 분리된 것 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin >> m;
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < m; y++) {
			cin >> ice[x][y]; //빙산 높이 입력받기
		}
	}
	int year = 0; // 몇 년 걸렸는지가 정답
	while (1) {
		for (int x = 0; x < subin; x++) { 
			for (int y = 0; y < m; y++) {
				if (ice[x][y] == 0) continue; // 바다면 무시 
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= m) continue;
					if (ice[nx][ny] != 0) continue; //바다가 아니면 무시 
					vis[x][y]++; // 바다가 아닌 곳의 방문 배열을 증가시킴 
				}
			}
		}
		for (int x = 0; x < subin; x++) {
			for (int y = 0; y < m; y++) {
				ice[x][y] = max(0, ice[x][y] - vis[x][y]); // 해당 빙산의 높이에서 방문한 만큼을 빼주면
				// 일년에 줄어든 높이를 계산할 수 있음
			}
		}
		year++; // 높이를 줄였으니 1년을 더해줌 
		for (int x = 0; x < subin; x++) {
			fill(vis[x], vis[x] + m, 0); //vis 배열을 다시 초기화
		}
		int check = status(); //상태 확인 함수, 빙산이 두 덩이 이상으로 분리되었는지 확인 

		for (int x = 0; x < subin; x++) {
			fill(vis[x], vis[x] + m, 0);
		}
		if (check == 0) {
			cout << 0;
			return 0;
		}
		else if (check == 1) continue;
		else break; //빙산이 분리되었을 경우 반복문 종료 
	}
	cout << year; // 몇 년 소요되었는지 출력
	return 0;
}