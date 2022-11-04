#include <iostream>
#include <string>
using namespace std;

int arr[8][8] = {
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
}; // 하얀색은 0번 검은색은 1번 체스판

int main() {
	string str;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cin >> str;
			for (int x = 0; x < 8; x++) {
				if (arr[i][x] == 0 && str[x] == 'F') cnt++;
			}
		}
	
	cout<<cnt;

	return 0; 
}