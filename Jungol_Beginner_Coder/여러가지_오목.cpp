#include <iostream>
using namespace std;
int map[20][20] = { 0 }; //������ �׸���
// �⺻������ �� ������ x,y ��ǥ�� ����� ���̱� ������ 8���� ��� �˻��� �ʿ� ����
// �ߺ��Ǵ� �κ� �����ϰ� 4�κи� �˻����ָ� �ȴ�.

int Garo(int sy,int sx) { //���� �˻� �ڵ�
	if (map[sy][sx - 1] == map[sy][sx] || map[sy][sx]==map[sy][sx+5]) return 0; // 6���̸� �ȵǱ� ������ �ش� ��ǥ ���ʰ� 6ĭ �� Ȯ��
	for (int i = 1; i <= 4; i++) { //4�� �����ָ鼭
		if (sx + i > 19) return 0; // ���� ����� �ٷ� ����
		if (map[sy][sx] != map[sy][sx + i]) return 0; //���� ������ �ٷ� ����
	} 
	return 1; //��� �ش���� ������ 1 ����
}
int Sero(int sy, int sx) { //���� �˻� �ڵ�
	if (map[sy-1][sx] == map[sy][sx] || map[sy][sx] == map[sy+5][sx]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sy + i > 19) return 0;
		if (map[sy][sx] != map[sy+i][sx]) return 0;
	}
	return 1;
}
int Up_Diag(int sy, int sx) { // ���� �ö󰡴� �밢�� Ȯ��
	if (map[sy+1][sx - 1] == map[sy][sx] || map[sy][sx] == map[sy - 5][sx + 5]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sx + i > 19 || sy - i <= 0 ) return 0;
		if (map[sy][sx] != map[sy - i][sx + i]) return 0;
	}
	return 1;
}
int Down_Diag(int sy, int sx) { //�Ʒ��� �������� �밢�� Ȯ��
	if (map[sy-1][sx - 1] == map[sy][sx] || map[sy][sx] == map[sy + 5][sx + 5]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sx + i > 19 || sy +i > 19) return 0;
		if (map[sy][sx] != map[sy+i][sx + i]) return 0;
	}
	return 1;
}
int main() {
	int ret1=0, ret2=0, ret3=0, ret4=0; // ���� �Լ��� ���ϰ��� �޾��ش�
	int ans_y, ans_x, ans_val; // ���� y,x�� ��°� ���� �̰���� ������ֱ� ����. 
	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			cin >> map[y][x]; // ���� ��ǥ �Է¹ޱ�
		}
	}
	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			if (map[y][x] == 1 || map[y][x] == 2) { // �ش� ���� 1�̸� ����, 2�� �Ͼ� ��, 0�̸� �ƹ����� ���°Ŷ� �˻����
				ret1=Garo(y, x); //���� �˻�
				ret2=Sero(y, x); //���� �˻�
				ret3=Up_Diag(y, x); //�밢 �˻�
				ret4=Down_Diag(y, x);
			}
			if (ret1==1 || ret2==1 || ret3==1 || ret4==1) { // �� �Լ� �˻� ��� �ϳ��� 1�� ���ϵǸ� ����� �����. 
				ans_y = y; //��½� ���´� y��ǥ
				ans_x = x; //x��ǥ �������ְ�
				ans_val = map[y][x]; // � ���� ����ߴ��� �������ش�. 
				break;
			}
		}
		if (ret1==1 || ret2==1 || ret3==1 || ret4==1) break;
	}
	if (ret1 == 1 || ret2 == 1 || ret3 == 1 || ret4 == 1) {
		cout << ans_val << endl; //���
		cout << ans_y << " " << ans_x << endl;
	}
	else cout << 0;
	return 0; 

}