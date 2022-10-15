#include <iostream>
using namespace std;

char date[2] = { 'x','o' };
int n;
char path[100];

void recur(int now) {
	if (now == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 2; i++) {
		path[now] = date[i];
		recur(now + 1);
		path[now] = 0;

	}
}

int main() {
	cin >> n;
	recur(0);
	return 0; 
}