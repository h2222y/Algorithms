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
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string str;
		list<char> L = {};
		auto cursor=L.begin();
		cin >> str;

		for (auto c : str) {
			if (c == '<') {
				if (cursor != L.begin()) {
					cursor--;
				}
			}
			else if (c == '>') {
				if (cursor != L.end()) {
					cursor++;
				}
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else L.insert(cursor, c);
		}

		for (auto c : L) cout << c;
		cout << "\n";
	}



	return 0;
}