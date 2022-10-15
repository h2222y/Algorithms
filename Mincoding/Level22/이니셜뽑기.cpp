#include <iostream>
using namespace std;

char arr[4][5][4] = {
	{" # ",
	"# #",
	"###",
	"# #",
	"# #"},
	{"###",
	"# #",
	"###",
	"# #",
	"###"},
	{"###",
	"# #",
	"#  ",
	"# #",
	"###"},
	{"## ",
	"# #",
	"# #",
	"# #",
	"## ",}
};
int main() {
	int n;
	cin >> n;
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 3; y++) {
				cout << arr[n][x][y];
			}
			cout << "\n";
		}

}