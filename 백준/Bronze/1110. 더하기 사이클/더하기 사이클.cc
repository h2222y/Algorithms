#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int i;
	int init;
	init = n;
	int cnt = 0;
	while (1) {
			n = ((n%10)*10)+ ((n / 10) + (n % 10))%10;
			cnt++;
			if(n==init){
		break;
			}
	}
	cout << cnt;
	return 0;
}