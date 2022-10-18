#include <iostream>
#include <string>
using namespace std;
string str;

bool isValid(string temp) {
	if (temp.length() != 5) return false; // ���� 5�ƴ϶�� ����
	for (int i = 0; i < 5; i++) {
		if (!(temp[i] >= '0' && temp[i] <= '9'))return false; // ���� �ƴϸ� ����
	}
	return true; // ������ ����
}
void Parsing(string str) {
	int a = 0; // �ε��� 0������ Ž������
	int b; 
	while(1){ // ��� �߰ߵɶ�����
	a = str.find('[', a); // ���� [�� �߰��ϸ�
	if (a == -1) return; // ��������
	b = str.find(']', a+1); // a+1�ε������� ] ���� ������
	if (b == -1) return; // ��������
	string temp = str.substr(a + 1, b - a - 1); // ���ڸ� ��������
	if (isValid(temp)) { // ���� ���ڰ� 5����� 
		cout << "[" << temp << "]\n"; // ���
	}
	a = b + 1; // a�� b+1���� �ٽ� Ž��
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str; // ���ڿ� �Է¹ޱ� 
		Parsing(str); // �Ľ��ϱ� 
	}
	
	return 0; 
}