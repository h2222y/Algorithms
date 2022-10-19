#include <iostream>
#include <string>
using namespace std;
string str[10];

bool Letter(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z')) return false;
	}
	return true;
}
bool Count(string str) {
	int dat[200] = {};
	for (int i = 0; i < str.length(); i++) {
		dat[str[i]]++;
	}
	for (int i = 0; i < 200; i++) {
		if (dat[i] > 2) return false;
	}
	return true;
}
int Vowel(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			cnt++;
	}
	return cnt;

}
int main() {
	// ���� �̸�? 
	// 1. �ҹ��ڸ� ��� ����
	// 2. Ư������ ������
	// 3. ���� ���ĺ� 2�� ���ϸ� ����
	// 4. ���� a,e,i,o,u�� �ߺ� ���� 3�� ���
	int n;
	cin >> n;
	bool flag = true;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		flag = Letter(str[i]);
		if (flag == false) {
			cout << "no\n";
		}
		if (flag == true) {
			flag = Count(str[i]);
			if (flag == false) {
				cout << "no\n";
			}
		}
		if (flag == true) {
			if (Vowel(str[i]) != 3) {
				flag = false;
				cout << "no\n";
			}
		}
		if(flag==true) cout << "good\n";
	}
	

	
	return 0; 
}