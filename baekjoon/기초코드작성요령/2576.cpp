//È¦¼ö
#include <iostream>
using namespace std;

int main() {
	int n;
	int sum = 0, min =999;
	int flag = 0;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 != 0) {
			flag = 1;
			sum += n;
			if (n < min) min = n;
		}
	}
	if(flag==1){
	cout << sum << "\n";
	cout << min << "\n";
	}
	else cout << -1;
	return 0;
}