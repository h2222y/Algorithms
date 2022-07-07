#include <iostream>
#include <algorithm>
using namespace std;
// 일곱난쟁이

int main() {
	int fake[9] = { 0 }; //가짜 일곱난쟁이
	int sum = 0; //전체 합 구하기
	for (int i = 0; i < 9; i++) {
		cin >> fake[i];
		sum += fake[i];
	}
	sort(fake, fake + 9); // 오름차순 정렬
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (fake[i] + fake[j]) == 100) { // 만약 전체합에서 두 난쟁이를 뺀 값이 100이면
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue; //해당 난쟁이 빼고 출력
					else cout << fake[k] << "\n";
				}
				return 0;
			}
		}
	}
	
	return 0;
}