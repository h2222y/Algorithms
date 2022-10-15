#include <iostream>
using namespace std;

char edge[4] = { 'B','G','T','K' };
char path[100];
int level;

void dfs(int now) {
	if (now == level) {
		cout << path << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		path[now] = edge[i];
		dfs(now+1);
		path[now] = 0;
	}
}
int main() {
	cin >> level;
	dfs(0);
}