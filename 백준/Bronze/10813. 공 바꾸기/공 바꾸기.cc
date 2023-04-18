#include <iostream>
using namespace std;
// hyesu 20230418
int arr[101];

int main(){
    int n,m; // n=basket num, m=change num
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i] = i;
    } // Initial State, basket num == ball num
    while(m--){
        int i,j; // ball number to change
        cin>>i>>j;
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; //change
    } 
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    } // print
    return 0; 
}