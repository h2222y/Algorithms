#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	// 1<=n<=1000
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cout << i << " ";
	}
	return 0;
}