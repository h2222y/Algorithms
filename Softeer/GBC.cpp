#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, length, velocity, ans;

int main() {
	cin >> n >> m;
	vector<int> range, test; // ���� ���Ϳ� test ���� ����
	while (n--) {
		cin >> length >> velocity; // ���̿� �ӵ� �Է�
		while (length--) range.push_back(velocity); // ���Ϳ� ���
	}
	while (m--) {
		cin >> length >> velocity; // ���̿� �ӵ� �Է�
		while (length--) test.push_back(velocity); // ���Ϳ� ���
	}
	for (int i = 0; i < 100; i++) {
		ans = max(ans, test[i] - range[i]); // ���� �ε����� �ִ� ���� ���ص� max���� ���Ѵ�.
	}
	cout << ans;
	return 0;
}