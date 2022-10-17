#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	cout << str<<"\n";
	for (int j = str.length() - 1; j >= 0; j--) {
		cout << str[j];
	}
	return 0; 
}