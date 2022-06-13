#include <iostream>
using namespace std;
// º°Âï±â3

int main() {
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n-y; x++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}