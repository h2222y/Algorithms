/* #include <iostream>
using namespace std;
int n;
int card[1000];

int Sort();
int Zero(int zero);

int main() {

	// n개의 숫자가 적힌 카드가 있다.
	// 이 카드들 중에서 몇개를 가지고 숫자가 1씩 증가하는
	// 순서대로 늘어놓는 경우를 스트레이트라고 한다.
	cin >> n;
	int cnt = 0;
	int flag = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < n; i++) {
		if (card[i] == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) ret = Sort();
	if (flag == 1) {
		for (int i = 0; i < n; i++) {
			if (card[i] == 0) cnt++;
		}
		ret = Zero(cnt);
	}
	cout << ret;
	return 0;
}

int Sort() {
	int temp=0;
	int cnt = 1, max=-999;
	for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (card[y] > card[x]) {
				temp = card[y];
				card[y] = card[x];
				card[x] = temp;
			}
		}
	} //숫자 정렬
	for (int x = 0; x < n; x++) {
		if ((card[x] + 1) != card[x + 1]) {
			cnt = 1;
			continue;
		}
		else if (card[x] + 1 == card[x + 1]) {
			cnt++;
		}
		if (cnt > max) {
			max = cnt;
		}
	} //0이 존재하지 않을때
	return max;

}
int Zero(int zero) {
	int temp = 0;
	int cnt = 1, max = -999;
	for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (card[y] > card[x]) {
				temp = card[y];
				card[y] = card[x];
				card[x] = temp;
			}
		}
	} //정렬
	for (int x = 0; x < n; x++) {
		if ((card[x] + 1) != card[x + 1]) {
			continue;
		}
		if (((card[x + 1] - card[x]) <= zero)&& card[x]!=0) {
			cnt++;
		}
	}
	return cnt+zero;
} */