#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> DQ;
	int n, m;
	cin >> n >> m; // 큐의 크기 n, 뽑아내려고 하는 수의 개수
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		DQ.push_back(i);
	}
	while (m--) {
		int pos; // 지민이가 뽑으려고 하는 수의 위치
		cin >> pos;
		int idx = find(DQ.begin(), DQ.end(), pos) - DQ.begin(); // idx는 현재 위치
		while (DQ.front() != pos) {
			if (idx < (int)DQ.size() - idx) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
			else {
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
			ans++;
		}
		DQ.pop_front();
	}
	cout << ans;

	return 0;
}