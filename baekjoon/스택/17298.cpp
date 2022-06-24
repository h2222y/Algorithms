#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
int ans[1000000];

int main() {
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //�迭�� ���� �Է¹ޱ�
	}
	stack<int> s; //�������� �� üũ
	for (int i = n - 1; i >= 0; i--) { //�����ʺ���
		while (!s.empty() && s.top() <= arr[i]) s.pop(); // �ش� ������ ������ ���� �۰ų� ������ pop
		if (s.empty()) { //������ ��������� -1 
			ans[i] = -1; 
		}
		else { // ������ ������� ������ ���� �迭�� ������ �� ���� �� �ֱ�
			ans[i] = s.top();
		}
		s.push(arr[i]); // ���ÿ� ���� �ֱ�(�����ʺ���)
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0; 
}