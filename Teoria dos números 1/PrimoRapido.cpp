#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int n, x;

bool ePrimo(int valor) {
	if (valor <= 1) {
		return false;
	}
	int raiz = (int)sqrt(valor);
	for (int i=2; i<=raiz; i++) {
		if (valor % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
    	cin >> x;
		if (ePrimo(x)) {
			printf("Prime\n");
		} else {
			printf("Not Prime\n");
		}
	}
    return 0;
}
