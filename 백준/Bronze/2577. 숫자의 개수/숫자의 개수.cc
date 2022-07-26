#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int gop = a * b * c;
	int dat[20] = { 0 };
	string s_gop(to_string(gop));
	//cout << s_gop;
	for (int i = 0; i < s_gop.length(); i++) {
		if (s_gop[i] >= '0' && s_gop[i] <= '9') {
			dat[s_gop[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << dat[i]<<endl;
	}
	return 0;
}