#include <iostream>
#include <algorithm>
using namespace std;
//ī�� ����ġ

int main() {
	int num[21] = { 0 };
	for (int i = 1; i <= 20; i++) {
		num[i] = i; //1~20������ ī�� �Է¹���
	}
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b; //a�� b �Է� (�����Է�)
		for (int j = a; j <= b; j++) {
			for (int k = j + 1; k <= b; k++) {
				if (j + k == a + b) { //�ε����� ���� a+b�� ������ ����Ī
					int temp = num[j];
					num[j] = num[k];
					num[k] = temp;
				}
			}
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout<<num[i]<<" ";
	}
	return 0;
}