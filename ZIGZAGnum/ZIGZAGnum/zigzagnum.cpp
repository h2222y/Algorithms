/* #include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int n;
		cin >> n;
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 0) {
				sum -= j;
			}
			else sum += j;
		}
		cout << "#"<<i<<" "<< sum;
		cout << endl;
	}
	return 0;
} */