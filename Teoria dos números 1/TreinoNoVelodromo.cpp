#include <stdio.h>
#include <iostream>

using namespace std;
int t, a, b;
int multiplos[65];
int tempos[20];

void zeraVetor(int * vetor, int n) {
	for (int i=0; i<n; i++) {
		vetor[i] = 0;
	}
}

void encontraMultiplos() {
	int m1 = a*b;
	int m;
	int i = 0;
	while (true) {
		m = m1*(i+1);
		if (m < t) {
			multiplos[i] = m;
		} else {
			break;
		}
		i++; 
	}
}

bool divide(int n, int d) {
	if (n%d == 0) {
		return true;
	}
	return false;
}

void calculaTempos() {
	short int cont = 0;
	bool divisor = false;
	for (int i=1; i<=t; i++) {
		divisor = false;
		if (divide(t, i)) {
			for (int j=0; multiplos[j]!=0; j++) {
				if (divide(multiplos[j], i)) {
					divisor = true;
					break;
				}
			}
			if (!divisor) {
				tempos[cont] = i;
				cont++;
			}
		}
	}
}

int main() {
	while (true) {
    	cin >> t >> a >> b;
		if (t==0 && a==0 && b==0) {
			break;
		}
		zeraVetor(multiplos, 65);
		zeraVetor(tempos, 20);

		encontraMultiplos();
		calculaTempos();
		for (int i=0; tempos[i]!=0; i++) {
			printf("%d ", tempos[i]);
		}
		printf("\n");
	}
    return 0;
}
