#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int max_val = -9999, min_val = 99999;
	int max_idx = 0, min_idx = 0;
	for (int i = 0; i < 4; i++) {
		cin >> str;
		int len = str.length();
		if (max_val < len) {
			max_val = len;
			max_idx = i;
		}
		if (min_val > len) {
			min_val = len;
			min_idx = i;
		}
	}
	cout << "긴문장:" << max_idx << "\n";
	cout << "짧은문장:" << min_idx;
	return 0; 
}