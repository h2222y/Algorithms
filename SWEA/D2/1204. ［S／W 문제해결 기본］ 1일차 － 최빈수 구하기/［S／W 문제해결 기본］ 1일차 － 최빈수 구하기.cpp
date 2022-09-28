#include <iostream>
using namespace std;

int arr[1000];
int dat[102];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int tc_num;
		cin >> tc_num;
		fill(dat, dat + 102, 0);
		int max_val = -9999999;
		int ans_idx = 0;
		for (int i = 0; i < 1000; i++) {
			cin >> arr[i];
			dat[arr[i]]++;
		}
		for (int i = 0; i < 102; i++) {
			if (dat[i] >= max_val) {
				max_val = dat[i];
				ans_idx = i;
			}
		}
		cout <<"#"<<tc_num<<" "<< ans_idx << "\n";

	}
	return 0;
}