#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	stack<int> S;
	int sum = 0;
	while (k--) {
		int n;
		cin >> n;
		if (n == 0) {
			if (S.empty())
				cout << 0; //����� ��� ó��
			else {
				sum -= S.top(); //0�� �Է��Ұ�� ���� �ֽŰ��� �տ��� �� ��
				S.pop(); //���� �ֽŰ��� ����
			}
		}
		else {
			S.push(n); //0�� �ƴ� ���� ��� ���� �־��� ��
			sum += S.top(); //���� �ֽ� ���� �տ� �߰�
		}
	}
	cout << sum;
	return 0;
}