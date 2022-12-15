#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int m;
int sum = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		// sum += num;
	}
	cin >> m;
	sort(v.begin(), v.end());
	int left = 0, right = v[n - 1];
	int mid = 0;
	int mx = 0;
	while (left <= right) {
		int sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] >= mid) sum += mid;
			else sum += v[i];
		}
		if (sum > m)
			right = mid - 1;
		else if (mid < m) {
			left = mid + 1;
			mx = max(mid, 0);
		}
	}
	cout << mx;

	return 0;
}