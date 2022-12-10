#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	// 0시부터 23시까지 0부터 59분까지
	b += c;
	if (b > 59) {
		a += b/60;
		b %=60;
	}

	a %= 24;
	cout << a << " " << b;

	return 0;
}