#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second
#define ll long long 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; //��� �� �Է¹ޱ�
	cin >> n;
	stack<pair<int, int>> S;
	ll ans = 0; 

	while (n--) {
		int now;
		cin >> now; //�� ����� Ű �Է�
		int cnt = 1; // 1���� ī��Ʈ
		while (!S.empty() && S.top().X <= now) { // ������ ���� �ʰ� ���� �� �� Ű�� ���� Ű���� �۰ų� ������
			ans += S.top().Y; // ���信 ī��Ʈ�� ���ϱ�
			if (S.top().X == now) cnt += S.top().Y; // Ű�� �������� ī��Ʈ���� ���� ī��Ʈ�� ���ϱ�
			S.pop();
		}
		if (!S.empty()) ans++; // ���� ���� ū ����� �� �� �ִ� ��� �� ����
		S.push({ now,cnt }); //���ÿ� ���� �� �ֱ�
	}
	cout << ans; //��ü ���� ���� ���
	return 0;
}