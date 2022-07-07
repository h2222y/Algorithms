#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int map[27][27]; // 지도에 집 표시
int vis[27][27]; // 각 집의 단지 표시 
string str[27]; // 입력 한 줄로 받기 위한 string 
int dx[4] = { 0,0,-1,1 }; // 방향 배열 
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // 지도의 넓이 입력받음 nxn
	for (int x = 0; x < n; x++) {
		cin >> str[x];
		for (int y = 0; y < n; y++) {
			map[x][y] = str[x][y] - '0'; //지도에 집 표시 
		}
	}
	int t = 1; //단지에 번호 붙이기
	vector<int> ans; // 오름차순으로 단지 수 출력하기 위한 벡터
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 0 || vis[x][y] !=0)continue; // 단지가 없거나 이미 방문한 곳은 제외
			queue<pair<int, int>> Q; //bfs
			Q.push({ x,y });
			vis[x][y] = t;
			int cnt = 1; // 단지 수 세기
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue; // 범위 벗어나는지 체크
					if (vis[nx][ny] != 0) continue; // 이미 방문한 곳은 제외
					if (map[nx][ny] != 1) continue; // 단지가 아닌 곳은 제외 
					Q.push({ nx,ny });
					vis[nx][ny] = t;
					cnt++;
				}
			}
			t++;
			ans.push_back(cnt); // 단지 수 출력을 위해 벡터에 값 넣기
		}
	}
	sort(ans.begin(), ans.end()); // 오름차순 정렬
	cout << t-1 << "\n"; //마지막에 t가 증가했기 때문에 -1해줌
	for (int i : ans)
		cout << i << "\n"; // 오름차순으로 값 출력
	return 0; 
}