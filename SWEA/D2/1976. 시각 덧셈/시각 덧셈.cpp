#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int h1, h2, m1, m2;
		cin >> h1 >> m1 >> h2 >> m2;
		int ans_hour=0, ans_min = 0;
		ans_hour = h1 + h2;
		ans_min = m1 + m2;
		if (ans_min >= 60) {
			ans_hour += ans_min / 60;
			ans_min = ans_min % 60;
		}
		if (ans_hour > 12) {
			ans_hour -= 12;
		}
		cout << "#" << T << " " << ans_hour << " "<<ans_min<<"\n";
	}
	return 0;
}