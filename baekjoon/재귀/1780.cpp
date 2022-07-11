#include <iostream>
using namespace std;
int arr[3000][3000];
int cnt[3];

bool check(int r, int c,int n) { //배열이 모두 같은 숫자로 이루어져 있는지 확인
	for (int i = r; i < r + n; i++) { //시작 좌표부터 n만큼 더한 값 까지 
		for (int j = c; j < c + n; j++) { // 여기서 n은 3으로 나눈 값이 들어간다.
			if (arr[r][c] != arr[i][j]) return false; // 하나라도 다르면 모두 같지 않음
		}
	}
	return true; // 모두 같을 경우 true 
}

void recur(int x,int y,int z) { //시작좌표 (x,y), z는 3으로 나누면 배열을 9등분 가능
	if (check(x,y,z)) { // 배열이 모두 같은 숫자로 이루어져 있는지 확인
		cnt[arr[x][y] + 1] += 1; // true면 모두 같은 경우므로 cnt[해당값(-1도있으므로)+1]++;
		return;
	}
	int n = z / 3; // 3으로 나눠주면 9등분 가능 x,y 모두 3으로 나눈 범위이므로 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recur(x + i * n, y + j * n,n); // 시작 좌표를 보내준다. 
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // 배열의 크기를 입력받는다 n = 3^k꼴 
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> arr[x][y]; // 배열을 입력받는다. 
		}
	}
	recur(0,0,n); //시작좌표 (0,0), n까지
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n"; //카운트 한 값 출력
	}
}