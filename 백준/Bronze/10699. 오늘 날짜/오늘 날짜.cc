#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;


int main() {
	
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	if(t->tm_mon<10){
		cout << t->tm_year + 1900 << "-0" << t->tm_mon+1 << "-" << t->tm_mday;
	}
	
	return 0;
	
}
