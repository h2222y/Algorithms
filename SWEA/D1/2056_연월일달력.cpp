#include <iostream>
#include <string>
using namespace std;

int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		string str;
		cin >> str;
		if (str[4] == '0') {
			int month = str[5]-'0';
			int day = (str[6] - '0') * 10 + (str[7] - '0');
			if (str[5] == '0') {
				cout << "#" << T << " " << -1 << "\n";
			}
			else if (1 <= day && day <= days[month - 1]) {
				cout << "#" << T << " ";
				for (int i = 0; i < 4; i++) {
					cout << str[i];
				}
				cout << "/";
				for (int i = 4; i <= 5; i++) {
					cout << str[i];
				}
				cout << "/";
				for (int i = 6; i < str.length(); i++) {
					cout << str[i];
				}
				cout << "\n";
			}
			else cout << "#" << T << " " << -1<<"\n";
		}
		else if (str[4] == '1') {
			if (str[5] == '1' || str[5] == '2') {
				int month = (str[4] - '0') * 10 + (str[5] - '0');
				int day = (str[6] - '0') * 10 + (str[7] - '0');
				if (1 <= day && day <= days[month - 1]) {
					cout << "#" << T << " ";
					for (int i = 0; i < 4; i++) {
						cout << str[i];
					}
					cout << "/";
					for (int i = 4; i <= 5; i++) {
						cout << str[i];
					}
					cout << "/";
					for (int i = 6; i < str.length(); i++) {
						cout << str[i];
					}
					cout << "\n";
				}
			}
			else cout << "#" << T << " " << -1<<"\n";
		}
	}

	return 0;
}