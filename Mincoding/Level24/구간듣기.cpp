#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		for (int j = a; j <= b; j++) {
			cout << str[j];
		}
	}
	return 0; 
}