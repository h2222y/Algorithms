#include <iostream>
using namespace std;
//º°Âï±â-6
int main() {
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y; x++) {
			cout << " ";
		}
		for (int x = 0; x <2* n - 2*y-1; x++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}