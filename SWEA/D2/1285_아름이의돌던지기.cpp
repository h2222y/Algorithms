#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n;
		int arr[1002] = {};
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int min_val = 100003;
		for (int i = 0; i < n; i++) {
			min_val = min(min_val, abs(arr[i]));
		}
		for (int i = 0; i < n; i++) {
			if (abs(arr[i]) == min_val)
				cnt++;
		}
		cout << "#" << T << " " << min_val << " " << cnt << "\n";
	}

	return 0;
}