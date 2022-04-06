#include <iostream>
using namespace std;
int n, k;// ���� ���� ����, �ܾ���� 
int arr[20][20] = { 0 }; // ���� ���� �� �Է�

int Garo();
int Sero();

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;//���� ����
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> k;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> arr[y][x];
			}
		}
		int garo = Garo();
		int sero = Sero();
		cout <<"#"<<t<<" "<<garo + sero << endl;
	}
	return 0;

}
int Garo() {
	int cnt = 0;
	int sum = 0;
	for (int y = 0; y < n; y++) {
		cnt = 0;
		for (int x = 0; x < n; x++) {
			if (arr[y][x] == 1) {
				cnt++;
				if (cnt > k) cnt = 0;
				if (x == n - 1 && cnt == k) sum++;
			}
			else {
				if (cnt == k) sum++;
				cnt = 0;
			}
		}
	}
	if (sum == 0) return 0;
	else return sum;
}
int Sero() {
	int cnt = 0;
	int sum = 0;
	for (int x = 0; x< n; x++) {
		cnt = 0;
		for (int y = 0; y < n; y++) {
			if (arr[y][x] == 1) {
				cnt++;
				if (cnt > k) cnt = 0;
				if (y == n - 1 && cnt == k) sum++;
			}
			else {
				if (cnt == k) sum++;
				cnt = 0;
			}
		}
	}
	if (sum == 0) return 0;
	else return sum;

}