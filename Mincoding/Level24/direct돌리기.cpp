#include <iostream>
#include <string>
using namespace std;

string str[3][3] = {
	"BHC","BBQ","KFC",
	"MC","7AVE","PAPA",
	"DHC","OBS","MOMS",
};
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int main() {
	int tar_x, tar_y;
	cin >> tar_x >> tar_y;
	for (int k = 0; k < 4; k++) {
		int nx = tar_x + dx[k];
		int ny = tar_y + dy[k];
		if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
		cout << str[nx][ny];
	}
	return 0; 
}