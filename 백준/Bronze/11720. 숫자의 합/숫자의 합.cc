#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> v; 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string num;
	cin >> n;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		v.push_back(num[i] - '0');
	}
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum;

	return 0; 
}