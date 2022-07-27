#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void command(string& tmp, deque<int>& DQ) {
	int cur = 0;
	for (int i = 1; i + 1 < tmp.size(); i++) {
		if (tmp[i] == ',') {
			DQ.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if (cur != 0) DQ.push_back(cur);
}
int main() {
	// AC는 정수 배열에 연산을 하기 위해 만든 언어
	// R(뒤집기), D(버리기)
	// R은 배열에 있는 수의 순서를 뒤집는 함수
	// D는 첫 번째 수를 버리는 함수, 배열이 비어있는데 D를 사용한 경우에는 에러 발생
	// 함수는 조합해서 한 번에 사용할 수 있다.
	int T;
	cin >> T;
	bool isWrong = false;

	while (T--) {
		deque<int> DQ;
		string p;
		cin >> p; // 명령어
		int n;
		cin >> n; // 배열에 들어있는 수의 개수
		string tmp;
		cin >> tmp;
		isWrong = false;
		int rev = 0;
		command(tmp, DQ);
		for (int i = 0; i < p.length(); i++) {
			//int pos = p.length();
			if (p[i] == 'R') {
				rev = 1 - rev;
			}
			if (p[i] == 'D') {
				if (DQ.empty()) {
					isWrong = true;
					break;
				}
				if (!rev) DQ.pop_front();
				else DQ.pop_back();
			}
		}
		if (isWrong == true) {
			cout << "error\n";
		}
		else {
			if (rev) reverse(DQ.begin(), DQ.end());
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