#include <iostream>
#include <string>
using namespace std;

string colors[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };


int main() {
	string color1, color2, color3;
	cin >> color1 >> color2 >> color3;
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		if (colors[i] == color1) sum += i*10;
		if (colors[i] == color2) sum += i;
	}
	for (int i = 0; i < 10; i++) {
		if (colors[i] == color3) {
			while (i--) {
				sum *= 10;
			}
			break;
		}
	}
	cout << sum;
	return 0;
}