#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define ll long long 
string s;
ll ans = 0;
stack <char> st;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s; // 괄호쌍을 입력받는다
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') // 만약 여는 괄호면 스택에 담는다.
			st.push(s[i]);
		else { // 닫는 괄호라면
			if (s[i - 1] == '(') { // 레이저인지 확인한다.
				st.pop(); // 레이저라면 스택에서 여는 괄호를 꺼내고
				ans += st.size(); //스택에 담겨져 있는 막대기만큼 정답에 더한다.
			}
			else { // 레이저가 아니라면
				st.pop(); // 자투리를 꺼내고 
				ans++; // 한 개를 증가시켜준다.
			}
		}
	}
	cout << ans << "\n";
	return 0;
}