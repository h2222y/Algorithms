#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		Q.push(i);
	}
	while (1) {
		if (Q.size() == 1) break;
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	
	}
	cout << Q.front();
	return 0;
}