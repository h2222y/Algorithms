#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	string ans = "CHRISTMAS";
	string word[100];
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < n; d++) {
					string temp = word[a] + word[b] + word[c] + word[d];
					if (temp == ans) cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0; 
}