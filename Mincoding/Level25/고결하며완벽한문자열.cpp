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
	// <>���� ���ڿ��� ����� ���ڿ��̿��� �Ѵ�
	// ����� ���ڿ�? �ߺ��� ���ڿ��� ����� �Ѵ�.
	// �ߺ��� ���ڿ��� �ƿ� ���� ��� �Ϻ��� ���ڿ��̴�
	// �Ϻ��� ���ڿ��ϰ�� O, �ƴ� ��� X ���
	cin >> n; //���ڿ��� ����
	bool flag = true;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		// ��ȣ ã�Ƽ� parsing �ϱ�
		flag= parser(str);
		if (flag == false) {
			cout << "X";
		}
		else cout << "O";
	}
	return 0; 
}