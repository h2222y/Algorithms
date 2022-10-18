#include <iostream>
#include <string>
using namespace std;

int n;

bool parser(string str) {
	int a = 0;
	int b;
	string temp;
	while (1) {
		int dat[200] = {};
		a = str.find('<', a);
		if (a == -1) break;
		b = str.find('>', a + 1);
		temp = str.substr(a+1, b-a-1);
		for (int i = 0; i < temp.length(); i++) {
			dat[temp[i]]++;
		}
		for (int i = 0; i < 200; i++) {
			if (dat[i] >= 2) return false;
		}
		a = b + 1;
	}
	return true;
}

int main() {
	// <>안의 문자열은 고결한 문자열이여야 한다
	// 고결한 문자열? 중복된 문자열이 없어야 한다.
	// 중복된 문자열이 아예 없을 경우 완벽한 문자열이다
	// 완벽한 문자열일경우 O, 아닐 경우 X 출력
	cin >> n; //문자열의 개수
	bool flag = true;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		// 괄호 찾아서 parsing 하기
		flag= parser(str);
		if (flag == false) {
			cout << "X";
		}
		else cout << "O";
	}
	return 0; 
}