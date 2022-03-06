#include <stdio.h>
#include <iostream>
using namespace std;
int t, a, b;
int divisores[2000];
int candidatos[2000];
void zeraVetor(int * vetor) {
	for (int i=0; i<2000; i++) {
		vetor[i] = 0;
	}
}
int mdcEuclides(int a, int b) {
	int r = 0;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int mmcEuclides(int a, int b) {
	int d = 0, m = 0;
	d = mdcEuclides(a, b);
	m = (a*b)/d;
	return m;
}
void calculaDivisores() {
	int cont = 0;
	for (int i=1; i<=t; i++) {
		if (t % i == 0) {
			divisores[cont] = i;
			cont++;
		}
	}
}
void calculaCandidatos(int mmcAB) {
	int cont = 0;
	for (int i=0; divisores[i] != 0; i++) {
		if (t == mmcEuclides(mmcAB, divisores[i])) {
			candidatos[cont] = divisores[i];
			cont++;
		}
	}
}
int main() {
	while (true) {
    	cin >> t >> a >> b;
		if (t==0 && a==0 && b==0) {
			break;
		}
		zeraVetor(divisores);
		zeraVetor(candidatos);
		int mmcAB = mmcEuclides(a, b);
		calculaDivisores();
		calculaCandidatos(mmcAB);
		for (int i=0; candidatos[i]!=0; i++) {
			printf("%du", candidatos[i]);
			if (candidatos[i+1] != 0) {
				printf(" ");
			}
		}
		printf("\n");
	}
    return 0;
}
