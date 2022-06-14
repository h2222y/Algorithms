#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//숫자의 개수

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int gop = a * b * c; //axbxc
	int dat[20] = { 0 };
	string s_gop(to_string(gop)); //곱한값을 문자열로 저장
	//cout << s_gop;
	for (int i = 0; i < s_gop.length(); i++) {
		if (s_gop[i] >= '0' && s_gop[i] <= '9') {
			dat[s_gop[i] - '0']++; //0부터 9까지 몇 번 쓰였는지 확인
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << dat[i] << endl; //개수 출력
	}
	return 0;
}