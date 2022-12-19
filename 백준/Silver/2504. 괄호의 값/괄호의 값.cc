#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char> s;
string str;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int sum = 0; // 누적 합
	int gop = 1; // 누적 곱
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			gop *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			gop *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if(str[i-1]=='(') sum += gop;
			s.pop();
			gop /= 2;
		}
		else {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += gop;
			s.pop();
			gop /= 3;
		}
	}
	if (s.empty()) cout << sum;
	else cout << 0;
}