//주사위 세개
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	// 같은 눈이 3개가 나오면 10000원 + 같은눈*1000원
	// 같은 눈이 2개가 나오면 1000원 + 같은눈*100원
	// 모두 다른 눈이 나오면 그중 가장 큰눈*100원
	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a == b || a == c) {
		cout << 1000 + a * 100;
	}
	else if (b == c) {
		cout << 1000 + b * 100;
	}
	else {
		if (a > b && a > c) {
			cout << a * 100;
		}
		else if (b > a && b > c) {
			cout << b * 100;
		}
		else if (c > a && c > b) {
			cout << c * 100;
		}
	}
	return 0;
}