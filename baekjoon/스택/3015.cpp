#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second
#define ll long long 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; //사람 수 입력받기
	cin >> n;
	stack<pair<int, int>> S;
	ll ans = 0; 

	while (n--) {
		int now;
		cin >> now; //각 사람의 키 입력
		int cnt = 1; // 1부터 카운트
		while (!S.empty() && S.top().X <= now) { // 스택이 비지 않고 스택 맨 위 키가 현재 키보다 작거나 같을때
			ans += S.top().Y; // 정답에 카운트값 합하기
			if (S.top().X == now) cnt += S.top().Y; // 키가 같을때는 카운트값에 현재 카운트값 더하기
			S.pop();
		}
		if (!S.empty()) ans++; // 현재 가장 큰 사람이 볼 수 있는 사람 수 세기
		S.push({ now,cnt }); //스택에 현재 값 넣기
	}
	cout << ans; //전체 쌍의 개수 출력
	return 0;
}