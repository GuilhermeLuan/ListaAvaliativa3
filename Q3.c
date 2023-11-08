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
    char placaCarro[9] = "XX-1111";
    char diaSemana[14] = "TERCA-FEIRA";
    char diaSemanaNaoPermitido[14];
    char *diasDaSemana[] = {
            "DOMINGO", "SEGUNDA-FEIRA", "TERÇA-FEIRA",
            "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO"
    };
    char *contemHifem = strchr(placaCarro, '-');
    int ultimoDigitoPlaca = placaCarro[strlen(placaCarro) - 1] - '0', qtdLetras = 0, qtdNumeros = 0;
    int placaEhValida, diaEhValido;



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
        if(qtdLetras != 3 || qtdNumeros != 4){
            printf("Placa invalida\n");
        }
    } else{ // placa nova
        if(qtdLetras != 4 || qtdNumeros != 3){
            printf("Placa invalida\n");
        }
    }

    for (int i = 0; i < 6; i++) {
        if (strstr(diaSemana, diasDaSemana[i]) != NULL) {
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
            break;}
        } else if (strstr(diaSemana, diasDaSemana[i]) != NULL){
            printf("Dia da semana invalido\n");
            return 0;
        }
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