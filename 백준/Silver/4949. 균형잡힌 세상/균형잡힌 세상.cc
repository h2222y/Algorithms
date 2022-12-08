#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	while (1) {
		getline(cin, str);
		if (str[0] == '.') break;
		stack<char> S;
		bool flag = false;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				S.push(str[i]);
			}
			else if (str[i] == '[') {
				S.push(str[i]);
			}
			if (str[i] == ')') {
				if (!S.empty() && S.top() == '(') S.pop();
				else {
					S.push('n');
					flag = false;
					break;
				}
			}
			if (str[i] == ']') {
				if(!S.empty() && S.top() == '['){
				S.pop();
				}
				else {
					S.push('n');
					flag = false;
					break;
				}
			}
		}
		if (S.empty()) {
			flag = true;
		}
		else flag = false;
		if (flag == true) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}