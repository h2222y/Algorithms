#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// �ֳʱ׷� �����
// �� ���� �ܾ��� ö���� ������ �ڹٲپ� ������ �� ������ �ֳʱ׷� ����
// ex) dared bread�� 2�� �����ϸ� ������ �� ����
// �������� ����� ���� �����ؾ��ϴ� �ּ� ������ ���� ���ϱ�

int main() {
	string a, b;
	cin >> a >> b; //���ڿ� �� �� �Է¹ޱ�
	int dat[100] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		dat[a[i] - 'a']++;	// a ���ڿ��� ���� �ε��� ������ �޾� ������Ű��
	}
	for (int i = 0; i < b.length(); i++) {
		dat[b[i] - 'a']--; // b ���ڿ��� ���� �ε��� ������ �޾� ���ҽ�Ű��
	}
	int cnt = 0; //�����ؾ��ϴ� ������ �ּ� ����
	for (int i = 0; i < 100; i++) {
		if (dat[i] != 0) { // ���� 0�̸� �ΰ��� ���ڰ� ��� �������̹Ƿ�
			cnt += abs(dat[i]); //0�� �ƴѼ����� ���밪�� �����ش�
		}
	}
	cout << cnt;
	return 0;
}