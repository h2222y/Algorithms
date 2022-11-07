#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int sum_y = 0, sum_k = 0;
		for (int j = 0; j < 9; j++) {
			int y, k;
			cin >> y >> k;
			sum_y += y;
			sum_k += k;
		}
		if (sum_y > sum_k) cout << "Yonsei\n";
		else if (sum_y < sum_k) cout << "Korea\n";
		else cout << "Draw\n";
	}
	return 0; 
}