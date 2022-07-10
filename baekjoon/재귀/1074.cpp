#include <iostream>
using namespace std;

int vis(int n,int s,int e) {
	if (n == 0) return 0; //n�� 0�̸� 0�� ��ȯ
	int half = 1 << (n - 1); // half�� 2^(n-1) �簢���� 2^(n-1)�� 4���
	if (s < half && e < half) return vis(n - 1, s, e); // ���� 1��и鿡 �ִٸ� �״�� ��ȯ
	if (s < half && e >= half) return half*half + vis(n - 1, s, e-half); // ���� 2��и鿡 �ִٸ� 1��и��� ���� �����ְ�, y���� �����ش�.(2�� �и��� y���� ����) 
	if (s >= half && e < half) return 2* half * half + vis(n - 1, s-half, e); // ���� 3��и鿡 �ִٸ� 1,2��и��� ���� �����ְ�, x���� �����ش�.(3�� �и��� x���� ����)
	return 3*half*half + vis(n - 1, s-half, e-half); // ���� 4��и鿡 �ִٸ� 1,2,3�� �и��� ���� �����ְ� x,y�� ��� �����ش�. 
	
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << vis(n, r, c);

}