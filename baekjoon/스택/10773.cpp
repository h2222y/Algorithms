#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	stack<int> S;
	int sum = 0;
	while (k--) {
		int n;
		cin >> n;
		if (n == 0) {
			if (S.empty())
				cout << 0; //비었을 경우 처리
			else {
				sum -= S.top(); //0을 입력할경우 가장 최신값을 합에서 뺀 후
				S.pop(); //가장 최신값을 제거
			}
		}
		else {
			S.push(n); //0이 아닌 수의 경우 값을 넣어준 뒤
			sum += S.top(); //가장 최신 값을 합에 추가
		}
	}
	cout << sum;
	return 0;
}