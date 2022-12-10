#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int fake[9] = { 0 };
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> fake[i];
		sum += fake[i];
	}
	sort(fake, fake + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (fake[i] + fake[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					else cout << fake[k] << "\n";
				}
				return 0;
			}
		}
	}
	
	return 0;
}