#include <iostream>
using namespace std;
//�����4

int main() {

	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y; x++) {
			cout << " ";
		}
		for (int x = 0; x < n - y; x++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}