#include <iostream>
using namespace std;

int paskal[11][11] = {};


int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n;
		cin >> n;
		for (int y = 0; y < n; y++) {
			fill(paskal[y], paskal[y] + n, 0);
		}
		for (int y = 0; y < n; y++) {
			paskal[y][0] = 1;
		}
		for (int y = 0; y < n; y++) {
			int x = y;
			paskal[y][x] = 1;
		}

		for (int y = 2; y < n; y++) {
			for (int x = 1; x < n-1; x++) {
				paskal[y][x] = paskal[y - 1][x - 1]+paskal[y-1][x];
			}
		}
		cout << "#" << T << " \n";
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (paskal[y][x] == 0) continue;
				cout << paskal[y][x]<<" ";
			}
			cout << "\n";
		}
							
	}
	return 0;
}