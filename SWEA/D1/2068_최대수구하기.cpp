#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;

	for (int T = 1; T <= tc; T++) {
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		int ans = 0;
		for(int i=0;i<10;i++){
			int max_val = arr[i];
			ans = max(ans, max_val);
		}
		cout <<"#" << T<<" " << ans << "\n";
	}

	return 0;
}