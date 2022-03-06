#include <stdio.h>
 
char cpf[15];
int a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;

void atribuiValores() {
	a1 = cpf[0] - '0';
	a2 = cpf[1] - '0';
	a3 = cpf[2] - '0';
	a4 = cpf[4] - '0';
	a5 = cpf[5] - '0';
	a6 = cpf[6] - '0';
	a7 = cpf[8] - '0';
	a8 = cpf[9] - '0';
	a9 = cpf[10] - '0';
}
 
void calculaB1() {
	b1 = a1 + (a2*2) + (a3*3) + (a4*4) + (a5*5) + (a6*6) + (a7*7) +
	(a8*8) + (a9*9);
	b1 = b1 % 11;
	if (b1 == 10) {
		b1 = 0;
	}
}

void calculaB2() {
	b2 = a1*9 + (a2*8) + (a3*7) + (a4*6) + (a5*5) + (a6*4) + (a7*3) +
	(a8*2) + a9;
	b2 = b2 % 11;
	if (b2 == 10) {
		b2 = 0;
	}
}

int main() {
	int i = 1;
	while (scanf("%s", cpf) > 0) {
    	atribuiValores();
    	calculaB1();
    	calculaB2();
	    if ((b1 == cpf[12] - '0') && (b2 == cpf[13] - '0')) {
	    	printf("CPF valido\n");
		} else{
			printf("CPF invalido\n");
		}
		i += 1;
	}
    return 0;
}
