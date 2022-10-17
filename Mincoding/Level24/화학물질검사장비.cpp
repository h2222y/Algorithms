#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string log_msg;
	double cnt_pass = 0, cnt_fail = 0;
	int passfind = -1, failfind = -1;

	cin >> log_msg;
	for (int i = 0; i < log_msg.length(); i++) {
		if (log_msg[i] >= 'a' && log_msg[i] <= 'z') {
			log_msg[i] = log_msg[i] - 'a' + 'A';
		}
	}
	while (1) {
		passfind = log_msg.find("PASS",passfind+1);
		if (passfind == -1) break;
		cnt_pass++;
	}

	while (1){
		failfind = log_msg.find("FAIL", failfind + 1);
		if (failfind == -1) break;
		cnt_fail++;
	}
	double sum = (cnt_pass / (cnt_pass + cnt_fail));
	int ans = sum * 100;
	cout << ans << "%";
	return 0; 
}