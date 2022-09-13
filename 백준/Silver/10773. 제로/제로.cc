#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	stack<int> S;
	int sum = 0;
	while (k--) {
		int n;
		cin >> n;
		if (n == 0) {
			if (S.empty())
				cout << 0;
			else {
				sum -= S.top();
				S.pop();
			}
		}
		else {
			S.push(n);
			sum += S.top();
		}
	}
	cout << sum;
	return 0;
}