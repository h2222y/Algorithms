#include <iostream>
#include <string>
#include <vector>
using namespace std;
int bucket[200];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int max = -9999;
	char max_idx = 0;
	bool flag = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			bucket[str[i] - 'a'+'A']++;
		}
		else bucket[str[i]]++;
	}
	for (int i = 0; i < 200; i++) {
		if (bucket[i] > max) {
			max = bucket[i];
			max_idx = i;
			flag = false;
		}
		else if (bucket[i] == max) {
			flag = true;
		}
	}
	if (flag==true) cout << "?";
	else cout << max_idx;

	return 0;
}