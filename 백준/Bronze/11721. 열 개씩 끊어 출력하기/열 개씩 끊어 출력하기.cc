#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int main() {
	cin >> str;
	int a = 0;
	while(a<str.length()){
		if (a + 10 > str.length()) {
			for (int i = a; i < str.length(); i++) {
				cout << str[i];
			}
			cout << "\n";
		}
		else {
			for (int i = a; i < a + 10; i++) {
				cout << str[i];
			}
		}
	a += 10;
	cout << "\n";
	}
}