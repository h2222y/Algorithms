#include <iostream>
#include <algorithm>
using namespace std;
//카드 역배치

int main() {
	int num[21] = { 0 };
	for (int i = 1; i <= 20; i++) {
		num[i] = i; //1~20번까지 카드 입력받음
	}
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b; //a와 b 입력 (범위입력)
		for (int j = a; j <= b; j++) {
			for (int k = j + 1; k <= b; k++) {
				if (j + k == a + b) { //인덱스의 값이 a+b와 같으면 스위칭
					int temp = num[j];
					num[j] = num[k];
					num[k] = temp;
				}
			}
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout<<num[i]<<" ";
	}
	return 0;
}