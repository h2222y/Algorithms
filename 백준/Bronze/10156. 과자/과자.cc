#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	int price;
	price = k * n;
	if (price-m >= 0) cout << price - m;
	else cout << 0;

	return 0;
}