#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;
		int A = 0, B = 0;
		A = p * w;
		if (w-r <= 0)
			B = q;
		else
			B = q + (s * (w-r));
		if (A <= B) cout <<"#"<<T<<" "<< A << "\n";
		else cout <<"#"<<T<<" "<< B << "\n";
	}
}