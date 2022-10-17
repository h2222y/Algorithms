#include <iostream>
#include <string>
using namespace std;
string str = "EWABC";
char ch;
char path[100];
int used[100];

void recur(int now) {
	
	if (path[now-1] == ch) return;
	if (now == 4) {
		cout << path << endl;
	}
	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[now] = str[i];
		recur(now + 1);
		path[now] = 0;
		used[i] = 0;
	}
	
}
int main() {
	cin >> ch;
	recur(0);

	return 0; 
}