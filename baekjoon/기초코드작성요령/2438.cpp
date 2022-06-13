//º°Âï±â
#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int i = 0; i < y; i++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}