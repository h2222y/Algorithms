#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str[20004];
int length[20004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, string>> v;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(make_pair(s.length(), s));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << "\n";
	}
	


	return 0;
}
