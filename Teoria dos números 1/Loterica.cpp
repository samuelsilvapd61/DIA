#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
 
int matriz[500][500];
int n, m, k;
long long int apostas;

void criaMatriz() {
	int valor = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			matriz[i][j] = valor;
			valor++;
		}
	}
}

long long int combinacao(int n, int p) {
	long long int comb = 0;
	if (n < p) {
		return 0;
	} else if (n == p) {
		return 1;
	} else {
		comb = (combinacao(n-1, p)*n)/(n-p);
		return comb;
	}
}

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

int quantPrimos(int min, int max) {
	int quant = 0;
	for (int i=min; i<=max; i++) {
		quant += ePrimo(i);
	}
	return quant;
}

int quantPrimosColuna(int min, int max) {
	int quant = 0;
	for (int i=min; i<=max; i = i+m) {
		quant += ePrimo(i);
	}
	return quant;
}

void calculaApostas() {
	apostas = 0;
	if (k == 1) {
		apostas = (n*m) - quantPrimos(0, n*m-1);
	} else {
		if (k <= m) {
			for (int i=0; i<n; i++) {
				apostas += combinacao(m-(quantPrimos(matriz[i][0], matriz[i][m-1])), k);
			}
		}
		if (k <= n) {
			for (int i=0; i<m; i++) {
				apostas += combinacao(n-(quantPrimosColuna(matriz[0][i], matriz[n-1][i])), k);
			}
		}
	}
}

int main() {
	while (true) {
    	cin >> n >> m >> k;
    	if (n==0 && m==0 && k==0) {
    		break;
		}
		criaMatriz();
		calculaApostas();
		printf("%lld\n", apostas);
	}
    return 0;
}
