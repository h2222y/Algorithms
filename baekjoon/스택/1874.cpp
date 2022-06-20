#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> S;
	int cnt = 1;
	string ans;
	while (n--) {
		int num;
		cin >> num;
		while (cnt <= num) {
			S.push(cnt++);
			ans += "+\n";
		}
		if (S.top() != num) {
			cout << "NO\n";
			return 0;
		}
		S.pop();
		ans += "-\n";
	}
	cout << ans;
	return 0;
}