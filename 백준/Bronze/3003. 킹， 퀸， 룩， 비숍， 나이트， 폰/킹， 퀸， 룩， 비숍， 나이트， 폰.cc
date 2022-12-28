#include <iostream>
using namespace std;

int white_pin[6] = { 1,1,2,2,2,8 };
int ans[6];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 6; i++) {
		int piece;
		cin >> piece;
		ans[i] = white_pin[i] - piece;
	}
	for (int i = 0; i < 6; i++) {
		cout << ans[i]<<" ";
	}
	return 0;

}