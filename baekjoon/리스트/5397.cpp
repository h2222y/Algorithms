#include <iostream>
#include <string>
#include <list>
using namespace std;
//Ű�ΰ�
	//�齺���̽��� �Է��ߴٸ� '-', Ŀ���� �ٷ� �տ� ���ڰ� �����Ѵٸ� �� ���ڸ� �����.
	// ȭ��ǥ�� �Է��ߴٸ� < �� >�� �־�����.
	// ����Ű��ŭ �̵��Ѵ�.
	// ������ ���ڴ� ��й�ȣ�� �Ϻ��̴�.

int main() {
	int T;
	cin >> T; // �׽�Ʈ���̽��� ���� �־�����.

	for (int tc = 0; tc < T; tc++) {
		string str; // �����̰� �Է��� ���ڿ��� �־�����.
		list<char> L = {};
		auto cursor=L.begin(); //Ŀ���� ó�� ��ġ�� �� ó�� ��ġ
		cin >> str; //���ڿ��� �Է¹޴´�
		 
		for (auto c : str) { //���ڿ��� ���鼭
			if (c == '<') { //�ش� ���ڰ� <��� 
				if (cursor != L.begin()) {
					cursor--; //�������� Ŀ���̵�
				}
			}
			else if (c == '>') { //�ش� ���ڰ� >���
				if (cursor != L.end()) {
					cursor++; //���������� Ŀ���̵�
				}
			}
			else if (c == '-') { //�ش� ���ڰ� -���
				if (cursor != L.begin()) {
					cursor--; //Ŀ���� �������� �̵��ϰ�
					cursor = L.erase(cursor); //�ش� ������ ���� ����� Ŀ���� �̵���Ų��.
				}
			}
			else L.insert(cursor, c); //�ش� Ŀ���� ���� ���ڰ� ������ �ش� ���� ����Ʈ�� ��´�
		}

		for (auto c : L) cout << c; //����Ʈ�� ����Ѵ�.
		cout << "\n";
	}



	return 0;
}