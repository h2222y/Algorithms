#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	
	if (a == b) cout << 0;
	else if (a < b) {
		cout << b - a - 1<<"\n";
		for (long long i = a+1; i < b ; i++) {
			cout << i<<" ";
		}
	}
	else {
		cout << a - b - 1 << "\n";
		for (long long i = b + 1; i < a; i++) {
			cout << i << " ";
		}
	}


	return 0; 
}