#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int a, b;
		cin >> a >> b;
		cout << "#" << T << " " << a / b <<" "<< a % b<<"\n";
	}
	return 0;
}