#include <iostream>
#include <string>
using namespace std;

int n;
int ans = 0;
char path[100];
string alpha = "ABC";
void recur(int now) {
	int cnt = 0;
	if (now >= 3 ) {
		if (path[now - 3] == path[now - 2] && path[now - 2] == path[now - 1]) return;
		//ans++;
	}
	if (now == n) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		path[now] = alpha[i];
		recur(now + 1);
		path[now] = 0;
	}

}

int main() {
	cin >> n;
	recur(0);
	cout << ans;
	return 0; 
}