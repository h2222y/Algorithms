#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int dat[100] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		dat[a[i] - 'a']++;	
	}
	for (int i = 0; i < b.length(); i++) {
		dat[b[i] - 'a']--;
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (dat[i] != 0) {
			cnt += abs(dat[i]);
		}
	}
	cout << cnt;
	return 0;
}