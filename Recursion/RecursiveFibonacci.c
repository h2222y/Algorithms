#include <stdio.h>

int Fibo(int n) { // FibonacciFunction 
	if (n == 1) return 0;
	if (n == 2) return 1;
	else return Fibo(n - 2) + Fibo(n - 1);
}
int main() {
	for (int i = 1; i <= 15; i++) {
		printf("%d ",Fibo(i));
	}
	return 0;
	
} 