#include <iostream>
using namespace std;

char path[10];

void dfs(int now) {
	if (now == 2) {
		cout << path << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		path[now] = 'A' + i;
		dfs(now + 1);
		path[now] = 0;
	}
}

int main() {
	dfs(0);
	return 0; 
}