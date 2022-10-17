#include <iostream>
#include <string>
using namespace std;
string input[5];
int cnt = 0;

void Input() {
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}
}
int getFind() {
	int a = -1;
	for(int i=0;i<5;i++){
		while (1) {
		a = input[i].find("MCD", a + 1);
		if (a == -1) break;
		cnt++;
		}
	}
	return cnt;
}
int main() {
	Input();
	getFind();
	cout << cnt;

	return 0; 
}