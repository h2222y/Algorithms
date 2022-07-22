//핸드폰 요금
#include <iostream>
using namespace std;

int main() {
	int n, time;
	cin >> n;
	int sum_y = 0, sum_m=0;
	for (int i = 0; i < n; i++) {
		cin >> time;
		sum_y += 10 + time / 30 * 10;
		sum_m += 15 + time / 60 * 15;
	}
	if (sum_y < sum_m) {
		cout << "Y ";
		cout << sum_y;
	}
	if (sum_m < sum_y) {
		cout << "M ";
		cout << sum_m;
	}
	if (sum_y == sum_m) {
		cout << "Y M ";
		cout << sum_y;
	}



	return 0;
}