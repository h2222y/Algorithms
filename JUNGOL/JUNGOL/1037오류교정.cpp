#include <iostream>
using namespace std;

int n;
int arr[101][101] = { 0 }; //n<100

int SumW(); //���� ��
int SumC(); //���� ��
int main() {
	cin >> n;
	for (int y = 1; y <= n; y++) { // �������� �ε��� 1�� �����Ѵٰ� ��õǾ� ����
		for (int x = 1; x <= n; x++) {
			cin >> arr[y][x];
		}
	}
	int retw = 0, retc = 0;
	retw = SumW(); //��
	retc = SumC(); //��
	if (retw == -1 && retc == -1) cout << "OK"; //�Ѵ� -1�̸� ����
	else if (retw >= 0 && retc >= 0) cout << "Change bit (" << retw << "," << retc << ")"; //�Ѵ� 1���̸� ������ �ε��� ������ֱ�
	else cout << "Corrupt"; // �������� corrupt
	return 0;
}
int SumW() {
	int sum = 0;
	int cnt = 0, a;
	for (int y = 1; y <= n; y++) {
		sum = 0;
		for (int x = 1; x <= n; x++) {
			sum += arr[y][x];
		}
		if (sum % 2 != 0) { //¦���� �ƴ� �� ���� ���ϱ�
			cnt++;
			a = y;
		}
	}
	if (cnt == 0) return -1; // ¦���� �ƴ� �� ������
	else if (cnt == 1) return a; //¦���� �ƴ� ���� �� �ϳ� �� ��
	else return -2; // ¦���� �ƴ� �� ������
}
int SumC() {
	int sum = 0;
	int cnt = 0, a;
	for (int x = 1; x <= n; x++) {
		sum = 0;
		for (int y = 1; y <= n; y++) {
			sum += arr[y][x];
		}
		if (sum % 2 != 0) {
			cnt++; //¦���� �ƴ� �� ���� ���ϱ�
			a = x;
		}
	}
	if (cnt == 0) return -1; //¦���� �ƴ� �� ������
	else if (cnt == 1) return a; //¦���� �ƴ� ���� �� �ϳ��� ��
	else return -2; // ¦���� �ƴ� �� ������
}
