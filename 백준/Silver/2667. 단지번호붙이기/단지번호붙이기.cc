#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int map[27][27];
int vis[27][27];
string str[27];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		cin >> str[x];
		for (int y = 0; y < n; y++) {
			map[x][y] = str[x][y] - '0';
		}
	}
	int t = 1;
	vector<int> ans;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 0 || vis[x][y] !=0)continue;
			queue<pair<int, int>> Q;
			Q.push({ x,y });
			vis[x][y] = t;
			int cnt = 1;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (vis[nx][ny] != 0) continue;
					if (map[nx][ny] != 1) continue;
					Q.push({ nx,ny });
					vis[nx][ny] = t;
					cnt++;
				}
			}
			t++;
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << t-1 << "\n";
	for (int i : ans)
		cout << i << "\n";
	return 0; 
}