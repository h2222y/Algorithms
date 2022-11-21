#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string str;
		getline(cin, str);
		if (i == 0) continue;
		cout << i << "." << " " << str<<"\n";
	}

	return 0;
}