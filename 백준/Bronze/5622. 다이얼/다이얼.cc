#include <iostream>
#include <string>
#include <vector>
using namespace std;
char arr[8][4] = {
	'A','B','C','\0',
	'D','E','F','\0',
	'G','H','I','\0',
	'J','K','L','\0',
	'M','N','O','\0',
	'P','Q','R','S',
	'T','U','V','\0',
	'W','X','Y','Z'
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		flag = false;
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 4; k++) {
				if (str[i] == arr[j][k]) {
					cnt += j+3;
					flag = true;
					break;
				}
			}
			if (flag == true) break;
		}
	}
	cout << cnt;

	return 0;
}