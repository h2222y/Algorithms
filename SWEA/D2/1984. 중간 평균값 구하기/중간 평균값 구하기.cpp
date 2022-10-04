#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		v.clear();
		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		double average = 0;
		double sum = 0;

		for (int i = 1; i < 9; i++) {
			sum += v[i];
		}
		average = sum / 8.0;
		cout << "#" << T << " " << round(average) << "\n";
	}
	return 0; 
}