#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int> v;
		int sum = 0;
		int min_val = 9999;
		for (int i = 0; i < 7; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] % 2 == 0) {
				sum += v[i];
				min_val = min(min_val, v[i]);
			}
		}
		cout << sum << " " << min_val << "\n";
	}

	return 0;
}