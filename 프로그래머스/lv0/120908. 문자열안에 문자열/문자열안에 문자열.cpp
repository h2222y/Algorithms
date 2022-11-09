#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    if(str1.find(str2)!=-1) return 1;
    return 2;
}