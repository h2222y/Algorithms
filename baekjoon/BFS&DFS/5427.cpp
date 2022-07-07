#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

int map[1003][1003];
int visfire[1003][1003];
int visSang[1003][1003];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string str[1003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // 테케 수 입력
	for (int tc = 0; tc < T; tc++)
	{
		bool escape = false; // 탈출 성공했는지 여부 확인
		int w, h;
		cin >> w >> h; //넓이와 높이 입력
		for (int i = 0; i < h; i++) { //높이별 불과 상근이의 방문 여부 초기화 (테케마다 초기화해줌)
			fill(visfire[i], visfire[i] + w, 0);
			fill(visSang[i], visSang[i] + w, 0);

		}
		queue<pair<int, int>> fireQ; //불 큐
		queue<pair<int, int>> SangQ; //상근이 큐
		for (int i = 0; i < h; i++) {
			cin >> str[i];
		} //문자열로 입력받음

		for (int x = 0; x < h; x++) {
			for (int y = 0; y < w; y++) {
				if (str[x][y] == '*') { //불 시작점 넣기
					fireQ.push({ x,y });
					visfire[x][y] = 1;
				}
				else if (str[x][y] == '@') { // 상근이 시작점 넣기
					SangQ.push({ x,y });
					visSang[x][y] = 1;
				}
				else if (str[x][y] == '#') { //벽일때 -1 넣기
					map[x][y] = -1;
				}
				else map[x][y] = 0; //다른 경우 0 넣기
			}
		}
		while (!fireQ.empty()) { // 불 bfs
			auto cur = fireQ.front();
			fireQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; //범위 벗어나면 불가능
				if (map[nx][ny]==-1) continue; // 벽일 경우 통과 못함
				if (visfire[nx][ny]!=0) continue; // visfire이 0인 경우에만 이동 가능
				visfire[nx][ny] = visfire[cur.X][cur.Y] + 1;
				fireQ.push({ nx,ny });
			}
		}

		while (!SangQ.empty() && !escape) { //상근이 bfs Q가 비지 않았을때와 통과하지 못한 동안
			auto cur = SangQ.front();
			SangQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) { //범위를 벗어나면 통과성공
					cout << visSang[cur.X][cur.Y] << "\n"; //통과할때 시간 출력
					escape = true; // bfs 탈출
					break;
				}
				if (map[nx][ny] == -1)continue; // 벽인경우 통과못함
				if (visSang[nx][ny] != 0) continue; // visSang이 0인 경우만 가능
				if (visfire[nx][ny] != 0 && visfire[nx][ny] <= visSang[cur.X][cur.Y]+1) continue; //불이 먼저 도착한경우나 같이 도착하면 불가능 
				visSang[nx][ny] = visSang[cur.X][cur.Y] + 1;
				SangQ.push({ nx,ny });
			}
		}
		if (!escape) cout << "IMPOSSIBLE\n"; //통과하지 못하면 impossible 출력
	}

		return 0;
}