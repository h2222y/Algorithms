#include <iostream>
#include <string>
using namespace std;

string pass[5] = {
	"Jason",
	"Dr.tom",
	"EXEXI",
	"GK12P",
	"POW",
};

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 5; i++) {
		if (str == pass[i]) {
			cout << "암호해제";
			return 0; 
		}
	}
	cout << "암호틀림";
	return 0;
}