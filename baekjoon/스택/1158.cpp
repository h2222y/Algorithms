#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; // 순열의 크기와 제거할 번호의 idx 입력받음
	cin >> n >> k;
	vector<int> v; // 1~n까지 저장할 벡터
	for (int i = 1; i <= n; i++) {
		v.push_back(i); // 벡터에 값 대입
	}

	vector<int> ans; //제거 순서를 저장할 벡터

	for (int i = 0; ans.size()<n; i++) { // ans의 크기가 n 미만일 때까지
		if (i % k == k - 1) ans.push_back(v[i]); // 인덱스는 k-1이므로 i를 k로 나눈 나머지가 k-1일때
		else v.push_back(v[i]); //나머지는 다시 벡터로 넣어줌
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << ans[i];
		else cout << ans[i] << ", ";
	}
	cout << ">";

	return 0;
}