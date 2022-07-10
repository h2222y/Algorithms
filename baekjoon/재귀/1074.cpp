#include <iostream>
using namespace std;

int vis(int n,int s,int e) {
	if (n == 0) return 0; //n이 0이면 0을 반환
	int half = 1 << (n - 1); // half는 2^(n-1) 사각형을 2^(n-1)로 4등분
	if (s < half && e < half) return vis(n - 1, s, e); // 만약 1사분면에 있다면 그대로 반환
	if (s < half && e >= half) return half*half + vis(n - 1, s, e-half); // 만약 2사분면에 있다면 1사분면의 값을 더해주고, y값만 맞춰준다.(2사 분면은 y값의 영향) 
	if (s >= half && e < half) return 2* half * half + vis(n - 1, s-half, e); // 만약 3사분면에 있다면 1,2사분면의 값을 더해주고, x값만 맞춰준다.(3사 분면은 x값의 영향)
	return 3*half*half + vis(n - 1, s-half, e-half); // 만약 4사분면에 있다면 1,2,3사 분면의 값을 더해주고 x,y값 모두 맞춰준다. 
	
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << vis(n, r, c);

}