#include <iostream>
#include <algorithm>
using namespace std;
int arr[100] = { 0 };

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		int dump;
		cin >> dump;

		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}

		while(1){ // 1000 회 * N log N  < 1 억 
	  	sort(arr, arr + 100, greater<int>());

			if (dump == 0) break;
		// 내림차순 정렬
		  arr[0]--;
	  	arr[99]++;
	  	dump--;
		}
		cout <<"#"<<tc<<" "<<arr[0] - arr[99] << endl;
	
	}
}