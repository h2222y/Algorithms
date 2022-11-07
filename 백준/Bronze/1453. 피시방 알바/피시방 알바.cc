#include <iostream>
#include <string>
using namespace std;
int bucket[102];
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		bucket[num]++;
		if (bucket[num] > 1) cnt++;
	}
	cout << cnt;

	return 0; 
}