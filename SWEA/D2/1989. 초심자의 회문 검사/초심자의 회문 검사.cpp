#include <iostream>
#include <string>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		string str;
		cin >> str;
		bool flag = true;
		int idx = (str.length()-1) / 2;
		for (int i = 0; i <= idx; i++) {
			if (str[i] != str[str.length() - 1 - i]) {
				cout <<"#"<<T<<" " << 0 << "\n";
				flag = false;
				break;
			}
		}
		if (flag == true) cout << "#" << T << " " << 1 << "\n";
	}
	return 0;
}