#include <iostream>
#include <string>
using namespace std;
int arr[1000];

int main() {
	string s;
	cin >> s;
	fill(arr, arr + 1000, -1);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (arr[s[i] - 'a'] > -1) continue;
			arr[s[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i]<<" ";
	}

	return 0;

}
