#include <iostream>
using namespace std;

//a+b

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}