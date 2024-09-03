#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	
	string strMul = to_string(mul);
	int dat[20] = {};
	for (int i = 0; i < strMul.length(); i++)
	{
		dat[strMul[i] - '0']++;
	}
	for (int i = 0; i <= 9; i++)
	{
		cout << dat[i] << "\n";
	}
	return 0;
}