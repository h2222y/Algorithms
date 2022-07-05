#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define X first
#define Y second
#define ll long long 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int mx = -999;
	while (1) {
		cin >> n; // 직사각형의 개수를 입력받는다.
		int cnt = 1;
		// mx = -999;
		if (n == 0) return 0;
		// vector<int> ans = { 0 };
		stack <pair<ll, ll>> S;
		ll ans=0; // 정답은 long long 값
		for (int i = 0; i < n; i++) {
			int height; 
			cin >> height; //각각의 높이를 입력받는다.
			int idx = i; //현재 i가 인덱스 값으로 들어감
			while (!S.empty() && S.top().X >= height) { // 스택이 비어있지 않고 스택의 top값이 현재 높이보다 크거나 같다면
				ans = max(ans, (i - S.top().Y) * S.top().X); // 넓이의 최대값을 구한다. 
				// 현재 i의 값에서 스택의 idx값을 빼주고 높이를 곱해준다 
				idx = S.top().Y; // 인덱스를 현재 스택의 맨 위의 값으로 갱신해준다.
				S.pop(); // 스택의 top값을 꺼내준다
			}
			S.push({ height,idx }); // 높이와 인덱스값 넣기
		}
		while (!S.empty()) {
			ans = max(ans, (n - S.top().Y) * S.top().X); // 위 과정을 마치고 스택이 비어있지 않다면,
			// 전체 높이의 개수 n에서 스택에 남아있는 값으로 넓이를 구했을때 최대값이 되는지 확인한다. 
			S.pop();
		}
		cout << ans << "\n";
	}

	return 0;
}