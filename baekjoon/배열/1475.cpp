#include <iostream>
#include <string>
using namespace std;
//���ȣ
// 0~9���� ���� �ö�ƽ ī�尡 �� ��Ʈ
// �� ��ȣ�� �־����� �ּҷ� �ʿ��� ��Ʈ�� ������?
// 6�� ����� 9�� �̿밡�� ����,6�� 2���� ��Ʈ 1���� ������ �ȴ�.

int main() {
	string room_num;
	cin >> room_num; //���ȣ �Է�
	int num[10] = { 0 }; //�ö�ƽ 1��Ʈ
	int max_val = -9999; // �ּҷ� �ʿ��� ���� 
	for (int i = 0; i < room_num.length(); i++) {
		num[room_num[i]-'0']++; //���̸�ŭ ī�� ���� ī����
	}
	num[6] = (num[6] + num[9] + 1) / 2; // ���� 6�̶� 9���� +1�� 2�� ������ �ʿ��� ��Ʈ��
	num[9] = num[6]; // 9�� 6�̶� ���� �� ������ �� �� �ϳ��� ������ �� ����
	for (int i = 0; i < 10; i++) {
		if (num[i] > max_val) max_val = num[i]; //�ִ� ī�� ���� ã��
	}
	cout << max_val; //��� 

	return 0;
}