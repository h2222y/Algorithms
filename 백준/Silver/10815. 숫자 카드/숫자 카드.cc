#include <iostream>
#include <map>
using namespace std;

int n, m;
int num;
map<int, int> map_num;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num; // 숫자를 입력받는다
		map_num[num]++; // 해당 인덱스의 개수 증가
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (map_num[num] > 0)cout << 1 << " "; // 만약 해당 인덱스의 개수가 1이상이면 가지고 있는 것
		else cout << 0<<" "; // 아니라면 가지고 있지 않다
	}
	return 0;
}