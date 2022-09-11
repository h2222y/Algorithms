#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;


int main() {
	string n, m;
	cin >> n >> m;
	long long ans =0;
	for (int i = 0; i < n.length(); i++) {
		for (int j = 0; j < m.length(); j++) {
			 ans += (n[i] - '0') * (m[j] - '0');
		}
	}
	cout << ans;
	return 0; 
}