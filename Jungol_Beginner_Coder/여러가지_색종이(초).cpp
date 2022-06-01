#include <iostream>
using namespace std;

int n; // �������� ����
int map[100][100] = { 0 }; // �Ͼ� ��ȭ��

void check(int sy, int sx ) { //y�� �������� x�� �������� �Է¹޴´�
	for (int y = sy; y < sy + 10; y++) { 
		for (int x = sx; x < sx + 10; x++) {
			map[y][x] = 1; // ���������κ��� ��ĭ�� 1�� ä���ָ� ���� �׸� ���� �� �ִ�.
		}
	}
}

int main() {
	cin >> n; //�������� ���� �Է¹ް�
	int cnt = 0;
	for (int i = 0; i < n; i++) { // �������� ����ŭ ���� x,y�� ���� ��ǥ�� �Է¹޴´�.
		int y, x;
		cin >> x >> y;
		check(y, x); //��ǥ�� �Է¹��� ������ ��ȭ���� ǥ�����ش�.
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1) cnt++; //��ȭ������ 0�̸� ��� 1�̸� �������̴�, �������� ������ ���� ���̸� ���� �� �ִ�.
		}
	}
	cout << cnt; //������ ����ϸ� ���̿� ����. 
	
	return 0;

}