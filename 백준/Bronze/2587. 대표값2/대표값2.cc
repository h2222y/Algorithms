#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

double arr[5];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double sum = 0;
	double avg = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	avg = sum / 5.0;
	sort(arr, arr + 5);
	cout << int(avg) << "\n" << arr[2];


	return 0; 
}