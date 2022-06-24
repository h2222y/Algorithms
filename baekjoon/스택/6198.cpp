#include <iostream>
#include <stack>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 개수
    ll h; // 높이

    while (n--) {
        cin >> h; //높이 입력받음
        while (!s.empty() && s.top() <= h) //스택이 비어있지 않고 스택에 들어있는 수의 높이가 현재 높이보다 낮을때
            s.pop(); //pop해준다
        ans += s.size(); //자신보다 큰 수 = 자신을 바라볼 수 있는 것들
        // stack에 자신보다 큰 수만을 남겨뒀기 때문에 자신을 바라볼 수 있는 개수를 세어주는 것이다. 
        s.push(h);
    }
    cout << ans;
    return 0;
}