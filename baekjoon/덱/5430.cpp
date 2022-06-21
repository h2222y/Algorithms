#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void command(string& tmp, deque<int>& DQ) {
	int cur = 0; 
	for (int i = 1; i + 1 < tmp.size(); i++) {
		if (tmp[i] == ',') { //만약 ,이면 , 앞에 수를 DQ에 넣는다.
			DQ.push_back(cur);
			cur = 0; //cur를 0으로 다시 초기화 시킨다.
		}
		else {
			cur = 10 * cur + (tmp[i] - '0'); // 만약 ,가 아니면 cur은 해당 숫자를 문자에서 숫자로 변경
		}
	}
	if (cur != 0) DQ.push_back(cur); // cur이 0이 아니면 cur의 해당 값을 넣는다.
}
int main() {
	// AC는 정수 배열에 연산을 하기 위해 만든 언어
	// R(뒤집기), D(버리기)
	// R은 배열에 있는 수의 순서를 뒤집는 함수
	// D는 첫 번째 수를 버리는 함수, 배열이 비어있는데 D를 사용한 경우에는 에러 발생
	// 함수는 조합해서 한 번에 사용할 수 있다.
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T; // 테스트 케이스의 개수 입력받기
	bool isWrong = false; // 배열이 비어있는데 D를 사용한 경우 error를 발생시키기 위한 flag

	while (T--) {
		deque<int> DQ; // DQ 선언
		string p; 
		cin >> p; // 명령어 입력
		int n;
		cin >> n; // 배열에 들어있는 수의 개수 입력
		string tmp;
		cin >> tmp; // 배열에 넣는 수 입력받기
		isWrong = false; // flag를 false로 유지
		int rev = 0; 
		command(tmp, DQ); // command 함수 호출
		for (int i = 0; i < p.length(); i++) {
			//int pos = p.length();
			if (p[i] == 'R') {
				rev = 1 - rev; // R일 경우 배열을 뒤집는다.
			}
			if (p[i] == 'D') { // D일 경우
				if (DQ.empty()) { // 배열이 비었을 경우 명령을 수행하지 못하기 때문에 
					isWrong = true; //error를 출력한다. 
					break;
				}
				if (!rev) DQ.pop_front(); // rev==0일 경우 앞의 값을 뺀다
				else DQ.pop_back(); // rev==0이 아닐 경우 뒤의 값을 뺀다
			}
		}
		if (isWrong == true) { // 틀리면 error 출력
			cout << "error\n";
		}
		else { //틀리지 않았을 경우
			if (rev) reverse(DQ.begin(), DQ.end()); //rev가 0이 아닐경우 뒤집는다.
			cout << "[";
			for (int i = 0; i < DQ.size(); i++) {
				cout << DQ[i];
				if (i + 1 != DQ.size()) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}