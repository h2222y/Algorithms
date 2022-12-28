#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	int cnt = -1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cnt++;
			if (cnt == k) {
				cout << x << " " << y;
				break;
			}
		}
	}
	return 0;
}