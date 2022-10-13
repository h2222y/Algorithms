#include <iostream>
#include <vector>
using namespace std;

int virus[102][102];
int dat[102];
int n;
bool check[102];

int cnt = 0;

void dfs(int now) {
	check[now] = true;
	for (int to = 1; to <= n; to++) {
		if (virus[now][to] == 0)continue;
		if (!check[to]) {
			dfs(to);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int edgeCnt;
	cin >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		virus[from][to] = 1;
		virus[to][from] = 1;
	}
	dfs(1);
	cout << cnt;
	return 0; 
}