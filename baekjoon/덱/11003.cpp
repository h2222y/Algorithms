#include <iostream>
#include <deque>
#include <utility>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l; // ������ ���� n�� �� �� l�� �־�����.
	deque<pair<int,int>> DQ; // deque<index,number>
	for (int i = 1; i <= n; i++) { //idx�� 1���� n����
		int num;
		cin >> num; // ���� �Է�
		while (!DQ.empty() && DQ.back().Y >= num) { //���� DQ�� ������� �ʰ�, DQ�� �� �� ���� num�� ���� num���� ũ�ų� ���ٸ� 
			DQ.pop_back(); // �ش� ���� ���� (�ּڰ��� ����)
		}
		DQ.push_back({ i,num }); // DQ�� ���� ���� �ε����� ��´�.
		if (DQ.front().X <= i - l) DQ.pop_front(); // A(i-L+1)~Ai������ �ּڰ��� ���ؾ� �ϹǷ�
		// �ش� �������� ����� ���� DQ���� �������ش�.
		cout << DQ.front().Y << " "; // DQ�� front�� number ���� ������ش�.
	}
	return 0;
}