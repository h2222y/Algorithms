#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cout << "=";
		}
		cout << "\n";
	}
	return 0; 
}