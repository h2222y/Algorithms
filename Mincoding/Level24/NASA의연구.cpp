#include <iostream>
#include <string>
using namespace std;
int dat[200];

int main() {
	string str;
	cin >> str;
	char max_val = -9999, min_val = 9999;
	char max_alpha = -9999,min_alpha = 9999;
	for (int i = 0; i < str.length(); i++) {
		dat[str[i]]++;
	}
	for (int i = 'A'; i <= 'K'; i++) {
		if (dat[i] > max_val) {
			max_val = dat[i];
			max_alpha = i;
		}
		if (dat[i] < min_val) {
			min_val = dat[i];
			min_alpha = i;
		}
	}
	cout << max_alpha << "\n" << min_alpha;
	
	return 0; 
}