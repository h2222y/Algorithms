#include <iostream>
using namespace std;

int n; //������ ����
int map[101][101] = { 0 }; // �Ͼ� ��ȭ�� 0�� ������ ���Ŵϱ� ũ�� �˳��ϰ� ����� �ֱ�

void Draw(int sy, int sx) { // ���� �簢���� �׷��� �Լ�
	for (int y = sy; y < sy + 10; y++) {
		for (int x = sx; x < sx + 10; x++) {
			map[y][x] = 1; //���� �簢���� ũ�Ⱑ 10x10���� ����, ���۰��� �Է¹޾Ƽ� �׸���
		}
	}
}

int Check(int y, int x) { //�ѷ��� ������ �Լ�
	int direct_y[4] = {-1,+1,0,0}; //��ȭ������ 1�� ǥ�õ� �κ��� �����¿츦 Ȯ���Ѵ�. y�� ����迭
	int direct_x[4] = { 0,0,-1,+1 }; // x�� ����迭
	int cnt = 0; //0�� ������ ��� Ȯ���� ���̴�. 1 �ֺ��� 0�� ������ ����, 1�̸� ���� �ʴ´�. (�ѷ��� ����ϴ� ���)
	int dx, dy;
	for (int t = 0; t < 4; t++) {
		dy = y + direct_y[t]; // ����迭�� �ݺ��ϸ� �����¿츦 Ȯ���Ѵ�.
		dx = x + direct_x[t]; 
		if (map[dy][dx] == 0) cnt++; //1 �ֺ��� 0�̸� ������ �����ش�.
	}
	return cnt;
}

int main() {
	cin >> n;
	int ret,sum=0;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		Draw(y, x); //�簢�� �׸���
	}
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1) {
				ret = Check(y, x); // 1�϶� �� ��ǥ�� �����¿츦 Ȯ���ؼ� 0�� ������ ��ȯ
				sum += ret; // ���ϰ��� �����ؼ� �ѷ��� ���� ���Ѵ�. 
			}
		}
	}
	cout << sum; //�ѷ��� �Ի�
	return 0;
}