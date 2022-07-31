#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string arr1, arr2;
	for (int i = 0; i < n; i++) {
		cin >> arr1 >> arr2;
		int bucket[100] = { 0 };
		int flag = 0;
		for (int j = 0; j < arr1.length(); j++) {
			bucket[arr1[j] - 'a']++;
			bucket[arr2[j] - 'a']--; 
		}
		for (int j = 0; j < 100; j++) {
			if (bucket[j] != 0) {
				flag = 1;
				break;
			}
		}
		if(flag==0) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}