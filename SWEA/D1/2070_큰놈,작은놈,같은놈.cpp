#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			cout << "#" << tc << " " << ">\n";
		}
		else if (a == b) {
			cout << "#" << tc << " " << "=\n";

		}
		else {
			cout << "#" << tc << " " << "<\n";
		}
	}
	return 0;
}