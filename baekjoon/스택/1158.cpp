#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; // ������ ũ��� ������ ��ȣ�� idx �Է¹���
	cin >> n >> k;
	vector<int> v; // 1~n���� ������ ����
	for (int i = 1; i <= n; i++) {
		v.push_back(i); // ���Ϳ� �� ����
	}

	vector<int> ans; //���� ������ ������ ����

	for (int i = 0; ans.size()<n; i++) { // ans�� ũ�Ⱑ n �̸��� ������
		if (i % k == k - 1) ans.push_back(v[i]); // �ε����� k-1�̹Ƿ� i�� k�� ���� �������� k-1�϶�
		else v.push_back(v[i]); //�������� �ٽ� ���ͷ� �־���
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << ans[i];
		else cout << ans[i] << ", ";
	}
	cout << ">";

	return 0;
}