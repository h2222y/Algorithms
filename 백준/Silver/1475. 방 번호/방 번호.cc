#include <iostream>
#include <string>
using namespace std;
int cnt[10];
int max_val = -999999;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string room_num = to_string(n);
	for (int i = 0; i < room_num.length(); i++) {
		cnt[room_num[i] - '0']++;
	}

	cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
	cnt[9] = cnt[6];
	
	for (int i = 0; i < 10; i++) {
		if (cnt[i] > max_val) {
			max_val = cnt[i];
		}
	}

	cout << max_val;


	return 0;
}