#include <iostream>
#include <list> //list STL 사용
#include <string>
using namespace std;
//에디터

int main() {
	string s;
	cin >> s; //문자열 입력받음

	list<char> Li; // Linked List 사용 
	list<char>::iterator t=Li.end(); //커서가 맨 마지막을 가리키고 있는다

	for (auto c : s) { //문자열의 모든 문자를 리스트에 담는다.
		Li.push_back(c);
	}

	int m;
	cin >> m; // 명령어의 개수

	for (int i = 0; i < m; i++) { // 명령어의 개수만큼
		char command, add; //명령어와 추가할 단어
		cin >> command; //명령어를 입력받는다
		if (command == 'P') { //명령어가 P일경우만 추가할 문자 입력
			cin >> add;
			Li.insert(t, add); //해당 커서가 가리키는 위치에 문자 추가
		}
		else if (command == 'L') { //커서가 맨 앞이 아닐경우 커서를 한 칸 이동시킨다
			if (t != Li.begin()) t--;
		}
		else if (command == 'D') {
			if (t != Li.end()) t++; //커서가 맨 뒤가 아닐경우 커서를 오른쪽으로 한 칸 이동시킨다
		}
		else if (command == 'B') {
			if(t!=Li.begin()){ //커서가 맨 앞이 아닐경우
			t--; //커서를 한 칸 왼쪽으로 이동시키고
			t = Li.erase(t); //해당 위치의 값을 지우고 커서를 해당 칸으로 
		}
		}
	}
	for (auto c : Li) cout << c; //리스트의 모든 값을 출력한다

	return 0;
}