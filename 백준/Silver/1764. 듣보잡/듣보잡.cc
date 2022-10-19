#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<string> v,ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			ans.push_back(s);
		}
	}

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	

	return 0;
	
}

