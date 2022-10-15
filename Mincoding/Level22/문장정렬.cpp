#include <iostream>
#include <algorithm>
using namespace std;
string str[4];

bool Comp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}
	sort(str, str + 4, Comp);
	
	for (int i = 0; i < 4; i++) {
		cout << str[i] << "\n";
	}

	return 0; 
}