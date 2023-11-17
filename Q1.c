#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valorRomano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanoParaDecimal(char* numeroRomano) {
    int resultado = 0;
    int comprimento = strlen(numeroRomano);

    for (int i = 0; i < comprimento; i++) {
        int valorAtual = valorRomano(numeroRomano[i]);

        if (i < comprimento - 1) {
            int valorProximo = valorRomano(numeroRomano[i + 1]);

            if (valorAtual < valorProximo) {
                resultado -= valorAtual;
            } else {
                resultado += valorAtual;
            }
        } else {
            resultado += valorAtual;
        }
    }

    return resultado;
}


char* decimalParaBinario(int numeroDecimal) {
    char* binario = (char*) malloc(33 * sizeof(char));
    itoa(numeroDecimal, binario, 2);

    return binario;
}

char* decimalParaHexadecimal(int numeroDecimal) {
    char* hexadecimal = (char*) malloc(33 * sizeof(char ));
    itoa(numeroDecimal, hexadecimal, 16);

    return hexadecimal;
}



int main() {
    char entradaEmRomano[13];
    scanf("%s", &entradaEmRomano);


    int entradaEmDecimal = romanoParaDecimal(entradaEmRomano);

    printf("%s na base 2: %s\n", entradaEmRomano, decimalParaBinario(entradaEmDecimal));
    printf("%s na base 10: %d\n",entradaEmRomano, romanoParaDecimal(entradaEmRomano));
    printf("%s na base 16: %s\n",entradaEmRomano, decimalParaHexadecimal(entradaEmDecimal));


    return 0;
}
