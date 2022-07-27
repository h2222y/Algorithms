#include <iostream>
using namespace std;

int main() {
	double arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		if (arr[i] < 40) arr[i] = 40;
	}
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	double avg = sum / 5.0;
	cout << (int)avg;


	return 0;
}