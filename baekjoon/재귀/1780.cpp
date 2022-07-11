#include <iostream>
using namespace std;
int arr[3000][3000];
int cnt[3];

bool check(int r, int c,int n) { //�迭�� ��� ���� ���ڷ� �̷���� �ִ��� Ȯ��
	for (int i = r; i < r + n; i++) { //���� ��ǥ���� n��ŭ ���� �� ���� 
		for (int j = c; j < c + n; j++) { // ���⼭ n�� 3���� ���� ���� ����.
			if (arr[r][c] != arr[i][j]) return false; // �ϳ��� �ٸ��� ��� ���� ����
		}
	}
	return true; // ��� ���� ��� true 
}

void recur(int x,int y,int z) { //������ǥ (x,y), z�� 3���� ������ �迭�� 9��� ����
	if (check(x,y,z)) { // �迭�� ��� ���� ���ڷ� �̷���� �ִ��� Ȯ��
		cnt[arr[x][y] + 1] += 1; // true�� ��� ���� ���Ƿ� cnt[�ش簪(-1�������Ƿ�)+1]++;
		return;
	}
	int n = z / 3; // 3���� �����ָ� 9��� ���� x,y ��� 3���� ���� �����̹Ƿ� 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recur(x + i * n, y + j * n,n); // ���� ��ǥ�� �����ش�. 
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // �迭�� ũ�⸦ �Է¹޴´� n = 3^k�� 
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> arr[x][y]; // �迭�� �Է¹޴´�. 
		}
	}
	recur(0,0,n); //������ǥ (0,0), n����
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n"; //ī��Ʈ �� �� ���
	}
}