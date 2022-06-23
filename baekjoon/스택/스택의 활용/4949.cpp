#include <iostream>
#include <string>
#include <stack>
using namespace std;
//�������� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str; // �Է¹��� ���ڿ�
	while (1) {
		getline(cin, str); //���⸦ �����ؼ� �Է� �޾ƾ� ��
		if (str[0] == '.') break; //. �Ѱ��� ������ ����
		stack<char> S; // ������ ���� ����
		bool flag = false; // flag�� ���� ��ȣ ���� �´��� �ƴ����� �Ǻ�
		for (int i = 0; i < str.length(); i++) { //���� ��ŭ
			if (str[i] == '(') { // (�̸� ���ÿ� ���
				S.push(str[i]);
			}
			else if (str[i] == '[') { // [�̸� ���ÿ� ���
				S.push(str[i]);
			}
			if (str[i] == ')') { //�ݴ� ��ȣ�� ) �� ��
				if (!S.empty() && S.top() == '(') S.pop(); // ������ ������� �ʰ�, �� ���� (���
				else {
					S.push('n'); // ���ÿ� �̻��� �� ���
					flag = false; // flag�� false�� ����
					break;
				}
			}
			if (str[i] == ']') { //�ݴ� ��ȣ�� ] �� ��
				if (!S.empty() && S.top() == '[') { // ������ ������� �ʰ�, [���
					S.pop(); // �տ� ��� ��ȣ ���ֱ�
				}
				else {
					S.push('n'); //���ÿ� �̻��� �� �־��ֱ�
					flag = false; //flag�� false��
					break;
				}
			}
		}
		if (S.empty()) { //������ ��� ����ִٸ�
			flag = true; // flag�� true�̴�
		}
		else flag = false; // ������� �ʴٸ� false
		if (flag == true) cout << "yes\n"; //flag�� true�� ��� yes ���
		else cout << "no\n"; //flag�� false�� ��� no ���
	}
	return 0;
}