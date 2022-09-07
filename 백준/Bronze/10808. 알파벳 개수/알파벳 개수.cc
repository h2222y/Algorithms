#include <iostream>
#include <string>
using namespace std;

int main() {
	char arr[100] = { 0 };
	char t = 'a';
	int bucket[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		arr[i] = t;
		t++;
	}

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == arr[j]) {
				bucket[j]++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << bucket[i] << " ";
	}
	return 0;
}