#include <iostream>
#include <string>
using namespace std;

string str;
int used[100];
char path[100];
void recur(int now) {

	if (now == 3) {
		cout << path << endl;
		return;
	 }

	for (int to = 0; to < 4; to++) {
		if (used[to] == 0)
		{
		used[to] = 1;
		path[now] = str[to];
		recur(now + 1);
		path[now] = 0;
		used[to] = 0;
		}
	}
}

int main() {
	/*cin >> str;
	used[0] = 1;
	recur(0);*/
	cin >> str;
	recur(0);
	return 0;
}