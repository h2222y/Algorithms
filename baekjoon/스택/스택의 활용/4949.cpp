#include <iostream>
#include <string>
#include <stack>
using namespace std;
//균형잡힌 세상

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str; // 입력받을 문자열
	while (1) {
		getline(cin, str); //띄어쓰기를 포함해서 입력 받아야 함
		if (str[0] == '.') break; //. 한개가 들어오면 종료
		stack<char> S; // 스택을 통해 구현
		bool flag = false; // flag를 통해 괄호 쌍이 맞는지 아닌지를 판별
		for (int i = 0; i < str.length(); i++) { //길이 만큼
			if (str[i] == '(') { // (이면 스택에 담기
				S.push(str[i]);
			}
			else if (str[i] == '[') { // [이면 스택에 담기
				S.push(str[i]);
			}
			if (str[i] == ')') { //닫는 괄호가 ) 일 때
				if (!S.empty() && S.top() == '(') S.pop(); // 스택이 비어있지 않고, 이 전에 (라면
				else {
					S.push('n'); // 스택에 이상한 값 담기
					flag = false; // flag를 false로 변경
					break;
				}
			}
			if (str[i] == ']') { //닫는 괄호가 ] 일 때
				if (!S.empty() && S.top() == '[') { // 스택이 비어있지 않고, [라면
					S.pop(); // 앞에 담긴 괄호 빼주기
				}
				else {
					S.push('n'); //스택에 이상한 값 넣어주기
					flag = false; //flag를 false로
					break;
				}
			}
		}
		if (S.empty()) { //스택이 모두 비어있다면
			flag = true; // flag는 true이다
		}
		else flag = false; // 비어있지 않다면 false
		if (flag == true) cout << "yes\n"; //flag가 true일 경우 yes 출력
		else cout << "no\n"; //flag가 false일 경우 no 출력
	}
	return 0;
}