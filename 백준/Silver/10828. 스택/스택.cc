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
	if(pos!=0) pos--;
}

int top() {
	return dat[pos - 1];
}


int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (str == "pop") {
			if (pos == 0)
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