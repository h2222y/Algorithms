#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int tc, T;
	cin >> T;
	for(tc=1;tc<=T;tc++){
	char arr[1000];
	cin >> arr;
	int len = strlen(arr);
	cout << "#" << tc << " ";
	for (int i = len; i >=0; i--) {
		if (arr[i] == 'b') cout << 'd';
		if (arr[i] == 'd') cout << 'b';
		if (arr[i] == 'p') cout << 'q';
		if (arr[i] == 'q') cout << 'p';
	}
	cout << "\n";
	}
	return 0;

}