#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main(){
    char placaCarro[10];
    char diaSemana[14];
    char diaSemanaNaoPermitido[14];
    char diasDaSemana[][14] = {
            "DOMINGO", "SEGUNDA-FEIRA", "TERCA-FEIRA",
            "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO"
    };
    int placaEhValida = 0, diaEhValido = 0;

    fgets(placaCarro, sizeof(placaCarro), stdin);
    placaCarro[strcspn(placaCarro, "\n")] = '\0';
    scanf("%s", diaSemana);

    char *contemHifem = strchr(placaCarro, '-');
    int ultimoDigitoPlaca = placaCarro[strlen(placaCarro) - 2] - '0', qtdLetras = 0, qtdNumeros = 0;
    //Conta a qtd de letras e numeros da Placa
    for (int i = 0; i < strlen(placaCarro); ++i) {
        if(isalpha(placaCarro[i])){
            qtdLetras++;
        } if(isdigit(placaCarro[i])){
            qtdNumeros++;
        }
    }

    //Valida a placa
    if(contemHifem != NULL){ //placa antiga
        if(qtdLetras == 3 && qtdNumeros == 4){
            placaEhValida = 1;
        }
    } else{ // placa nova
        if(qtdLetras == 4 && qtdNumeros == 3){
            placaEhValida = 1;
        }
    }

    //Validação da semana
    for (int i = 0; i < sizeof(diasDaSemana) / sizeof(diasDaSemana[0]); i++) {
        if (strstr(diaSemana, diasDaSemana[i]) != NULL) {
            diaEhValido = 1;
        }
    }

    if(diaEhValido == 0 || placaEhValida == 0){
        if(placaEhValida == 0){
            printf("Placa invalida\n");
        }
        if(diaEhValido == 0){
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    switch (ultimoDigitoPlaca) {
        case 0:
        case 1:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[1]);
            break;
        case 2:
        case 3:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[2]);
            break;
        case 4:
        case 5:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[3]);
            break;
        case 6:
        case 7:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[4]);
            break;
        case 8:
        case 9:
            strcpy(diaSemanaNaoPermitido, diasDaSemana[5]);
            break;
    }

    if (strcmp(diaSemana, diasDaSemana[0]) == 0 || strcmp(diaSemana, diasDaSemana[6]) == 0){
        printf("Nao ha proibicao no fim de semana\n");
    } else if(strcmp(diaSemana, diaSemanaNaoPermitido) != 0){
        toLowerCase(diaSemana);
        printf("%s pode circular %s\n", placaCarro, diaSemana);
    } else{
        toLowerCase(diaSemana);
        printf("%s nao pode circular %s\n", placaCarro, diaSemana);

    }
    return 0;
}