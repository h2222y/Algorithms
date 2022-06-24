#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
int ans[1000000];

int main() {
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //배열에 숫자 입력받기
	}
	stack<int> s; //스택으로 수 체크
	for (int i = n - 1; i >= 0; i--) { //오른쪽부터
		while (!s.empty() && s.top() <= arr[i]) s.pop(); // 해당 값보다 스택의 값이 작거나 같으면 pop
		if (s.empty()) { //스택이 비어있으면 -1 
			ans[i] = -1; 
		}
		else { // 스택이 비어있지 않으면 정답 배열에 스택의 맨 위의 값 넣기
			ans[i] = s.top();
		}
		s.push(arr[i]); // 스택에 순열 넣기(오른쪽부터)
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0; 
}