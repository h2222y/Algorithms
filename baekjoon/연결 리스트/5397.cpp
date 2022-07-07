#include <iostream>
#include <string>
#include <list>
using namespace std;
//키로거
	//백스페이스를 입력했다면 '-', 커서의 바로 앞에 글자가 존재한다면 그 글자를 지운다.
	// 화살표를 입력했다면 < 나 >가 주어진다.
	// 방향키만큼 이동한다.
	// 나머지 문자는 비밀번호의 일부이다.

int main() {
	int T;
	cin >> T; // 테스트케이스의 수가 주어진다.

	for (int tc = 0; tc < T; tc++) {
		string str; // 강산이가 입력한 문자열이 주어진다.
		list<char> L = {};
		auto cursor=L.begin(); //커서의 처음 위치는 맨 처음 위치
		cin >> str; //문자열을 입력받는다
		 
		for (auto c : str) { //문자열을 돌면서
			if (c == '<') { //해당 문자가 <라면 
				if (cursor != L.begin()) {
					cursor--; //왼쪽으로 커서이동
				}
			}
			else if (c == '>') { //해당 문자가 >라면
				if (cursor != L.end()) {
					cursor++; //오른쪽으로 커서이동
				}
			}
			else if (c == '-') { //해당 문자가 -라면
				if (cursor != L.begin()) {
					cursor--; //커서를 왼쪽으로 이동하고
					cursor = L.erase(cursor); //해당 문자의 값을 지우고 커서를 이동시킨다.
				}
			}
			else L.insert(cursor, c); //해당 커서의 값의 문자가 영어라면 해당 값을 리스트에 담는다
		}

		for (auto c : L) cout << c; //리스트를 출력한다.
		cout << "\n";
	}



	return 0;
}