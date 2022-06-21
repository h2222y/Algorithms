#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void command(string& tmp, deque<int>& DQ) {
	int cur = 0; 
	for (int i = 1; i + 1 < tmp.size(); i++) {
		if (tmp[i] == ',') { //���� ,�̸� , �տ� ���� DQ�� �ִ´�.
			DQ.push_back(cur);
			cur = 0; //cur�� 0���� �ٽ� �ʱ�ȭ ��Ų��.
		}
		else {
			cur = 10 * cur + (tmp[i] - '0'); // ���� ,�� �ƴϸ� cur�� �ش� ���ڸ� ���ڿ��� ���ڷ� ����
		}
	}
	if (cur != 0) DQ.push_back(cur); // cur�� 0�� �ƴϸ� cur�� �ش� ���� �ִ´�.
}
int main() {
	// AC�� ���� �迭�� ������ �ϱ� ���� ���� ���
	// R(������), D(������)
	// R�� �迭�� �ִ� ���� ������ ������ �Լ�
	// D�� ù ��° ���� ������ �Լ�, �迭�� ����ִµ� D�� ����� ��쿡�� ���� �߻�
	// �Լ��� �����ؼ� �� ���� ����� �� �ִ�.
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T; // �׽�Ʈ ���̽��� ���� �Է¹ޱ�
	bool isWrong = false; // �迭�� ����ִµ� D�� ����� ��� error�� �߻���Ű�� ���� flag

	while (T--) {
		deque<int> DQ; // DQ ����
		string p; 
		cin >> p; // ��ɾ� �Է�
		int n;
		cin >> n; // �迭�� ����ִ� ���� ���� �Է�
		string tmp;
		cin >> tmp; // �迭�� �ִ� �� �Է¹ޱ�
		isWrong = false; // flag�� false�� ����
		int rev = 0; 
		command(tmp, DQ); // command �Լ� ȣ��
		for (int i = 0; i < p.length(); i++) {
			//int pos = p.length();
			if (p[i] == 'R') {
				rev = 1 - rev; // R�� ��� �迭�� �����´�.
			}
			if (p[i] == 'D') { // D�� ���
				if (DQ.empty()) { // �迭�� ����� ��� ����� �������� ���ϱ� ������ 
					isWrong = true; //error�� ����Ѵ�. 
					break;
				}
				if (!rev) DQ.pop_front(); // rev==0�� ��� ���� ���� ����
				else DQ.pop_back(); // rev==0�� �ƴ� ��� ���� ���� ����
			}
		}
		if (isWrong == true) { // Ʋ���� error ���
			cout << "error\n";
		}
		else { //Ʋ���� �ʾ��� ���
			if (rev) reverse(DQ.begin(), DQ.end()); //rev�� 0�� �ƴҰ�� �����´�.
			cout << "[";
			for (int i = 0; i < DQ.size(); i++) {
				cout << DQ[i];
				if (i + 1 != DQ.size()) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}