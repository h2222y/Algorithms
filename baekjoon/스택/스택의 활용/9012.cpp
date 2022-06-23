#include <iostream>
#include <stack>
#include <string>
using namespace std;
//괄호

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // 입력받을 문자열의 개수를 입력받는다
	while (n--) {
		stack<char> S; // 스택을 사용하여 구현할 것이다.
		string str;
		cin >> str; //문자열을 입력받는다
		for (int i = 0; i < str.length(); i++) {
			if(str[i]==')'){ //만약 닫힌 괄호를 발견한다면
				if (!S.empty() && S.top() == '(') { // 스택이 비어 있지 않고, 직전 입력값이 (면 (를 지워준다.
					S.pop();
				}
				else S.push(str[i]); // 만약 위 조건에 해당되지 않으면 값을 넣어서 스택이 비어있지 않게 만들어준다.
			}
			else S.push(str[i]); //이외에는 (인 경우만 있으므로 스택에 넣어준다.
		}
		if (S.empty()) cout << "YES\n"; //배열이 모두 비면 괄호 쌍이 잘 맞는 것
		else cout << "NO\n"; //이 외에는 NO를 출력

	}
	return 0;
}