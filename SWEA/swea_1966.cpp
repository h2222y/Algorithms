#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++){
	int n;
	cin >> n;
	int arr[51] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << "#" << tc << " ";
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}
	cout << "\n";
	}
	return 0;
}