#include <iostream>
#include <algorithm>
using namespace std;

int bene[1000004];

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n;
		cin >> n;
		int max_val = -999999;
		long long ans = 0;

		for (int i = 1; i <= n; i++) {
			cin >> bene[i];
		}
		for (int i = n; i >= 1; i--) {
			if (bene[i] > max_val) {
				max_val = bene[i];
			}
			ans += max_val - bene[i];
		}
		cout <<"#"<<T<<" "<< ans << "\n";

	}
	return 0; 
}