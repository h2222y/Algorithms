#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	
	int s, y;
	int girls[7] = { 0 };
	int boys[7] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		if (s == 0) girls[y]++;
		else boys[y]++;
	}

	int cnt = 0;

	for (int i = 1; i <= 6; i++) {
		if (girls[i] > 0) {
			cnt += (girls[i]-1) / k + 1;
		}
		if (boys[i] > 0) {
			cnt += (boys[i]-1) / k + 1;
		}
	}
	cout << cnt;

	return 0;
}