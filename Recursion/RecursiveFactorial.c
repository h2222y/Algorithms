#include <stdio.h>

int Fact(int n) { // Factorial Function by using Recursion
	if (n == 0) {
		return 1;
	}
	else return n * Fact(n - 1);
}

int main() {
	int ret= Fact(5); //Call factorial function
	printf("%d", ret);

	return 0;
}