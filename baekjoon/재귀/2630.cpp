#include <iostream>
using namespace std;

int paper[200][200];
int cnt[2];
bool check(int x,int y,int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[x][y] != paper[i][j]) return false; // �ϳ��� �ٸ��� false 
		}
	}
	return true; // ��� ���� ��� true
}

void recur(int x, int y, int n) {
	if (check(x, y, n)) { // �迭�� ��� ���� ���ڷ� �̷���� �ִ��� Ȯ��
		cnt[paper[x][y]] ++; // true�� ��� ���� ���Ƿ� cnt[0|1]++;
		return;
	}
	int k = n / 2; // 2�� �����ָ� 4��� ���� x,y ��� 4���� ���� �����̹Ƿ� 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			recur(x + i * k, y + j * k, k); // ���� ��ǥ�� �����ش�. 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> paper[x][y]; // �迭�� ���� �Է¹ޱ�
		}
	}
	recur(0, 0, n);
	for (int i = 0; i < 2; i++)
		cout << cnt[i]<<"\n"; // cnt ���
}