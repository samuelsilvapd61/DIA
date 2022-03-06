#include <iostream>

using namespace std;

int c, n;
int doces[100000];

// O vetor "casas" armazena o n�mero da primeira casa e da �ltima casa da sequ�ncia de casas que ser� a resposta do exerc�cio.
int casas[2];

int calculaResposta() {
	long long int soma = 0;
	int resto;
	
	// S� existem "c" valores de restos poss�veis. Inicializo as posi��es do vetor "restos" com -1.
	int restos[c];
	for (int i=0; i<c; i++) {
		restos[i] = -1;
	}
	
	// Para cada quantidade de doces de cada casa, faco os testes necessarios.
	for (int i = 0; i<n; i++) {
		// Testo se a pr�pria casa "i" j� tem o valor que dividido por "c" j� da resto 0.
		if (doces[i]%c == 0) {
			casas[0] = i+1;
			casas[1] = i+1;
			return 0;
		} else {
			soma += doces[i];
			resto = soma % c;
			// Testo se o total de doces at� o momento, dividido por "c" da resto 0.
			if (resto == 0) {
				casas[0] = 1;
				casas[1] = i+1;
				return 0;
			} else {
				// Por fim, testo se o resto encontrado no momento, � um valor j� encontrado anteriormente. 
				// (Por isso que o vetor "restos" � inicializado com -1.)
				if (restos[resto] != -1) {
					casas[0] = restos[resto]+1;
					casas[1] = i+1;
					return 0;
				// Se n�o for, eu adiciono o numero da casa no vetor "restos".
				} else {
					restos[resto] = i+1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> c >> n;
		if (c == 0 && n == 0) {
			return 0;
		}
		for (int i = 0; i<n; i++) {
			cin >> doces[i];
		}
		calculaResposta();
		
		// Aqui � exibida a resposta utilizando a informa��o do vetor "casas".
		cout << casas[0];
		for (int i=casas[0]+1; i<=casas[1]; i++) {
			cout << " ";
			cout << i;
		}
		cout << endl;
	}
    return 0;
}
