/* 문제를 이해하는데 오래 걸렸는데,
	예를 들어 8 4 3 6 8 7 5 2 1을 입력으로 넣으면(8은 수열의 크기 n)
	4 3 6 8 7 5 2 1이라는 수열을 오름차순으로 정렬된 스택을 이용해 구현할 수 있는지
	확인하는 것이다.
	4를 수열에 넣기 위해서 stack에 1 2 3 4를 순서대로 push하고, 4를 pop해서 꺼내오고 
	3을 pop하고, 수열에 6을 넣기 위해서 다시 5 6을 stack에 push하고, 6을 pop 하는 것이다. */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // 수열의 크기

	stack<int> S; //입력 받을 stack 
	int cnt = 1; // cnt와 수열의 값을 비교해 줄 것 (Stack은 오름차순으로 값 넣음)
	string ans; // 값을 저장할 문자열 

	while(n--) {
		int k; // 수열의 각 값
		cin >> k;
		while (cnt <= k) { // 수열의 값보다 cnt가 작으면
			S.push(cnt++); //1부터 넣어주고 증가
			ans += "+\n"; //push 했음을 정답에 넣기
		}
		if (S.top() != k) { // stack의 top 값이 k와 같지 않다면, 
			cout << "NO\n"; // NO 출력하고
			return 0; //즉시 종료
		}
		S.pop(); // 그 외에는 pop해서 수열 만들어주기
		ans += "-\n"; //pop 했음을 알려줌
	}
	cout << ans;
	
	return 0;
}