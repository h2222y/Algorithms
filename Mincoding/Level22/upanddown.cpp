#include <iostream>
#include <string>
using namespace std;

string str[10] = { "B4","B3", "B2", "B1","1","2","3","4","5","6" };
string command;

//void dfs(int now) {
//
//	for (int i = 0; i < 10; i++) {
//
//	}
//}

int main() {
	int now = 4;
	for(int i=0;i<5;i++){
	cin >> command;
	if (command == "up") {
		now++;
	}
	else now--;
	}


	cout << str[now];
	return 0;
}