#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; // n 동전의 개수, k는 구하고자 하는 값
	cin >> n >> k;
	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int i = n - 1;
	while(1) {
		if (k <= 0) break;
		if (v[i] > k) i--;
		else if (v[i] == k) {
			cnt++;
			break;
		}
		else if(v[i]<k) {
			k = k - v[i];
			cnt++;
			if (v[i] > k) {
				i--;
			}
		}
	}
	cout << cnt;
	return 0;
}