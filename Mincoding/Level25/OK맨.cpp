#include <iostream>
#include <string>
using namespace std;
string str;


int BadWord() {
	// bad no puck �������
	if (str.find("bad") != -1) return 0;
	if (str.find("no") != -1) return 0;
	if (str.find("puck") != -1) return 0;

	//'_'�� ���� 5�� ����
	if (str.find("______") != -1)return 0;

	// ��� ���ĺ� 5�� ���ϸ� ���� 
	int dat[200] = {};
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '_') {
			dat[str[i]]++;
		}
	}
	for (int i = 0; i < 200; i++) {
		if (dat[i] > 5) return 0;
	}
	// ���� ����� ��
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