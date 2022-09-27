#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += n[i] - '0';
	}
	cout << sum;
	return 0;
}