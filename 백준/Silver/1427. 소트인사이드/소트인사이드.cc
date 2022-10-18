#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

bool Comp(string s1,string s2) {
	if(s1>s2) return false;
}
int main() {
	cin >> str;
	sort(str.begin(), str.end(),greater<>());
	cout << str;
	return 0; 
}
