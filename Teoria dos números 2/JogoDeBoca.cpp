#include <iostream>

using namespace std;

int calculaResposta(string valor) {
	int soma = 0;
	int tamanho = valor.length();
	for (int i=0; i<tamanho; i++) {
		soma += (int) valor[i];
	}
	return soma % 3;
}

int main() {
	string valor;
	cin >> valor;
	cout << calculaResposta(valor) << endl;
    return 0;
}
