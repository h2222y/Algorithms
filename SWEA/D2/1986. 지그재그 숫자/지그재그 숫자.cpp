#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		v.clear();
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] % 2 == 0)
				ans -= v[i];
			else
				ans += v[i];
		}
		cout << "#" << T << " " << ans<<"\n";
	}
	return 0; 
}