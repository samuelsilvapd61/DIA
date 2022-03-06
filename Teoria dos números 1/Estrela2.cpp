#include <stdio.h>
#include <iostream>
#include <math.h>
#include<stdlib.h>

using namespace std;
long long int n;

// Primalidade força bruta
/*
bool ePrimo(int valor) {
	if (valor <= 1) {
		return false;
	}
	int raiz = (int)sqrt(valor);
	//int metade = (int)(valor/2);
	for (int i=2; i<=raiz; i++) {
		if (valor % i == 0) {
			return false;
		}
	}
	return true;
}
*/

// Primalidade com Crivo
/*
bool ePrimo2(int n, int *c) {
	if (c[n] == n) {
		return true;
	} else {
		return false;
	}
}
*/

/*
void crivoErastotenes(int n, int * c) {
	for (int i=1; i<=n; i++) {
		c[i] = i;
	}
	int t = 2;
	int d = 0;
	for (int i=1; i<=(n/2); i++) {
		c[t] = 2;
		t += 2;
	}
	for (int i=3; i<=sqrt(n); i++) {
		if (c[i] == i) {
			t = i*i;
			d = i+i;
			while(t <= n) {
				if (c[t] == t) {
					c[t] = i;
				}
				t = t+d;
			}
		}
	}
}
*/

int mdcEuclides(int a, int b) {
	int r = 0;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

/*
void crivoTabelaPrimos() {
	
}
*/
int main() {
	while (true) {
		cin >> n;
		if (n < 3) {
			break;
		}
		//int vetor[n];
		//crivoErastotenes(n, vetor);
		
		int cont = 0;
		for (int i=1; i<=(n/2); i++) {
			if (i > 1 && n % i == 0) {
				continue;
			}
			if (mdcEuclides(i, n) == 1) {
				//printf("OLA\n");
				cont++;
			}
		}
		printf("%d\n", cont);
		
		/*for (int i=0; i<=n; i++) {
			printf("i = %d - %d\n", i, vetor[i]);
		}*/
	}
    return 0;
}
