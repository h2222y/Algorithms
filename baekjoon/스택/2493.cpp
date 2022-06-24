#include <iostream>
#include <stack>
using namespace std;
#define X first // pair�� first �� second�� ���ϰ� ����ϱ� ���� ����
#define Y second // ���� ����

int n; // Ÿ���� ���� 
stack<pair<int, int>> S; // Ÿ���� ���̸� �Է¹��� ����

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; //Ÿ���� ���� �Է�
	S.push({ 100000001,0 }); //pair ���� �ִ� ���̺��� 1ū ���̿� ���� ��ǥ 
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height; //���� �Է¹���
		while (S.top().X < height)  // ������ ���� ���� �Է¹��� height ���� �۴ٸ� pop
			S.pop(); // ū ���� �߰��Ҷ����� pop�� ���ش� 
		cout << S.top().Y << " "; // ���� ���� ���� ��ǥ���� ���� Ÿ���� ���� ���
		S.push({ height,i }); // �Է� ���� ���̿� Ÿ���� ��ǥ
	}

	return 0;
}