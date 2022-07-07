#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	list<char> Li;
	for (auto c : s) Li.push_back(c); //초기 편집기에 입력되어 있는 문자열
	list<char>::iterator t = Li.end(); //커서는 맨 마지막을 가리킴
	
	int m;
	cin >> m; //입력할 명령어의 개수 
	
	for (int i = 0; i < m; i++) {
		char command, dollar;
		cin >> command; //명령어 입력
		if (command == 'P') {
			cin >> dollar; //추가할 문자
			Li.insert(t, dollar); //원하는 위치에 추가한다.
		}
		else if (command == 'L') {
			if(t!=Li.begin()) t--; // 맨 앞이 아니면 커서를 한 칸 왼쪽으로
		}
		else if (command == 'D') {
			if (t != Li.end())t++; // 맨 뒤가 아니면 커서를 한 칸 오른쪽으로
		}
		else if (command == 'B') {
			if(t!=Li.begin()){ // 맨 앞의 값이 아니면
			t--; //커서를 한 칸 왼쪽으로 가고
			t = Li.erase(t); // 지운 값의 다음 값의 위치를 받아옴
			} 
		}
	}
	for (auto c : Li)cout << c;
	return 0;
}