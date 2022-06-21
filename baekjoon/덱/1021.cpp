#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> DQ;
	int n, m;
	cin >> n >> m; // ť�� ũ�� n, �̾Ƴ����� �ϴ� ���� ����
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		DQ.push_back(i);
	}
	while (m--) {
		int pos; // �����̰� �������� �ϴ� ���� ��ġ
		cin >> pos;
		int idx = find(DQ.begin(), DQ.end(), pos) - DQ.begin(); // idx�� ���� ��ġ
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