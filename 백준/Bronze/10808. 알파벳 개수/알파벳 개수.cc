#include <iostream>
#include <string>
using namespace std;

void Solution(string& s, int freq[])
{
	for (auto c : s)
		freq[c - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << freq[i] << " ";
		
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int freq[26] = {};
	string s;
	cin >> s;
	Solution(s, freq);
	
	return 0;
}