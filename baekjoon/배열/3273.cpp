#include <iostream>
#include <algorithm>
using namespace std;

// �� ���� ��
// �ð��ʰ� ����ؼ� �� ������ �˰��� �̿�

int main() {
	int n,x; // ������ ���� n, �� x
	cin >> n;
	int cnt = 0;//�� x�� ��ġ�ϴ� �� ���� ������
	int arr[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // �Է¹ޱ�
	}
	cin >> x; // x �Է¹ޱ�
	sort(arr, arr + n); //������������ ����
	
	int i = 0, j = n - 1;
	while (1) {
		int sum = arr[i] + arr[j]; // �ձ��ϱ�
		if (i >= j) break; // �� �����Ͱ� �ں��� ũ�ų� �������� ����
		if (sum == x) { 
			cnt++;
			i++;
			j--;
		}
		else if (sum < x) {
			i++;
		}
		else j--;

	}
	cout << cnt;
	return 0;
}