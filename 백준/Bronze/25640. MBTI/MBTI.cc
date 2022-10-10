#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string jinho;
	cin >> jinho;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == jinho)cnt++;
	}
	cout << cnt;

	return 0; 
}