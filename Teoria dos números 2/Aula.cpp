#include <iostream>
#include <limits.h>

using namespace std;
long int n, m;

long int calculaMultiplo() {
	string texto;
	long int valor, multiplo;
	long int menorD = 0; 
	long int menorE = 0;
	
	
	// Adicionar digitos a direita de M
	for (int i=0; i<=9; i++) {		
		valor = n*10 + i;
		cout << valor << endl;
		if (valor % m == 0) {
			menorD = valor;
			break;
		}
	}
	//cout << valor << endl;
	
	// Adicionar digitos a esquerda de M
	for (int i=0; i<=9; i++) {		
		valor = i*10 + n;
		cout << valor << endl;
		if (valor % m == 0) {
			menorE = valor;
		}
	}
	//cout << menorD << endl;
	//cout << menorE << endl;
	//printf("menorE = %ld", menorE);
	
	if (menorD > menorE) {
		multiplo = menorE;
	} else {
		multiplo = menorD;
	}
	//cout << multiplo << endl;
	return multiplo;
}

int main() {
	
	cin >> n >> m;
	int r[m];
	
	cout << calculaMultiplo() << endl;
    return 0;
}
