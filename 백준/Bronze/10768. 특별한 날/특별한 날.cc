#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mon, date;
	cin >> mon >> date;
	if (mon == 2) {
		if (date > 18) {
			cout << "After";
		}
		else if (date < 18) {
			cout << "Before";
		}
		else cout << "Special";
	}
	else if (mon > 2) {
		cout << "After";
	}
	else cout << "Before";
	

	return 0;
}