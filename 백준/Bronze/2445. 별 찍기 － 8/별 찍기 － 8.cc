#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < x+1; y++) {
			cout << "*";
		}
		for (int y = 0; y <2*(n-x-1); y++) {
			cout << " ";
		}
		for (int y = 0; y < x + 1; y++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int x = 0; x < n - 1; x++) {
		for (int y = 0; y < n - x-1; y++) {
			cout << "*";
		}
		for (int y = 0; y < 2 * x +2; y++) {
			cout << " ";
		}
		for (int y = 0; y < n - x - 1; y++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}