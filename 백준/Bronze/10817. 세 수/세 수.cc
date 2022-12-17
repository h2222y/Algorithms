#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= b) {
		if (b >= c) {
			cout << b;
		}
		else if (a <= c) {
			cout << a;
		}
		else cout << c;
	}
	else if (b >= a) {
		if (a >= c) {
			cout << a;
		}
		else if (b <= c) {
			cout << b;
		}
		else cout << c;
	}
	else if (c >= a) {
		if (b >= a) {
			cout << b;
		}
		else if (c <= b) {
			cout << c;
		}
		else cout << a;
	}
	else if (a >= c) {
		if (b >= c) {
			cout << b;
		}
		else if (a <= b) {
			cout << a;
		}
		else cout << c;
	}
	else if (b >= c) {
		if (a >= c) {
			cout << a;
		}
		else if (b <= a) {
			cout << b;
		}
		else cout << c;
	}


	return 0;
}