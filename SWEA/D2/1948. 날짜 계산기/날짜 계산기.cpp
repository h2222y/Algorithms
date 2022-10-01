#include <iostream>
using namespace std;

int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++)
	{
		int start_m, start_d, end_m, end_d;
		cin >> start_m >> start_d >> end_m >> end_d;
		int ans = 0;
		if (start_m == end_m) {
			ans = end_d - start_d+1;
		}
		else {
			ans += days[start_m - 1] - start_d + 1;
			for (int i = start_m; i < end_m-1; i++) {
				ans += days[i];
			}
			ans += end_d;
		}
		cout << "#" << T << " " << ans<<"\n";

	}return 0;
}