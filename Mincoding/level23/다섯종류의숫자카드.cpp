#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string numbers;
char path[100];
int cnt = 0;
void recur(int now) {
	if (now>1 && abs(path[now - 2] - path[now-1]) > 3) return;
	if (now == 4) {
		//cout << path << endl;
		cnt++;
		return;
	}
	for (int i = 0; i < 5; i++) {
		path[now] = numbers[i];
		recur(now + 1);
		path[now] = 0;
	}
}
int main() {
	cin >> numbers;
	recur(0);
	cout << cnt;
	return 0; 
}