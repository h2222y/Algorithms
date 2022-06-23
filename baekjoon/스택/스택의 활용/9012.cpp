#include <iostream>
#include <stack>
#include <string>
using namespace std;
//��ȣ

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // �Է¹��� ���ڿ��� ������ �Է¹޴´�
	while (n--) {
		stack<char> S; // ������ ����Ͽ� ������ ���̴�.
		string str;
		cin >> str; //���ڿ��� �Է¹޴´�
		for (int i = 0; i < str.length(); i++) {
			if(str[i]==')'){ //���� ���� ��ȣ�� �߰��Ѵٸ�
				if (!S.empty() && S.top() == '(') { // ������ ��� ���� �ʰ�, ���� �Է°��� (�� (�� �����ش�.
					S.pop();
				}
				else S.push(str[i]); // ���� �� ���ǿ� �ش���� ������ ���� �־ ������ ������� �ʰ� ������ش�.
			}
			else S.push(str[i]); //�̿ܿ��� (�� ��츸 �����Ƿ� ���ÿ� �־��ش�.
		}
		if (S.empty()) cout << "YES\n"; //�迭�� ��� ��� ��ȣ ���� �� �´� ��
		else cout << "NO\n"; //�� �ܿ��� NO�� ���

	}
	return 0;
}