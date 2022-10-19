#include <iostream>
#include <string>
using namespace std;
string str;

int getNumIdx(int start) {
	for (int i = start; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') return i;
	}
	return -1;
}
int getCharIdx(int start) {
	for (int i = start; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return i;
	}
	return -1;
}
void print(string name, string num) {
	cout << name << "#";
	int number = stoi(num);
	number += 17;
	cout << number << "\n";
}
int main() {
	cin >> str;
	int a = 0;
	int b = 0;
	string name, num;
	while (1) {
		b = getNumIdx(a); // ���� �ε��� b�� ���
		name = str.substr(a, b - a); // ó�� ~ ���� �ε��� �������� �̸�

		a = b; // ���� �ε��� ���� ~ �����ε������� ã�Ƽ� ��ȣ ��������
		b = getCharIdx(a);
		if (b == -1) {
			b = str.length();
			num = str.substr(a, b - a);
			print(name, num);
			a = b;
			break;
		}
		num = str.substr(a, b - a);
		print(name, num);
		a = b;
	}

	return 0;
}