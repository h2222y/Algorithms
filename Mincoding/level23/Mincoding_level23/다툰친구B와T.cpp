#include <iostream>
#include <string>
using namespace std;
string str;
int used[100];
int cnt = 0;
void recur(int now) {

	if (now >= 2 && used[now - 1] == 'B' && used[now - 2] == 'T') return;
	if (now >= 2 && used[now - 1] == 'T' && used[now - 2] == 'B') return;

	if (now == 4) {
		cnt++;
		return;
	}

	for (int to = 0; to < 4; to++) {
		used[now] = str[to];
		recur(now + 1);
		used[now] = 0;
	}
}

int main() {
	cin >> str;
	recur(0);
	cout << cnt;
	return 0;

}