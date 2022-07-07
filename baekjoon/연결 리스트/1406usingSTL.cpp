#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	list<char> Li;
	for (auto c : s) Li.push_back(c); //�ʱ� �����⿡ �ԷµǾ� �ִ� ���ڿ�
	list<char>::iterator t = Li.end(); //Ŀ���� �� �������� ����Ŵ
	
	int m;
	cin >> m; //�Է��� ��ɾ��� ���� 
	
	for (int i = 0; i < m; i++) {
		char command, dollar;
		cin >> command; //��ɾ� �Է�
		if (command == 'P') {
			cin >> dollar; //�߰��� ����
			Li.insert(t, dollar); //���ϴ� ��ġ�� �߰��Ѵ�.
		}
		else if (command == 'L') {
			if(t!=Li.begin()) t--; // �� ���� �ƴϸ� Ŀ���� �� ĭ ��������
		}
		else if (command == 'D') {
			if (t != Li.end())t++; // �� �ڰ� �ƴϸ� Ŀ���� �� ĭ ����������
		}
		else if (command == 'B') {
			if(t!=Li.begin()){ // �� ���� ���� �ƴϸ�
			t--; //Ŀ���� �� ĭ �������� ����
			t = Li.erase(t); // ���� ���� ���� ���� ��ġ�� �޾ƿ�
			} 
		}
	}
	for (auto c : Li)cout << c;
	return 0;
}