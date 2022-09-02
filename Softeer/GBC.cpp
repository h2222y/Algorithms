#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, length, velocity, ans;

int main() {
	cin >> n >> m;
	vector<int> range, test; // 범위 벡터와 test 벡터 생성
	while (n--) {
		cin >> length >> velocity; // 길이와 속도 입력
		while (length--) range.push_back(velocity); // 벡터에 담기
	}
	while (m--) {
		cin >> length >> velocity; // 길이와 속도 입력
		while (length--) test.push_back(velocity); // 벡터에 담기
	}
	for (int i = 0; i < 100; i++) {
		ans = max(ans, test[i] - range[i]); // 같은 인덱스에 있는 값을 빼준뒤 max값을 구한다.
	}
	cout << ans;
	return 0;
}