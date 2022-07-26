#include <iostream>
#include <string>
using namespace std;
int arr[1001] = { 0 };
int main() {
	int c;
	cin >> c;
	for (int tc = 0; tc < c; tc++) {
		int n;
		cin >> n;
		double num;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			arr[i] = num;
			sum += num;
		}
		double avg = sum / n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > avg) {
				cnt++;
			}
		}
		cout.precision(3);
		cout << fixed;
		cout << (double)cnt / (double)n * 100<<"%"<<endl;
	
	}
	return 0;
}