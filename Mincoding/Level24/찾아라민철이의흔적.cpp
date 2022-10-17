#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int n;
	string isIn;
	cin >> name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> isIn;
		if (isIn.find(name) == -1) {
			cout << "X\n";
		}
		else {
			cout << "O\n";
		}
	}
	return 0; 
}