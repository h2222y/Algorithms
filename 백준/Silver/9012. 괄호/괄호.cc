#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		stack<char> S;
		string str;
		cin >> str;
		//bool flag = false;
		for (int i = 0; i < str.length(); i++) {
			if(str[i]==')'){
				if (!S.empty() && S.top() == '(') {
					S.pop();
				}
				else S.push(str[i]);
			}
			else S.push(str[i]);
		}
		if (S.empty()) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;
}