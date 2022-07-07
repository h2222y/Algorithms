//핸드폰 요금
#include <iostream>
using namespace std;

int main() {
	int n, time;
	cin >> n;
	int sum_y = 0, sum_m=0;
	for (int i = 0; i < n; i++) {
		cin >> time;
		sum_y += 10 + time / 30 * 10; //30초 이상 사용하면 30초마다 10원
		sum_m += 15 + time / 60 * 15;// 60초 이상 사용하면 60초마다 10원
	}
	if (sum_y < sum_m) {
		cout << "Y ";
		cout << sum_y; //영식이 싸면 영식 요금제
	}
	if (sum_m < sum_y) {
		cout << "M "; 
		cout << sum_m; //민식이 싸면 민식 요금제
	}
	if (sum_y == sum_m) {
		cout << "Y M "; 
		cout << sum_y; //같으면 영식먼저 출력하고 합산 금액 출력
	}



	return 0;
}