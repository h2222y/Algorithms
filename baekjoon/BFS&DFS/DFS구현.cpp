#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second

int board[502][502]; // = {...};
int vis[502][502];
int n = 7, m = 10;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int, int>> S;
	vis[0][0] = 1;
	S.push({ 0,0 });
	while (!S.empty()) {
		auto cur = S.top();
		S.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= 7 || ny < 0 || ny >= 10)continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			S.push({ nx,ny });
		}
	}
}