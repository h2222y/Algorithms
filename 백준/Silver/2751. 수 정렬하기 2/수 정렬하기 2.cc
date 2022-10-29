#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	int n;
	cin >> n;
	int num;

	while (n--) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << "\n";
	}
	return 0; 
}