#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int pass,k;
	cin >> pass >> k;
	int cnt = 0;
	for (int i = k; i <= pass; i++) {
		cnt++;
		if (i == pass) break;
	}
	cout << cnt;
	return 0;
}