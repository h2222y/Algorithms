//�ڵ��� ���
#include <iostream>
using namespace std;

int main() {
	int n, time;
	cin >> n;
	int sum_y = 0, sum_m=0;
	for (int i = 0; i < n; i++) {
		cin >> time;
		sum_y += 10 + time / 30 * 10; //30�� �̻� ����ϸ� 30�ʸ��� 10��
		sum_m += 15 + time / 60 * 15;// 60�� �̻� ����ϸ� 60�ʸ��� 10��
	}
	if (sum_y < sum_m) {
		cout << "Y ";
		cout << sum_y; //������ �θ� ���� �����
	}
	if (sum_m < sum_y) {
		cout << "M "; 
		cout << sum_m; //�ν��� �θ� �ν� �����
	}
	if (sum_y == sum_m) {
		cout << "Y M "; 
		cout << sum_y; //������ ���ĸ��� ����ϰ� �ջ� �ݾ� ���
	}



	return 0;
}