#include <iostream>
#include <string>
using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0;

void push(int x) {
	dat[pos] = x;
	pos++;
}
void pop() {
	if (pos != 0) pos--; // pos가 0이 아닐 때에만 감소시킨다.
}

int top() {
	return dat[pos - 1];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) { // n번 반복
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (str == "pop") {
			if (pos == 0) // pos가 0이면 stack에 값이 없다는 뜻
				cout << -1 << "\n";
			else
				cout << top() << "\n";
			pop();
		}
		else if (str == "size") {
			cout << pos << "\n";
		}
		else if (str == "empty") {
			if (pos == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else {
			if (pos == 0)
				cout << -1 << "\n";
			else
				cout << top() << "\n";
		}
	}
	return 0;
}