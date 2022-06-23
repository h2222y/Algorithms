#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; //명령어의 개수
	int cnt = 0;
	while (n--) {
		stack<char> S; //스택을 이용한다. FILO
		string str;
		cin >> str; //명령어를 입력받는다. 
		for (int i = 0; i < str.length(); i++) {
			if (!S.empty() && S.top() == str[i]) S.pop(); // 스택이 비어있지 않고, 현재 값과 스택의 top값이 같다면 pop
			else S.push(str[i]); // 위의 조건에 해당하지 않으면 스택에 값 push
		}
		if (S.empty()) cnt++; // 스택이 모두 비어있으면 카운트+1
	}
	cout << cnt;

}