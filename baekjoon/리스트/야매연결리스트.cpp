#include <stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num; // 새로운 원소를 생성
    pre[unused] = addr; // 새 원소의 pre값에 삽입할 위치의 주소 대입
    nxt[unused] = nxt[addr]; // 새 원소의 nxt 값에 삽입할 위치의 nxt 대입
    if (nxt[addr] != -1) pre[nxt[addr]] = unused; // 삽입할 위치의 nxt 값과 삽입할 위치의 다음 원소의 pre 값을 새 원소로 변경
    // 맨 마지막 원소의 뒤에 새 원소를 추가하는 상황이라면 삽입할 위치의 다음 원소가 존재하지 않음
    // pre[nxt[addr]]=unused;로 바로 사용하면 pre[-1]에 접근할 수 있음
    // 따라서 nxt[addr]이 -1이 아닐 때에만 pre[nxt[addr]]에 unused를 대압
    nxt[addr] = unused; // 삽입할 위치의 다음 원소는 unused
    unused++; // 다 사용한 unused 값 1 증가
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr]; // dummy node의 존재로 어떤 원소를 지우더라도 pre[addr]은 -1이 아님이 보장된다.
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; //nxt[addr]는 제일 마지막 우너소를 지우는 과정에서 값이 -1일 수 있다.
    // 따라서 조건문을 걸어준다. 
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}