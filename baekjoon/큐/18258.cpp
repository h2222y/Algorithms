#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> Q;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		else if (str == "pop") {
			if (Q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (str == "size") {
			cout << Q.size() << "\n";
		}
		else if (str == "empty") {
			if (Q.empty()) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (str == "front") {
			if (Q.empty()) {
				cout << -1 << "\n";
			}
			else cout << Q.front() << "\n";
		}
		else {
			if (Q.empty()) {
				cout << -1 << "\n";
			}
			else cout << Q.back() << "\n";
		}

	}
	return 0;
}