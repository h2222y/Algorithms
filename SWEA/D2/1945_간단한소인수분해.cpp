#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n;
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		cin >> n;
		while(n!=1){
		if (n % 2 == 0) {
			a++;
			n = n / 2;
		}
		if (n % 3 == 0){
			b++;
			n = n / 3;
		}
		if (n % 5 == 0) {
			c++;
			n = n / 5;
		}
		if (n % 7 == 0)
		{
			d++;
			n = n / 7;
		}
		if (n % 11 == 0) {
			e++;
			n = n / 11;
		}
		}
		cout <<"#"<<T<<" "<< a << " " << b << " " << c << " " << d << " " << e << "\n";
		
	}

	return 0; 
}