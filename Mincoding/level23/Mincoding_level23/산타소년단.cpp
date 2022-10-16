#include <iostream>
#include <string>
using namespace std;
string bts = "BTSKR";

int ans = 0;
char path[100];
int used[100];
int n;

void recur(int now) {
	if (now == n) {
		for (int i = 0; i < now; i++) {
			if (path[i] == 'S') {
				ans++;
			}
		}
		return; 
	}
	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		path[now] = bts[i];
		used[i] = 1;
		recur(now + 1);
		path[now] = 0;
		used[i] = 0;
	}

}
int main() {
	cin >> n;
	recur(0);
	cout << ans;
	return 0; 
}