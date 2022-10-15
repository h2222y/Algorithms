#include <iostream>
using namespace std;
int n;
int path[100];

void recur(int now) {
	if (now > 4) {
		for(int i=1;i<=4;i++){
		cout << path[i];
		}
		cout << "\n";
		return; 
	}
	
	for (int i = 1; i <= n; i++) {
		path[now] = i;
		recur(now + 1);
		path[now] = 0;
	}
}

int main() {
	cin >> n;
	recur(1);
	return 0; 
}