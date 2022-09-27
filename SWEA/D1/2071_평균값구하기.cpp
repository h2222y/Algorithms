#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		double sum =0, avg =0;
		while (!v.empty()) {
			v.pop_back();
		}
		for (int i = 0; i < 10; i++) {
			double num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < 10; i++) {
			sum += v[i];
		}
		avg = round(sum / 10);

		cout << "#" << T << " " << avg << "\n";


	}

	return 0;
}