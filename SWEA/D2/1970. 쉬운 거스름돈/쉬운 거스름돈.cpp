#include <iostream>
using namespace std;

int money_list[8] = { 50000,10000,5000,1000,500,100,50,10 };
int cnt[8] = {};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n;
		cin >> n;
		fill(cnt, cnt + 8, 0);
		for (int i = 0; i < 8; i++) {
			if (money_list[i] <= n) {
				while (money_list[i] <= n && n!=0) {
					n -= money_list[i];
					cnt[i]++;
				}
			}
		}
		cout << "#" << T << "\n";
		for (int i = 0; i < 8; i++) {
			cout << cnt[i] << " ";
		}
		cout << "\n";
	}
	
	return 0; 
}