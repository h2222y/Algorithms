#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int board[103][103][103]; // 토마토를 표시할 공간
int dist[103][103][103]; // 방문 여부를 표시할 공간
int dx[6] = { 0,0,0,0,-1,1 };//위,아래,왼쪽,오른쪽,앞쪽,뒤쪽
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };
queue<tuple<int, int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
    cin >> m >> n >> h; // 세로, 가로, 높이 
    for (int i = 0; i < h; i++) { //높이
        for (int j = 0; j < n; j++) { // 행 
            for (int k = 0; k < m; k++) { // 열
                int tmp;
                cin >> tmp; // 임시변수에 입력받아 값 확인 
                board[j][k][i] = tmp;
                if (tmp == 1) Q.push({ j, k, i }); // 익은 토마토의 경우 queue에 담는다. 
                if (tmp == 0) dist[j][k][i] = -1; // 익지 않은 토마토는 dist 배열에 -1을 담는다.
            }
        }
    }
    while (!Q.empty()) { //bfs
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int curX, curY, curZ; //tuple을 사용한다. 
        tie(curX, curY, curZ) = cur; // std::tie는 개별 변수들을 tuple처럼 만들어서 tuple의 각 위치의 값을 가져온다.
        for (int i = 0; i < 6; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({ nx,ny,nz });
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[j][k][i] == -1) {
                    cout << -1; //익지 않은 토마토가 하나라도 존재할 경우 -1을 출력하고 종료한다. 
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans << '\n'; // 최소 날짜를 출력한다.
    return 0;
}