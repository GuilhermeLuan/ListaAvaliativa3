#include <stdio.h>

int main(){
    int qtdMeses;
    double aporteMensal, taxaJuros, montanteFinal = 0.0;

    scanf("%d", &qtdMeses);
    scanf("%lf", &aporteMensal);
    scanf("%lf", &taxaJuros);

    for (int i = 1; i <= qtdMeses; ++i) {
        montanteFinal += aporteMensal;
        montanteFinal *= (1 + taxaJuros);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montanteFinal);
    }


    return 0;
}