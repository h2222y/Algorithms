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
		int sum = 0;
		while (!v.empty()) {
			v.pop_back();
		}
		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < 10; i++) {
			if (v[i] % 2 != 0) {
				sum += v[i];
			}
		}
		cout << "#" << T << " " << sum<<"\n";
	}
	return 0;
}