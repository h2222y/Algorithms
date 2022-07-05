#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define X first
#define Y second
#define ll long long 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int mx = -999;
	while (1) {
		cin >> n; // ���簢���� ������ �Է¹޴´�.
		int cnt = 1;
		// mx = -999;
		if (n == 0) return 0;
		// vector<int> ans = { 0 };
		stack <pair<ll, ll>> S;
		ll ans=0; // ������ long long ��
		for (int i = 0; i < n; i++) {
			int height; 
			cin >> height; //������ ���̸� �Է¹޴´�.
			int idx = i; //���� i�� �ε��� ������ ��
			while (!S.empty() && S.top().X >= height) { // ������ ������� �ʰ� ������ top���� ���� ���̺��� ũ�ų� ���ٸ�
				ans = max(ans, (i - S.top().Y) * S.top().X); // ������ �ִ밪�� ���Ѵ�. 
				// ���� i�� ������ ������ idx���� ���ְ� ���̸� �����ش� 
				idx = S.top().Y; // �ε����� ���� ������ �� ���� ������ �������ش�.
				S.pop(); // ������ top���� �����ش�
			}
			S.push({ height,idx }); // ���̿� �ε����� �ֱ�
		}
		while (!S.empty()) {
			ans = max(ans, (n - S.top().Y) * S.top().X); // �� ������ ��ġ�� ������ ������� �ʴٸ�,
			// ��ü ������ ���� n���� ���ÿ� �����ִ� ������ ���̸� �������� �ִ밪�� �Ǵ��� Ȯ���Ѵ�. 
			S.pop();
		}
		cout << ans << "\n";
	}

	return 0;
}