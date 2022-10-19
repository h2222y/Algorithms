#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	int a = 0;
	int b;
	int c = 0, d;
	int sum = 0;
	string temp1, temp2;

	while (1) {
		a = str.find('[', a);
		b = str.find(']', a + 1);
		c = str.find('{', c);
		d = str.find('}', c + 1);
		if (a == -1 && c == -1)break;
		if(a!=-1) temp1 = str.substr(a + 1, b - a - 1);
		if(c!=-1) temp2 = str.substr(c + 1, d - c - 1);
		
		if (a < c) {
			if (a == -1) {
				sum *= stoi(temp2);
				a = -1;
				c = d + 1;
			}
			else {
				sum += stoi(temp1);
				c = a;
				a = b + 1;
			}
		}
		else if (a > c) {
			if (c == -1) {
				sum += stoi(temp1);
				a = b + 1;
				c = -1;
			}
			else {
				sum *= stoi(temp2);
				a = c;
				c = d + 1;
			}
		}
	}
	cout << sum;
	return 0; 
}