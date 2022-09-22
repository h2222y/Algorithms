#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> p;
int sum_arr[1002];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p.push_back(num);
	}

	sort(p.begin(), p.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum_arr[i] += p[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sum_arr[i];
	}
	cout << ans;

}
