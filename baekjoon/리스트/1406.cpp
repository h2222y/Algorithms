#include <iostream>
#include <list> //list STL ���
#include <string>
using namespace std;
//������

int main() {
	string s;
	cin >> s; //���ڿ� �Է¹���

	list<char> Li; // Linked List ��� 
	list<char>::iterator t=Li.end(); //Ŀ���� �� �������� ����Ű�� �ִ´�

	for (auto c : s) { //���ڿ��� ��� ���ڸ� ����Ʈ�� ��´�.
		Li.push_back(c);
	}

	int m;
	cin >> m; // ��ɾ��� ����

	for (int i = 0; i < m; i++) { // ��ɾ��� ������ŭ
		char command, add; //��ɾ�� �߰��� �ܾ�
		cin >> command; //��ɾ �Է¹޴´�
		if (command == 'P') { //��ɾ P�ϰ�츸 �߰��� ���� �Է�
			cin >> add;
			Li.insert(t, add); //�ش� Ŀ���� ����Ű�� ��ġ�� ���� �߰�
		}
		else if (command == 'L') { //Ŀ���� �� ���� �ƴҰ�� Ŀ���� �� ĭ �̵���Ų��
			if (t != Li.begin()) t--;
		}
		else if (command == 'D') {
			if (t != Li.end()) t++; //Ŀ���� �� �ڰ� �ƴҰ�� Ŀ���� ���������� �� ĭ �̵���Ų��
		}
		else if (command == 'B') {
			if(t!=Li.begin()){ //Ŀ���� �� ���� �ƴҰ��
			t--; //Ŀ���� �� ĭ �������� �̵���Ű��
			t = Li.erase(t); //�ش� ��ġ�� ���� ����� Ŀ���� �ش� ĭ���� 
		}
		}
	}
	for (auto c : Li) cout << c; //����Ʈ�� ��� ���� ����Ѵ�

	return 0;
}