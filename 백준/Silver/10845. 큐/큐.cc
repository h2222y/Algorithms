#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;
int head = 0, tail = 0;
int dat[MX];

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
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
			if (head == tail) {
				cout << -1 << "\n";
			}
			else{
				cout << front() << "\n";
				pop();
			}
		}
		else if (str == "size") {
			 cout << tail - head<<"\n";
		}
		else if (str == "empty") {
			if (head == tail) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (str == "front") {
			if (head ==tail) {
				cout << -1 << "\n";
			}
			else
				cout<<front()<<"\n";
		}
		else {
			if (head==tail) {
				cout << -1 << "\n";
			}
			else
				cout<<back()<<"\n";
		}
	}

	return 0;
}