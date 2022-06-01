#include <iostream>
using namespace std;
// ���γ� ������ ���̰� ¦���϶� ���̸� ������ ���´�.
// ������ ����, ���� ���̰� ��� Ȧ���� ����
// ���� ���� �� �� ���� ���̰� ¦���� ¦���� �κ� ����
// �� �� ¦���� ū �� ����
// �� �� ¦���� ���̰� ������ ���� ���� ����
// ���̸� ������ �� ĭ�� ���ڰ� ��������

int paper[210][210] = { 0 }; //���� ������ �迭
int n, m; // ������ ���� ������ ����

void isMax(int n, int m) { // ���̸� ���� �� �ִ밪�� ã�´�
	int max = -99999;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (paper[y][x] > max) max = paper[y][x];
		}
	}
	cout << max << " ";

}
void isMin(int n, int m) { // ���̸� ���� �� �ּҰ��� ã�´�
	int min = 1000000;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (paper[y][x] < min) min = paper[y][x];
		}
	}
	cout << min << " " << endl;
}

void foldGaro() {// ���̸� ���η� ���� ���
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m / 2; x++) {
			paper[y][x] = paper[y][x] + paper[y][m - 1 - x];
		}
	}
	isMax(n, m / 2);
	isMin(n, m / 2);
}

void foldSero() { // ���̸� ���η� ���� ���
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n / 2; y++) {
			paper[y][x] = paper[y][x] + paper[n - 1 - y][x];
		}
	}
	isMax(n / 2, m);
	isMin(n / 2, m);
}


int main() {
	cin >> n >> m;
	int cnt = 0;// �� �� �������� Ȯ���ϱ� ���� ī��Ʈ ���� ���� ���
	int N = n, M = m;  // ī��Ʈ ���� ����ϰ� �ٽ� ���� ���ؼ� ���

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> paper[y][x]; // ���̿� �ԷµǾ� �ִ� �� ����
		}
	}

	while (1) { // �� �� ������ Ȯ���ϱ� ���� �ݺ���
		if (m % 2 != 0 && n % 2 != 0) break; //�Ѵ� Ȧ���� ����
		cnt++;

		if (m % 2 == 0) { //���ΰ� ¦���϶�
			if (n % 2 == 0) { //���ε� ¦���̸�
				if (m >= n) {
					m /= 2;
				}
				else {
					n /= 2;
				}
			}
			else {
				m /= 2;
			}
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
	}

	cout << cnt << endl; //ī��Ʈ �� ���
	n = N; // ��� �� �ٽ� �ø���
	m = M;

	while (1) {
		if (m % 2 != 0 && n % 2 != 0) break;

		if (m % 2 == 0) { //���ΰ� ¦���϶�
			if (n % 2 == 0) { //���ε� ¦���̸�
				if (m >= n) {
					foldGaro(); // ���ΰ� �� ��ų� ������ ���η� ����
					m /= 2;
				}
				else {
					foldSero(); // ���ΰ� �� ��� ���η� ����
					n /= 2;
				}
			}
			else { // ���ΰ� ¦���� �ƴϸ�
				foldGaro(); // ���θ� ¦��
				m /= 2;
			}
		}
		else if (n % 2 == 0) { //���θ� ¦���̸�
			foldSero();
			n /= 2;
		}
	}

	return 0;
}