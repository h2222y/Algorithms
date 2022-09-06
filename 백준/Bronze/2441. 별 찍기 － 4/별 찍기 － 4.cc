#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < x; y++) {
			cout << " ";
		}
		for (int y = 0; y < n - x; y++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}