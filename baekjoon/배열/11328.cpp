#include <iostream>
#include <string>
using namespace std;
//Strfry
// �־��� ���ڿ� �ΰ� �� �� ���ڿ��� ���ڵ��� �������� �̾� �������Ͽ�
// ù ��° ���ڿ��� ���� �� �ִ� ��� Possible
// ���� �� ���� ��� impossible

int main() {
	int n;
	cin >> n; //tc�� ����
	string arr1, arr2; //���ڿ� 2��
	for (int i = 0; i < n; i++) { //������ ������ŭ
		cin >> arr1 >> arr2; //���ڿ� 2�� �Է¹���
		int bucket[100] = { 0 }; //���ڸ� ������ dat �迭
		int flag = 0; //possible impossible ����
		for (int j = 0; j < arr1.length(); j++) {
			bucket[arr1[j] - 'a']++; // arr1�� �ִ� ���ڵ��� dat�� ����
			bucket[arr2[j] - 'a']--; //arr1�� �ִ� ���� -1�� �ϸ� 0�̵ȴ�.
		}
		for (int j = 0; j < 100; j++) {
			if (bucket[j] != 0) { //0�� �ƴϸ� �ٸ� ���� ����
				flag = 1;
				break;
			}
		}
		if(flag==0) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}