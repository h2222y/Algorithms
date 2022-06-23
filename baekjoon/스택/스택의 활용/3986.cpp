#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; //��ɾ��� ����
	int cnt = 0;
	while (n--) {
		stack<char> S; //������ �̿��Ѵ�. FILO
		string str;
		cin >> str; //��ɾ �Է¹޴´�. 
		for (int i = 0; i < str.length(); i++) {
			if (!S.empty() && S.top() == str[i]) S.pop(); // ������ ������� �ʰ�, ���� ���� ������ top���� ���ٸ� pop
			else S.push(str[i]); // ���� ���ǿ� �ش����� ������ ���ÿ� �� push
		}
		if (S.empty()) cnt++; // ������ ��� ��������� ī��Ʈ+1
	}
	cout << cnt;

}