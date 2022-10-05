#include <iostream>
#include <string>
using namespace std;
string str;

int main() {
	int n;
	cin >> n;
	bool check = true;
	// int rest = 0;
	for (int i = 1; i <= n; i++) {
		str = to_string(i);
		bool check = true;
		int cnt = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '3' || str[j] == '6' || str[j] == '9') {
				check = false;
				cnt++;
			}
		}
		if (!check) {
			for (int j = 0; j < cnt; j++) {
				cout << "-";
			}
			cout << " ";
		}
		else cout << i << " ";
	}
	return 0;
}