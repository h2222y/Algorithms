#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	// 시작은 0:0(자정) 23:59(다음날 자정 1분 전)
	m -= 45;
	if (m < 0) {
		m += 60;
		h--;
	}
	if (h < 0) {
		h = 23;
	}
	cout << h << " " << m;
	return 0;
}