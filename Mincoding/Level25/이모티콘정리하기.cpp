#include <iostream>
#include <string>
using namespace std;

string str;

void removeChar(char ch) {
	// 괄호를 한 개로 정리 
	string tar;
	tar += ch;
	tar += ch;
	int a = -1;
	int b;
	while (1) {
		a = str.find(tar, a + 1);
		if (a == -1) break;
		for (int i = a; i <= str.length(); i++) {
			if (str[i] != ch) {
				b = i;
				break;
			}
		}
		int size = b - a - 1;
		str.erase(a, size);
	}
}
void step1() {
	removeChar('(');
	removeChar(')');
}
void step2()
{
	//눈웃음 ^^ 두개로 정리

	int a = -1;
	int b;
	while (1) {
		a = str.find("^^^", a + 1);
		if (a == -1) break;

		for (int i = a; i <= str.length(); i++) {
			if (str[i] != '^') {
				b = i;
				break;
			}
		}

		int size = b - a - 2;
		str.erase(a, size);
	}

}
void step3()
{
	//눈과 눈 사이 _ 하나로 정리
	int a = -1;
	int b = 1;

	while (1) {
		a = str.find('^', a + 1);
		if (a == -1) break;
		if (a + 2 >= str.length()) break;

		if (str[a + 2] == '^') str[a + 1] = '_';
	}
}

int main() {
	// 풀이 1
	
	/* string temp[100];
	string str;
	cin >> str;
	int a = 0;
	int b = 0;
	int t = 0;
	while (1) {
		a = str.find("(^", a);
		if (a == -1) break;
		b = str.find("^)", a + 1);
		//string temp;
		for (int i = a; i <= b+1; i++) {
			temp[t] += str[i];
		}
		t++;
		a = b+1;
	}
	for (int i = 0; i < 100; i++) {
		if (temp[i] == "") break;
		int cnt = 0;
		for (int j = 0; j < temp[i].length(); j++) {
			if (temp[i][j] == '(' || temp[i][j] == ')') continue;
			if (temp[i][j] == '\0') temp[i].pop_back();
			if (temp[i][j] == '^') {
				cnt++;
				if (cnt > 2) {
					temp[i][cnt - 1] =temp[i][cnt];
					temp[i][cnt] = ')';
					temp[i][cnt + 1] = '\0';
				}
			}
			else {
				temp[i][j] = '_';
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		if (temp[i] != "") cout << temp[i];
	} */
	
	// 풀이 2
	cin >> str;
	step1();
	step2();
	step3();
	cout << str;



	return 0; 
}