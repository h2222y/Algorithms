#include <iostream>
#include <string>
using namespace std;

string str = "ABC123[10]B{3}AT[20][10]BB{2}Q";

int getNums(int a, int b)
{
	string temp = str.substr(a + 1, b - a - 1);
	return stoi(temp);
}

int main()
{
	cin >> str;
	int n = str.length();

	int a, b;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == '[') {
			a = i;
			b = str.find(']', a + 1);
			sum += getNums(a, b);

			i += (b - a);
		}
		else if (str[i] == '{') {
			a = i;
			b = str.find('}', a + 1);
			sum *= getNums(a, b);

			i += (b - a);
		}
	}

	cout << sum;

	return 0;
}