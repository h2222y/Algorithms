#include <iostream>
#include <string>
using namespace std;

char arr[100000];
int main() {
	int tc;
	string str;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> str;
		int sum = 0;
		int cnt = 1;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				sum += cnt;
				cnt++;
			}
			else cnt = 1;
		}
		cout << sum<<endl;
	}
	return 0;
}