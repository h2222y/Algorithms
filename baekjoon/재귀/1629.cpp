#include <iostream>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m) {
	if (b == 1) return a % m; //base condition a�� 1���� Ŭ �� �ֱ� ������ m���� ���� ������ ��ȯ
	ll val = POW(a,b/2,m); // �������� 2�� ������
	val = val * val % m; //val���� 2�γ���� ���� a�� �ٽ� �������ش�.
	if (b % 2 == 0) return val; // ���� ¦���̸� �״�� val�� ������ָ� �ȴ�.
	return val * a % m; // Ȧ���̸� val�� a�� �� �� �� ������� �Ѵ� (2b+1)
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c; 
	cout<< POW(a, b, c); // �� ���
}