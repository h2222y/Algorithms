#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
char delimeter[2] = { '-','+' };

vector<string> split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
}

int main() {
	string str;
	cin >> str;
	int sum = 0;
	vector<string> v = split(str, "+-");
	for (int i = 0; i < v.size(); i++) {
		sum += stoi(v[i]);
	}
	return 0; 
}