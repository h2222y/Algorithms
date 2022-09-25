#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // 수열의 개수 입력
	for (int i = 0; i < n; i++) {
		int num; // 수열 숫자 입력
		cin >> num;
		if (v.empty() || v.back() < num) v.push_back(num); // 벡터가 비어있지 않고,
		// 백터의 맨 마지막 수가 num보다 작다면 넣는다.
		else *lower_bound(v.begin(), v.end(), num) = num;
		// lower_bound는 해당 숫자 이상인값의 인덱스를 반환 
	}
	cout << v.size();
	
	return 0;
}