#include <iostream>
#include <string>
using namespace std;
string str;


int BadWord() {
	// bad no puck 없어야함
	if (str.find("bad") != -1) return 0;
	if (str.find("no") != -1) return 0;
	if (str.find("puck") != -1) return 0;

	//'_'가 연속 5개 이하
	if (str.find("______") != -1)return 0;

	// 모든 알파벳 5개 이하만 가능 
	int dat[200] = {};
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '_') {
			dat[str[i]]++;
		}
	}
	for (int i = 0; i < 200; i++) {
		if (dat[i] > 5) return 0;
	}
	// 숫자 없어야 함
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') return 0;
	}
	return 1;

}



int main() {
	cin >> str;
	
	int ret = BadWord();
	if (ret == 1) cout << "pass";
	else cout << "fail";

	return 0; 
}