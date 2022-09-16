#include <iostream>
using namespace std;

void Hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << ' ' << '\n';
		return;
	}
	Hanoi(a, 6 - a - b, n-1);
	cout << a << ' ' << b << ' ' << '\n';
	Hanoi(6 - a - b, b, n - 1);

}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	Hanoi(1, 3, n);
	return 0;
}