/* ������ �����ϴµ� ���� �ɷȴµ�,
	���� ��� 8 4 3 6 8 7 5 2 1�� �Է����� ������(8�� ������ ũ�� n)
	4 3 6 8 7 5 2 1�̶�� ������ ������������ ���ĵ� ������ �̿��� ������ �� �ִ���
	Ȯ���ϴ� ���̴�.
	4�� ������ �ֱ� ���ؼ� stack�� 1 2 3 4�� ������� push�ϰ�, 4�� pop�ؼ� ��������
	3�� pop�ϰ�, ������ 6�� �ֱ� ���ؼ� �ٽ� 5 6�� stack�� push�ϰ�, 6�� pop �ϴ� ���̴�. */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // ������ ũ��

	stack<int> S; //�Է� ���� stack 
	int cnt = 1; // cnt�� ������ ���� ���� �� �� (Stack�� ������������ �� ����)
	string ans; // ���� ������ ���ڿ� 

	while (n--) {
		int k; // ������ �� ��
		cin >> k;
		while (cnt <= k) { // ������ ������ cnt�� ������
			S.push(cnt++); //1���� �־��ְ� ����
			ans += "+\n"; //push ������ ���信 �ֱ�
		}
		if (S.top() != k) { // stack�� top ���� k�� ���� �ʴٸ�, 
			cout << "NO\n"; // NO ����ϰ�
			return 0; //��� ����
		}
		S.pop(); // �� �ܿ��� pop�ؼ� ���� ������ֱ�
		ans += "-\n"; //pop ������ �˷���
	}
	cout << ans;

	return 0;
}