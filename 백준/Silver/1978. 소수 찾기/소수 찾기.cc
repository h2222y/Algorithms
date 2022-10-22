#include <iostream>
using namespace std;

int main() {
	int n;
	int ans = 0;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		int cnt = 0;
		for (int i = 1; i <= num; i++) {
			if (num % i == 0)
				cnt++;
		}
		if (cnt == 2) ans++;
	}
	cout << ans;
	return 0; 
}