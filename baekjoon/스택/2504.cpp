#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char> s;
string str;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int sum = 0; // ���� ��
	int mul = 1; // ���� ��
	for (int i = 0; i < str.length(); i++) { // �Է¹��� ���̸�ŭ
		if (str[i] == '(') { // ���� ( ��ȣ�̸�
			s.push(str[i]); // ���ÿ� ���� �ְ�
			mul *= 2; // 2�� �����ش�
		}
		else if (str[i] == '[') { // ���� [ ��ȣ�̸�
			s.push(str[i]); // ���ÿ� ���� �ְ�
			mul *= 3; // 3�� �����ش�
		} 
		else if (str[i] == ')') { //�ݴ� ) ��ȣ�� ��
			if (s.empty() || s.top() != '(') { // ������ ����ְ� ( ��ȣ�� �ƴϸ�
				cout << 0; //�ùٸ� ��ȣ���� �ƴϹǷ� ���� 
				return 0;
			}
			if(str[i-1]=='(') sum += mul; // ()�� ���� �����϶��� sum�� ���ݱ��� ���Ѱ��� �����ش�
			s.pop(); // ���ÿ��� ���°�ȣ�� ���ְ�
			mul /= 2; // ��ȣ�� �ݾ����Ƿ� 2�� �����ش�.
		}
		else { // �ݴ� ] ��ȣ�� �� 
			if (s.empty() || s.top() != '[') { // ��ȣ �� ���� ������ ���� 
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += mul; // [] �� ��쿡�� sum�� ���ݱ��� ���� �� ���ϱ�
			s.pop(); // ���ÿ��� ���� ���ְ�
			mul /= 3; // ��ȣ�� �ݾ����Ƿ� 3���� �����ش�. 
		}
	}
	if (s.empty()) cout << sum; //������ ��� ������� ��� �ùٸ� ��ȣ���̹Ƿ� ���� ����Ѵ�.
	else cout << 0; // ������ ���� ������ ¦�� ���� �ʴ� ��ȣ���� �����ϴ� ��
}