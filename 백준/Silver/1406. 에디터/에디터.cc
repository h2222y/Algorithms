#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	list<char> Li;
	for (auto c : s) Li.push_back(c);
	list<char>::iterator t = Li.end();
	
	int m;
	cin >> m; //입력할 명령어의 개수
	
	for (int i = 0; i < m; i++) {
		char command, dollar;
		cin >> command;
		if (command == 'P') {
			cin >> dollar;
			Li.insert(t, dollar);
		}
		else if (command == 'L') {
			if(t!=Li.begin()) t--;
		}
		else if (command == 'D') {
			if (t != Li.end())t++;
		}
		else if (command == 'B') {
			if(t!=Li.begin()){
			t--;
			t = Li.erase(t);
			}
		}
	}
	for (auto c : Li)cout << c;
	return 0;
}