#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double a, b;
	cin >> a >> b;
	cout << int(a + b) << "\n";
	cout << int(a - b) << "\n";
	cout << int(a * b) << "\n";
	cout << int(a / b) << "\n";

	return 0; 
}