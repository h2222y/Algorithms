#include <iostream>
using namespace std;

int recur(int n, int a,int b) {
	if (n <= 1) return n;
	else if (n == 2) return a + b;
	else return recur(n-1, b,a+b);
}

int main() {
	int n;
	cin >> n;
	int a = 0, b = 1;
	cout<< recur(n, a,b);
	return 0;
}