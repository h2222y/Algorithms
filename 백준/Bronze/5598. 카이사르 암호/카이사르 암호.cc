#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'D' && str[i] <= 'Z') {
			str[i] = str[i] - 3;
		}
		else {
			str[i] = str[i] + 23;
		}
	}
	cout << str;
	return 0; 
}