#include <iostream>
using namespace std;

int main() {
	int n; // 시험 본 과목의 갯수 n<=1000
	cin >> n;
	double score[1000] = { 0 }; // 현재 성적
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	double max = -999;
	for (int i = 0; i < n; i++) {
		if (score[i] > max) {
			max = score[i];
		}
	}
	double newScore=0;
	double newSum=0;
	for (int i = 0; i < n; i++) {
		newScore = (score[i] / max) * 100;
		newSum += newScore;
	}
	float ans = 0;
	ans = newSum / n;
	cout << ans;
	// 점수/M*100으로 점수 조작하기
	
}