#include <iostream>
#include <string>
using namespace std;
string str[10];

bool Letter(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z')) return false;
	}
	return true;
}
bool Count(string str) {
	int dat[200] = {};
	for (int i = 0; i < str.length(); i++) {
		dat[str[i]]++;
	}
	for (int i = 0; i < 200; i++) {
		if (dat[i] > 2) return false;
	}
	return true;
}
int Vowel(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			cnt++;
	}
	return cnt;

}
int main() {
	// 좋은 이름? 
	// 1. 소문자만 사용 가능
	// 2. 특수문자 사용금지
	// 3. 같은 알파벳 2개 이하만 가능
	// 4. 모음 a,e,i,o,u는 중복 포함 3개 사용
	int n;
	cin >> n;
	bool flag = true;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		flag = Letter(str[i]);
		if (flag == false) {
			cout << "no\n";
		}
		if (flag == true) {
			flag = Count(str[i]);
			if (flag == false) {
				cout << "no\n";
			}
		}
		if (flag == true) {
			if (Vowel(str[i]) != 3) {
				flag = false;
				cout << "no\n";
			}
		}
		if(flag==true) cout << "good\n";
	}
	

	
	return 0; 
}