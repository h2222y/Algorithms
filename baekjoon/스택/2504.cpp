#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char> s;
string str;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int sum = 0; // 누적 합
	int mul = 1; // 누적 곱
	for (int i = 0; i < str.length(); i++) { // 입력받은 길이만큼
		if (str[i] == '(') { // 여는 ( 괄호이면
			s.push(str[i]); // 스택에 값을 넣고
			mul *= 2; // 2를 곱해준다
		}
		else if (str[i] == '[') { // 여는 [ 괄호이면
			s.push(str[i]); // 스택에 값을 넣고
			mul *= 3; // 3을 곱해준다
		} 
		else if (str[i] == ')') { //닫는 ) 괄호일 때
			if (s.empty() || s.top() != '(') { // 스택이 비어있고 ( 괄호가 아니면
				cout << 0; //올바른 괄호쌍이 아니므로 종료 
				return 0;
			}
			if(str[i-1]=='(') sum += mul; // ()와 같은 형식일때만 sum에 지금까지 곱한값을 더해준다
			s.pop(); // 스택에서 여는괄호를 빼주고
			mul /= 2; // 괄호를 닫았으므로 2로 나눠준다.
		}
		else { // 닫는 ] 괄호일 때 
			if (s.empty() || s.top() != '[') { // 괄호 쌍 맞지 않으면 종료 
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += mul; // [] 일 경우에만 sum에 지금까지 곱한 값 더하기
			s.pop(); // 스택에서 값을 뺴주고
			mul /= 3; // 괄호를 닫았으므로 3으로 나눠준다. 
		}
	}
	if (s.empty()) cout << sum; //스택이 모두 비었으면 모두 올바른 괄호쌍이므로 답을 출력한다.
	else cout << 0; // 스택이 비지 않으면 짝이 맞지 않는 괄호쌍이 존재하는 것
}