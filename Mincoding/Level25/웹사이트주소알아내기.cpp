#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
	int a = 0;
	int b=0;
	int c, d;
	int cnt = 0;
	while (1) {
		a = str.find("http://", a);
		b = str.find("https://", b);
		if (a == -1 && b == -1) break;
		c = str.find('.', a+1);
		d = str.find('.', b + 1);
		string temp;
		if (a != -1) {
			temp = str.substr(a+7, c - a-7);
			if (temp.length() >= 3) cnt++;
		}
		if (b != -1) {
			temp = str.substr(b + 8, d - b - 8);
			if (temp.length() >= 3) cnt++;
		}
		a = c;
		b = d;
	}
	cout << cnt << "°³";
	return 0; 
}
