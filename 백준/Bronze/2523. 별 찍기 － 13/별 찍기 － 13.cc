#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 0; x < y; x++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int y = 1; y < n; y++) {
		for (int x = 0; x < n - y; x++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0; 
}